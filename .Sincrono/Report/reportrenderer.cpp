#include "reportrenderer.h"
#include "paper.h"
#include <QTime>
#include "section.h"
#include <QDebug>

ReportRenderer::ReportRenderer(QObject *parent) :
    QObject(parent)
{
}

QDomDocument ReportRenderer::render(QPrinter* printer ,QDomDocument in ,QMap<QString,QString> queryClausules, QMap<QString,QString> params, bool& error, bool isPrev)
{
    QPainter p;
    m_doc = preRender(&p,in,queryClausules,params,error,isPrev);
    for(int i=0;i<2;i++)
    {
        QDomNode root = m_doc.firstChild();
        QDomNode page = root.firstChild();
        while(!page.isNull())
        {
            if(!page.hasChildNodes())
            {
                QDomNode _aux = page;
                page = page.nextSiblingElement("Page");
                root.removeChild(_aux);
            }
            else
            {
                QDomNode section = page.firstChild();
                while(!section.isNull())
                {
                    if(!section.hasChildNodes())
                    {
                        QDomNode _aux = section;
                        section = section.nextSibling();
                        page.removeChild(_aux);
                    }
                    else
                        section = section.nextSibling();
                }
                page = page.nextSiblingElement("Page");
            }
        }
    }
    m_doc.firstChild().toElement().setAttribute("pages", m_doc.firstChild().childNodes().size());
    QFile f("/usr/share/RecoverDrake/pre.xml");
    if(f.open(QFile::WriteOnly))
    {
        QTextStream out(&f);
        const int Indent = 4;
        m_doc.save(out,Indent);
    }
    f.close();
    return m_doc;
}

void ReportRenderer::drawElement(qreal dpix, QPainter* painter, QDomElement element, int printResolution, qreal dpiy)
{
    if(element.attribute("id")== "RoundRect")
        drawRect(element, painter,dpix,dpiy,printResolution);
    else if(element.attribute("id")== "Label")
        drawLabel(element, painter,dpix,dpiy);
    else if(element.attribute("id")== "Line")
        drawLine(element, painter,dpix,dpiy,printResolution);
    else if(element.attribute("id")== "CodeBar")
        drawCodeBar(element, painter,dpix,dpiy);
    else if(element.attribute("id")== "Image")
        drawImage(element, painter,dpix,dpiy);
}

void ReportRenderer::Print(QPrinter *printer)
{
    QDomElement ele = m_doc.documentElement();
    QSize margins(printer->paperRect().left() - printer->pageRect().left(), printer->paperRect().top() - printer->pageRect().top());
    QPainter painter(printer);
    qreal dpix = printer->logicalDpiX() / 96.0;
    qreal dpiy = printer->logicalDpiY() / 96.0;
    int printResolution = printer->resolution();
    painter.translate(margins.width(),margins.height());
    double mx = ele.attribute("mx").toDouble();
    double my = ele.attribute("my").toDouble();
    double usable = ele.attribute("usable").toDouble();
    double width = Paper::cmToPx(ele.attribute("w").toDouble()) - ele.attribute("mr").toDouble() - mx;
    painter.translate( mx * dpix , my * dpiy);
    QDomNodeList pages = ele.childNodes();
    for(int i=0;i<pages.size();i++)
    {
        painter.save();
        QDomNodeList sections = pages.at(i).childNodes();
        for(int s = 0;s<sections.size();s++)
        {
            QDomElement cSec = sections.at(s).toElement();
            int id = cSec.attribute("id").toDouble();
            if(id < 2)
            {
                QDomNodeList elements = cSec.childNodes();
                for(int e = 0;e<elements.size();e++)
                {
                    QDomElement element = elements.at(e).toElement();
                    drawElement(dpix, &painter, element, printResolution, dpiy);
                }
                int siz = cSec.attribute("size").toDouble();
                painter.translate(0,siz* dpiy);
            }
            else if(id == 2)
            {
                QDomNodeList parts = cSec.childNodes();
                for(int p=0;p<parts.size();p++)
                {
                    QDomElement cPart = parts.at(p).toElement();
                    if(cPart.attribute("colored").toDouble())
                    {
                        painter.save();
                        painter.setPen(Qt::NoPen);
                        painter.setBrush(ColorFromString(cPart.attribute("color")));
                        painter.drawRect(0,0,width * dpix ,cPart.attribute("size").toDouble() * dpiy);
                        painter.restore();
                    }
                    QDomNodeList elements = cPart.childNodes();
                    for(int e = 0;e<elements.size();e++)
                    {
                        QDomElement element = elements.at(e).toElement();
                        drawElement(dpix, &painter, element, printResolution, dpiy);
                    }
                    int siz = cPart.attribute("size").toDouble();
                    painter.translate(0,siz* dpiy);
                }
            }
            else
            {
                if(s==sections.size()-1)
                {
                    int siz = cSec.attribute("size").toDouble();
                    painter.save();
                    painter.resetTransform();
                    painter.translate(margins.width(),margins.height());
                    painter.translate( mx * dpix , my * dpiy);
                    int offset = usable - siz;
                    painter.translate( 0, offset * dpiy);
                    QDomNodeList elements = cSec.childNodes();
                    for(int e = 0;e<elements.size();e++)
                    {
                        QDomElement element = elements.at(e).toElement();
                        drawElement(dpix, &painter, element, printResolution, dpiy);
                    }
                    painter.restore();
                }
                else
                {
                    int siz = cSec.attribute("size").toDouble();
                    int sizNext = sections.at(s+1).toElement().attribute("size").toDouble();
                    painter.save();
                    painter.resetTransform();
                    painter.translate(margins.width(),margins.height());
                    painter.translate( mx * dpix , my * dpiy);
                    int offset = usable - siz - sizNext;
                    painter.translate( 0, offset * dpiy);
                    QDomNodeList elements = cSec.childNodes();
                    for(int e = 0;e<elements.size();e++)
                    {
                        QDomElement element = elements.at(e).toElement();
                        drawElement(dpix, &painter, element, printResolution, dpiy);
                    }
                    painter.restore();
                    painter.translate(0,siz* dpiy);
                }
            }
        }
        painter.restore();
        if(i!=pages.size()-1)
            printer->newPage();
    }
}

void ReportRenderer::PreRender()
{
    bool error;
    _params[":fecha"] = "Fecha: " + QDate::currentDate().toString("dd-MM-yyyy");
    _params[":hora"] = "Hora: " +QDateTime::currentDateTime().toString("hh:mm:ss");    
    render( printer ,DocIn , queryClausules, _params, error, _limit);
    emit end();
}

QDomDocument ReportRenderer::preRender(QPainter* painter ,QDomDocument in,QMap<QString,QString> queryClausules, QMap<QString,QString> params, bool &error, bool isPrev)
{    
    QTime t;
    t.start();
    QDomElement Inroot = in.documentElement();
    if (Inroot.tagName() != "RDReports")
    {
        error = true;
        return QDomDocument();
    }
    QDomDocument doc;
    QDomElement root = doc.createElement("Document");
    doc.appendChild(root);
    bool haveRHeader = false;
    bool havePHeader = false;
    bool PHeaderOnAll = false;
    bool PFooterOnAll = false;
    bool havePFooter = false;
    bool haveRFooter = false;
    int RHeaderSiz = 0;
    int PHeaderSiz = 0;
    int PFooterSiz = 0;
    int RFooterSiz = 0;
    QDomNode RHeaderElement;
    QDomNode PHeaderElement;
    QDomNode PFootElement;
    QDomNode RFootElement;
    QList<QDomNode> SectionNodes;
    QStringList querys;
    double usable = 0;
    QDomNode child = Inroot.firstChild();
    QDomElement _aux = child.toElement();
    QMap<QString,float> _paper_acums;
    QStringList acums = _aux.attribute("acum").split(",");
    foreach (QString s, acums)
    {
        _paper_acums[s] = 0.0;
    }
    while (!child.isNull())
    {
        QDomNode sections = child.firstChild();
        while (!sections.isNull())
        {
            QDomElement secEle = sections.toElement();
            if(secEle.tagName() == "Size")
            {
                usable =  Paper::cmToPx(secEle.attribute("h").toDouble());
                root.setAttribute("h",secEle.attribute("h"));
                root.setAttribute("w",secEle.attribute("w"));
            }
            else if(secEle.tagName() == "Margin")
            {
                usable -= Paper::cmToPx(secEle.attribute("top").toDouble());
                usable -= Paper::cmToPx(secEle.attribute("bottom").toDouble());
                root.setAttribute("my",QString::number(Paper::cmToPx(secEle.attribute("top").toDouble()), 'f', 2));
                root.setAttribute("mx",QString::number(Paper::cmToPx(secEle.attribute("left").toDouble()), 'f', 2));
                root.setAttribute("usable",QString::number(usable, 'f', 2));
                root.setAttribute("mr",QString::number(Paper::cmToPx(secEle.attribute("left").toDouble()), 'f', 2));
            }
            else if(secEle.tagName() == "Section")
            {
                Section::SectionType t = static_cast<Section::SectionType>(secEle.attribute("id").toDouble());
                switch (t) {
                case Section::ReportHeader:
                    haveRHeader = true;
                    RHeaderSiz = secEle.attribute("size").toDouble();
                    RHeaderElement = sections.cloneNode(true);
                    break;
                case Section::PageHeader:
                    havePHeader = true;
                    PHeaderSiz = secEle.attribute("size").toDouble();
                    PHeaderOnAll = secEle.attribute("OnFistPage").toDouble();
                    PHeaderElement = sections.cloneNode(true);
                    break;
                case Section::Detail:
                    SectionNodes.append(sections.cloneNode(true));
                    break;
                case Section::PageFooter:
                    havePFooter = true;
                    PFooterSiz = secEle.attribute("size").toDouble();
                    PFooterOnAll= secEle.attribute("OnFistPage").toDouble();
                    PFootElement = sections.cloneNode(true);
                    break;
                case Section::ReportFooter:
                    haveRFooter = true;
                    RFooterSiz = secEle.attribute("size").toDouble();
                    RFootElement = sections.cloneNode(true);
                    break;
                }
            }
            else if(secEle.tagName() == "SQL")
            {
                querys << secEle.attribute("target");
            }
            sections = sections.nextSibling();
        }
        child = child.nextSibling();
    }
    QList<QPair<QString,QString> > finalQuerys;
    QStringListIterator it(querys);
    while (it.hasNext()) {
        QPair<QString,QString> aux = getSql(it.next(),queryClausules,isPrev);
        if(!aux.first.isEmpty())
            finalQuerys.append(aux);
    }
    QListIterator<QPair<QString,QString> > qIt(finalQuerys);
    QMap<QString,QSqlRecord> selects;
    while(qIt.hasNext())
    {
        QPair<QString,QString> pair = qIt.next();
        QSqlDatabase db;
        db = QSqlDatabase::database("PRINCIPAL");
        QSqlQuery q(db);
        if(q.exec(pair.second))
            if(q.next())
                selects.insert(pair.first,q.record());
    }
    QListIterator<QDomNode> sectionIt(SectionNodes);
    QList<QDomNode> parsedSections;
    while(sectionIt.hasNext())
    {
        QDomNode n = sectionIt.next();
        QDomElement ele = n.toElement();
        QDomNodeList l = ele.childNodes();
        for(int i=0 ; i< l.size(); i++)
        {
            QDomElement _e = l.at(i).toElement();
            if(_e.attribute("id")== "Param")
            {
                QString value = params.value(_e.attribute("Arg"));
                _e.setAttribute("id","Label");
                _e.setAttribute("Text",value);
            }
        }
        bool iSql = ele.attribute("haveSqlInterno").toDouble();
        QString cla = ele.attribute("ClausulaInterna");
        QStringList lCla = cla.split("=");
        QString columna = "";
        QString bindKey = "";
        QString clausulaInterna = "";
        if(lCla.size()==2)
        {
            columna = lCla.at(1);
            clausulaInterna = QString("%1=:%2").arg(lCla.at(0)).arg(lCla.at(1));
            bindKey = QString(":%1").arg(lCla.at(1));
        }
        QPair<QString,QString> gSql = getSql(ele.attribute("SqlGlobal"),queryClausules,isPrev);
        QString first = gSql.first;
        QSqlDatabase db;
        db = QSqlDatabase::database("PRINCIPAL");
        QSqlQuery gQuery(db);
        if(gQuery.exec(gSql.second))
        {
            while(gQuery.next())
            {
                QStringList i_acums_list = ele.attribute("acum").split(",");
                QMap<QString,float> _i_acums;
                foreach (QString _a, i_acums_list)
                {
                    _i_acums[_a]=0.0;
                }
                QSqlRecord record = gQuery.record();
                QDomNode exit = doc.createElement("section");
                bool appenExit = true;
                QDomNode copy = n.cloneNode(true);
                QDomNode sectionPart = copy.firstChild();
                while(!sectionPart.isNull())
                {
                    QDomNode next = sectionPart.nextSibling();
                    QDomElement secEle = sectionPart.toElement();
                    if(secEle.tagName() == "Header")
                    {
                        QDomNode child = sectionPart.firstChild();
                        while(!child.isNull())
                        {
                            QDomElement ele = child.toElement();
                            if(ele.attribute("id")=="Field")
                            {
                                ele.setAttribute("id","Label");
                                QString text = "";
                                int formato = ele.attribute("formato").toDouble();
                                QStringList value = ele.attribute("Sql").split(".");
                                if(value.size()== 3)
                                        text = applyFormato(record.value(value.at(2)).toString(),formato);                                
                                ele.setAttribute("Text",text);
                            }
                            else if(ele.attribute("id")=="RelationalField")
                            {
                                ele.setAttribute("id","Label");
                                QString text = "";
                                int formato = ele.attribute("formato").toDouble();
                                QStringList value = ele.attribute("value").split(".");
                                if(value.size()>1)
                                {
                                    QString key = value.at(0) + "." + value.at(1);
                                    text = applyFormato(getRelationField(ele.attribute("Sql"),selects.value(key)),formato);
                                }
                                ele.setAttribute("Text",text);
                            }
                            else if(ele.attribute("id")=="CodeBar")
                            {
                                QString text = "";
                                QStringList value = ele.attribute("Sql").split(".");
                                if(value.size()== 3)
                                    text = record.value(value.at(2)).toString();
                                ele.setAttribute("Code",text);
                            }
                            else if(ele.attribute("id")=="Image")
                            {
                                QByteArray b;
                                QStringList value = ele.attribute("Path").split(".");
                                if(value.size()== 3)
                                    b = record.value(value.at(2)).toByteArray();
                                ele.setAttribute("img-data",QString(b));
                            }
                            child = child.nextSibling();
                        }
                        exit.appendChild(sectionPart);
                    }
                    else if (secEle.tagName() == "Body")
                    {
                        if(iSql)
                        {
                            QString c1 = ele.attribute("color1");
                            QString c2 = ele.attribute("color2");
                            bool colored = ele.attribute("colored").toDouble();
                            bool altern = ele.attribute("alternative").toDouble();
                            bool toogle = true;
                            QString iSql = ele.attribute("SqlInterno");
                            QSqlDatabase db;
                            db = QSqlDatabase::database("PRINCIPAL");
                            QString query = QString("SELECT * FROM %1 WHERE %2").arg(iSql.split(".").at(1)).arg(clausulaInterna);
                            QSqlQuery iQuery(db);
                            iQuery.prepare(query);
                            iQuery.bindValue(bindKey,record.value(columna));
                            if(iQuery.exec())
                            {
                                if(iQuery.next())
                                {
                                    do
                                    {                                        
                                        QSqlRecord iRecord = iQuery.record();
                                        QDomNode iCopy = sectionPart.cloneNode(true);
                                        QDomElement iCopyEle = iCopy.toElement();
                                        iCopyEle.setAttribute("colored",colored);
                                        if(toogle)
                                        {
                                             iCopyEle.setAttribute("color",c1);
                                             if(altern)
                                                 toogle = false;
                                        }
                                        else
                                        {
                                             iCopyEle.setAttribute("color",c2);
                                             toogle = true;
                                        }
                                        QDomNode child = iCopy.firstChild();
                                        while(!child.isNull())
                                        {
                                            QDomElement ele = child.toElement();
                                            if(ele.attribute("id")=="Field")
                                            {
                                                ele.setAttribute("id","Label");
                                                QString text = "";
                                                int formato = ele.attribute("formato").toDouble();
                                                QStringList value = ele.attribute("Sql").split(".");
                                                if(value.size()== 3)
                                                        text = applyFormato(iRecord.value(value.at(2)).toString(),formato);
                                                ele.setAttribute("Text",text);
                                                if(ele.attribute("Expandable") == "1")
                                                {
                                                    double h = ele.attribute("h").toDouble();
                                                    double siz = iCopy.toElement().attribute("size").toDouble();
                                                    QRectF r(0,0,ele.attribute("w").toDouble(),h);
                                                    QRectF r2(painter->fontMetrics().boundingRect(r.toRect(),Qt::TextWordWrap,text));
                                                    double diff = r2.height() - h;
                                                    iCopy.toElement().setAttribute("size",siz+diff+10);
                                                    ele.setAttribute("h",r2.height()+10);
                                                }
                                                if(_i_acums.contains(ele.attribute("name")))
                                                    _i_acums[ele.attribute("name")]+= iRecord.value(value.at(2)).toDouble();
                                            }
                                            else if(ele.attribute("id")=="RelationalField")
                                            {
                                                ele.setAttribute("id","Label");
                                                QString text = "";
                                                int formato = ele.attribute("formato").toDouble();
                                                text = applyFormato(getRelationField(ele.attribute("Sql"),record),formato);
                                                ele.setAttribute("Text",text);
                                            }
                                            else if(ele.attribute("id")=="CodeBar")
                                            {
                                                QString text = "";
                                                QStringList value = ele.attribute("Sql").split(".");
                                                 if(value.size()== 3)
                                                    text = record.value(value.at(2)).toString();                                                 
                                                ele.setAttribute("value",text);
                                            }
                                            else if(ele.attribute("id")=="Image")
                                            {
                                                QByteArray b;
                                                QStringList value = ele.attribute("Path").split(".");
                                                if(value.size()== 3)
                                                    b = record.value(value.at(2)).toByteArray();
                                               ele.setAttribute("img-data",QString(b));
                                            }
                                            child = child.nextSibling();
                                        }
                                        exit.appendChild(iCopy);
                                    }while(iQuery.next());
                                }
                                else
                                {
                                    appenExit = false;
                                }
                            }
                        }
                        else
                        {
                            QDomNode child = sectionPart.firstChild();
                            while(!child.isNull())
                            {
                                QDomElement ele = child.toElement();
                                if(ele.attribute("id")=="Field")
                                {
                                    ele.setAttribute("id","Label");
                                    QString text = "";
                                    int formato = ele.attribute("formato").toDouble();
                                    QStringList value = ele.attribute("Sql").split(".");
                                    if(value.size()== 3)
                                        text = applyFormato(record.value(value.at(2)).toString(),formato);
                                    ele.setAttribute("Text",text);
                                    if(ele.attribute("Expandable") == "1")
                                    {
                                        double h = ele.attribute("h").toDouble();
                                        double siz = sectionPart.toElement().attribute("size").toDouble();
                                        QRectF r(0,0,ele.attribute("w").toDouble()-10,h);
                                        QRectF r2(painter->fontMetrics().boundingRect(r.toRect(),Qt::TextWordWrap,text));
                                        double diff = r2.height() - h;
                                        sectionPart.toElement().setAttribute("size",siz+diff+painter->fontMetrics().height());
                                        ele.setAttribute("h",r2.height()+painter->fontMetrics().height());
                                    }
                                }
                                else if(ele.attribute("id")=="RelationalField")
                                {
                                    ele.setAttribute("id","Label");
                                    QString text = "";
                                    int formato = ele.attribute("formato").toDouble();
                                    text = applyFormato(getRelationField(ele.attribute("Sql"),record),formato);
                                    ele.setAttribute("Text",text);
                                }
                                else if(ele.attribute("id")=="CodeBar")
                                {
                                    QString text = "";
                                    QStringList value = ele.attribute("Sql").split(".");                                    
                                    if(value.size()== 3)
                                        text = record.value(value.at(2)).toString();                                    
                                    ele.setAttribute("Code",text);
                                }
                                else if(ele.attribute("id")=="Image")
                                {
                                    QByteArray b;
                                    QStringList value = ele.attribute("Path").split(".");
                                    if(value.size()== 3)
                                        b = record.value(value.at(2)).toByteArray();
                                   ele.setAttribute("img-data",QString(b));
                                }
                                child = child.nextSibling();
                            }
                            exit.appendChild(sectionPart);
                        }
                    }
                    else
                    {
                        QDomNode child = sectionPart.firstChild();
                        while(!child.isNull())
                        {
                            QDomElement ele = child.toElement();
                            if(ele.attribute("id")=="Field")
                            {
                                ele.setAttribute("id","Label");
                                QString text = "";
                                int formato = ele.attribute("formato").toDouble();
                                QStringList value = ele.attribute("Sql").split(".");
                                if(value.size()== 3)
                                        text = applyFormato(record.value(value.at(2)).toString(),formato);
                                ele.setAttribute("Text",text);
                            }
                            else if(ele.attribute("id")=="RelationalField")
                            {
                                ele.setAttribute("id","Label");
                                QString text = "";
                                int formato = ele.attribute("formato").toDouble();
                                text = applyFormato(getRelationField(ele.attribute("Sql"),record),formato);
                                ele.setAttribute("Text",text);
                            }
                            else if(ele.attribute("id")=="CodeBar")
                            {
                                QString text = "";
                                QStringList value = ele.attribute("Sql").split(".");
                                if(value.size()== 3)
                                    text = record.value(value.at(2)).toString();
                                ele.setAttribute("Code",text);
                            }
                            else if(ele.attribute("id")=="Image")
                            {
                                QByteArray b;
                                QStringList value = ele.attribute("Path").split(".");
                                if(value.size()== 3)
                                    b = record.value(value.at(2)).toByteArray();
                                ele.setAttribute("img-data",QString(b));
                            }
                            if(ele.attribute("id")=="Acumulador")
                            {
                                ele.setAttribute("id","Label");
                                QString text = "";
                                int formato = ele.attribute("formato").toDouble();
                                text = applyFormato(QString::number(_i_acums.value(ele.attribute("target")),'f',2),formato);
                                ele.setAttribute("Text",text);
                            }
                            child = child.nextSibling();
                        }
                        exit.appendChild(sectionPart);
                    }
                    sectionPart = next;
                }
                if(appenExit)
                    parsedSections.append(exit);
            }
        }
    }
    if(haveRHeader)
    {
       QDomNodeList l = RHeaderElement.childNodes();
       for(int i=0 ; i< l.size(); i++)
       {
           QDomElement _e = l.at(i).toElement();
           if(_e.attribute("id")== "Param")
           {
               QString value = params.value(_e.attribute("Arg"));
               _e.setAttribute("id","Label");
               _e.setAttribute("Text",value);
           }
       }
    }
    if(havePHeader)
    {
        QDomNodeList l = PHeaderElement.childNodes();
        for(int i=0 ; i< l.size(); i++)
        {
            QDomElement _e = l.at(i).toElement();
            if(_e.attribute("id")== "Param")
            {
                QString value = params.value(_e.attribute("Arg"));
                _e.setAttribute("id","Label");
                _e.setAttribute("Text",value);
            }
        }
    }
    if(havePFooter)
    {
        QDomNodeList l = PFootElement.childNodes();
        for(int i=0 ; i< l.size(); i++)
        {
            QDomElement _e = l.at(i).toElement();
            if(_e.attribute("id")== "Param")
            {
                QString value = params.value(_e.attribute("Arg"));
                _e.setAttribute("id","Label");
                _e.setAttribute("Text",value);
            }
        }
    }
    if(haveRFooter)
    {
        QDomNodeList l = RFootElement.childNodes();
        for(int i=0 ; i< l.size(); i++)
        {
            QDomElement _e = l.at(i).toElement();
            if(_e.attribute("id")== "Param")
            {
                QString value = params.value(_e.attribute("Arg"));
                _e.setAttribute("id","Label");
                _e.setAttribute("Text",value);
            }
        }
    }
    QDomNode pageNode = startPage(usable,PFooterSiz, RHeaderSiz ,RFooterSiz,doc,havePHeader&&PHeaderOnAll,PHeaderElement,selects,haveRHeader,RHeaderElement);
    parseFooters(RFootElement , haveRFooter , PFootElement , havePFooter , selects);
    root.appendChild(pageNode);
    int ipageCount = 1;
    int pageUsable = usable;
    if(havePHeader&&PHeaderOnAll)
        pageUsable -= PHeaderSiz;
    if(haveRHeader)
        pageUsable -= RHeaderSiz;
    QListIterator<QDomNode> parsedIt(parsedSections);
    while(parsedIt.hasNext())
    {
        QDomNode sec = doc.createElement("Section");
        sec.toElement().setAttribute("id",2);
        pageNode.appendChild(sec);
        QDomNode n = parsedIt.next();
        QDomNode child = n.firstChild();
        QDomNode lastChild = n.lastChild();
        QDomNode sectionHeader;
        QDomNode sectionFoot;
        bool haveHead = false;
        bool haveFoot = false;
        int headSiz = 0;
        int footSiz = 0;
        if(child.toElement().tagName() == "Header")
        {
            haveHead = true;
            sectionHeader = child;
            headSiz = child.toElement().attribute("size").toDouble();
            sec.appendChild(sectionHeader.cloneNode(true));
            pageUsable -= headSiz;
        }
        if(lastChild.toElement().tagName() == "Foot")
        {
            haveFoot = true;
            footSiz = lastChild.toElement().attribute("size").toDouble();
            sectionFoot = lastChild;
        }
        QList<QDomNode> bodys;
        QDomNodeList l = n.childNodes();
        for(int i = 0;i< l.size(); i++)
        {
            if(haveFoot && i == l.size()-1)
                continue;
            bodys.append(l.at(i));
        }
        QListIterator<QDomNode> bodyIt(bodys);
        while (bodyIt.hasNext())
        {
            QDomNode body = bodyIt.next();
            QDomElement bEle = body.toElement();
            if(bEle.tagName() == "Body")
            {
                if(parsedIt.hasNext())
                {
                    if(pageUsable > bEle.attribute("size").toDouble() + footSiz + PFooterSiz)
                    {
                        pageUsable -= bEle.attribute("size").toDouble();
                        sec.appendChild(body);
                        QDomNode child = body.firstChild();
                        while(!child.isNull())
                        {
                            QDomElement ele = child.toElement();

                            if(_paper_acums.contains(ele.attribute("name")))
                            {
                                QString sValue = ele.attribute("Text");
                                _paper_acums[ele.attribute("name")] += getNumber(sValue,ele.attribute("formato").toInt());
                            }

                            child = child.nextSibling();
                        }
                        if(!bodyIt.hasNext())
                        {
                            if(haveFoot)
                            {
                                sec.appendChild(sectionFoot);
                                pageUsable -= footSiz;
                            }
                        }
                    }
                    else
                    {
                        if(havePFooter)
                            endPage(pageNode,PFootElement.cloneNode(true),_paper_acums);
                        pageNode = startPage(usable,PFooterSiz, RHeaderSiz,RFooterSiz,doc,havePHeader,PHeaderElement,selects);
                        ipageCount++;
                        root.appendChild(pageNode);
                        pageUsable = usable;
                        if(havePHeader)
                            pageUsable -= PHeaderSiz;
                        sec = doc.createElement("Section");
                        sec.toElement().setAttribute("id",2);
                        pageNode.appendChild(sec);
                        if(haveHead)
                        {
                            sec.appendChild(sectionHeader.cloneNode(true));
                            pageUsable -= headSiz;
                        }
                        pageUsable -= bEle.attribute("size").toDouble();
                        sec.appendChild(body);
                        QDomNode child = body.firstChild();
                        while(!child.isNull())
                        {
                            QDomElement ele = child.toElement();

                            if(_paper_acums.contains(ele.attribute("name")))
                            {
                                QString sValue = ele.attribute("Text");
                                _paper_acums[ele.attribute("name")] += getNumber(sValue,ele.attribute("formato").toInt());
                            }

                            child = child.nextSibling();
                        }
                        if(!bodyIt.hasNext())
                        {
                            if(haveFoot)
                            {
                                sec.appendChild(sectionFoot);
                                pageUsable -= footSiz;
                            }
                        }
                    }
                }
                else
                {
                    if(bodyIt.hasNext())
                    {
                        if(pageUsable > bEle.attribute("size").toDouble() + footSiz + PFooterSiz)
                        {
                            pageUsable -= bEle.attribute("size").toDouble();
                            sec.appendChild(body);
                            QDomNode child = body.firstChild();
                            while(!child.isNull())
                            {
                                QDomElement ele = child.toElement();

                                if(_paper_acums.contains(ele.attribute("name")))
                                {
                                    QString sValue = ele.attribute("Text");
                                    _paper_acums[ele.attribute("name")] += getNumber(sValue,ele.attribute("formato").toInt());
                                }
                                child = child.nextSibling();
                            }
                        }
                        else
                        {
                            if(havePFooter)
                                endPage(pageNode,PFootElement.cloneNode(true),_paper_acums);
                            pageNode = startPage(usable,PFooterSiz, RHeaderSiz,RFooterSiz,doc,havePHeader,PHeaderElement,selects);
                            ipageCount++;
                            root.appendChild(pageNode);
                            pageUsable = usable;

                            if(havePHeader)
                                pageUsable -= PHeaderSiz;

                            sec = doc.createElement("Section");
                            sec.toElement().setAttribute("id",2);
                            pageNode.appendChild(sec);
                            if(haveHead)
                            {
                                sec.appendChild(sectionHeader.cloneNode(true));
                                pageUsable -= headSiz;
                            }
                            pageUsable -= bEle.attribute("size").toDouble();
                            sec.appendChild(body);
                            QDomNode child = body.firstChild();
                            while(!child.isNull())
                            {
                                QDomElement ele = child.toElement();

                                if(_paper_acums.contains(ele.attribute("name")))
                                {
                                    QString sValue = ele.attribute("Text");
                                    _paper_acums[ele.attribute("name")] += getNumber(sValue,ele.attribute("formato").toInt());
                                }
                                child = child.nextSibling();
                            }
                        }
                    }
                    else
                    {
                        int needed = bEle.attribute("size").toDouble() + footSiz + RFooterSiz;
                        if(PFooterOnAll)
                            needed += PFooterSiz;
                        if(pageUsable > needed)
                        {
                            pageUsable -= bEle.attribute("size").toDouble();
                            sec.appendChild(body);
                            QDomNode child = body.firstChild();
                            while(!child.isNull())
                            {
                                QDomElement ele = child.toElement();

                                if(_paper_acums.contains(ele.attribute("name")))
                                {
                                    QString sValue = ele.attribute("Text");
                                    _paper_acums[ele.attribute("name")] += getNumber(sValue,ele.attribute("formato").toInt());
                                }

                                child = child.nextSibling();
                            }
                            if(!bodyIt.hasNext())//last body of section & report
                            {
                                if(haveFoot)
                                {
                                    sec.appendChild(sectionFoot);
                                    pageUsable -= footSiz;
                                }
                            }
                            if(!bodyIt.hasNext())
                            {
                                if(haveFoot)
                                {
                                    sec.appendChild(sectionFoot);
                                    pageUsable -= footSiz;
                                }
                            }
                        }
                        else
                        {
                            if(havePFooter)
                                endPage(pageNode,PFootElement.cloneNode(true),_paper_acums);
                            pageNode = startPage(usable,PFooterSiz, RHeaderSiz,RFooterSiz,doc,havePHeader,PHeaderElement,selects);
                            ipageCount++;
                            root.appendChild(pageNode);
                            pageUsable = usable;

                            if(havePHeader)
                                pageUsable -= PHeaderSiz;
                            sec = doc.createElement("Section");
                            sec.toElement().setAttribute("id",2);
                            pageNode.appendChild(sec);
                            if(haveHead)
                            {
                                sec.appendChild(sectionHeader.cloneNode(true));
                                pageUsable -= headSiz;
                            }
                            pageUsable -= bEle.attribute("size").toDouble();
                            sec.appendChild(body);
                            QDomNode child = body.firstChild();
                            while(!child.isNull())
                            {
                                QDomElement ele = child.toElement();

                                if(_paper_acums.contains(ele.attribute("name")))
                                {
                                    QString sValue = ele.attribute("Text");
                                    _paper_acums[ele.attribute("name")] += getNumber(sValue,ele.attribute("formato").toInt());
                                }

                                child = child.nextSibling();
                            }
                            if(!bodyIt.hasNext())
                            {
                                if(haveFoot)
                                {
                                    sec.appendChild(sectionFoot);
                                    pageUsable -= footSiz;
                                }                               
                            }
                        }
                    }
                }
            }
        }
    }
    if(havePFooter && PFooterOnAll)
        endPage(pageNode,PFootElement.cloneNode(true),_paper_acums);
    if(haveRFooter)
    {
        pageNode.appendChild(RFootElement);
        QDomNode sec = pageNode.firstChild();
        for(int i= 0; i<2; i++)
        {
            if(sec.toElement().attribute("id").toDouble() == 0 || sec.toElement().attribute("id").toDouble() == 1)
            {
                QDomNode ele = sec.firstChild();
                while(!ele.isNull())
                {
                    if(ele.toElement().attribute("id") == "Line")
                        if(ele.toElement().attribute("endPointName")!= "Self")
                            if(ele.toElement().attribute("endPointName")!= "Pie de report")
                                ele.toElement().setAttribute("h",ele.toElement().attribute("h").toDouble()-RFooterSiz);
                    if(ele.toElement().attribute("id") == "RoundRect")
                        if(ele.toElement().attribute("endPointName")!= "Self")
                            if(ele.toElement().attribute("endPointName")!= "Pie de report")
                                ele.toElement().setAttribute("h",ele.toElement().attribute("h").toDouble()-RFooterSiz);
                    ele = ele.nextSibling();
                }
            }
            sec = sec.nextSibling();
        }
        QDomNode child = RFootElement.firstChild();
        while(!child.isNull())
        {
            QDomElement ele = child.toElement();
            if(ele.attribute("id")=="Acumulador")
            {
                ele.setAttribute("id","Label");
                QString text = "";
                int formato = ele.attribute("formato").toDouble();
                text = applyFormato(QString::number(_paper_acums.value(ele.attribute("target")),'f',2),formato);
                ele.setAttribute("Text",text);
            }
            child = child.nextSibling();
        }
    }
    root.setAttribute("pages",ipageCount);
    return doc;
}

bool ReportRenderer::limit() const
{
    return _limit;
}

void ReportRenderer::setLimit(bool limit)
{
    _limit = limit;
}

QMap<QString, QString> ReportRenderer::params() const
{
    return _params;
}

void ReportRenderer::setParams(const QMap<QString, QString> &params)
{
    _params = params;
}

void ReportRenderer::drawRect(QDomElement e, QPainter *painter, double dpiX, double dpiY, int printResolution)
{
    painter->save();
    QPointF pos;
    pos.setX(e.attribute("x").toDouble() * dpiX);
    pos.setY(e.attribute("y").toDouble() * dpiY);
    QSize siz;
    siz.setWidth(e.attribute("w").toDouble()* dpiX);
    siz.setHeight(e.attribute("h").toDouble()* dpiY);
    QColor penColor = ColorFromString(e.attribute("PenColor"));
    int penW = e.attribute("PenWidth").toDouble();
    QColor color1 , color2;
    color1 = ColorFromString(e.attribute("Color1"));
    color2 = ColorFromString(e.attribute("Color2"));
    double r1, r2;
    r1 = e.attribute("RadiousX").toDouble();
    r2 = e.attribute("RadiousY").toDouble();
    bool vGrad , gUsed;
    gUsed = e.attribute("GradientUsed").toDouble();
    vGrad = e.attribute("GradientDirection") == "V";
    painter->setRenderHints(QPainter::Antialiasing);
    QPen pen(painter->pen());
    pen.setWidthF((penW / 100) * printResolution);
    pen.setColor(penColor);
    painter->setPen(pen);
    painter->translate(pos);
    QRectF r(QPointF(0,0),siz);
    if(gUsed)
    {
        if(vGrad)
        {
            QLinearGradient Gradient(r.width()/2,0,r.width()/2,r.height());
            Gradient.setColorAt(0,color1);
            Gradient.setColorAt(1,color2);
            painter->setBrush(QBrush(Gradient));
        }
        else
        {
            QLinearGradient Gradient(0,r.height()/2,r.width(),r.height()/2);
            Gradient.setColorAt(0,color1);
            Gradient.setColorAt(1,color2);
            painter->setBrush(QBrush(Gradient));
        }
    }
    else
    {
        painter->setBrush(QBrush(color1));
    }
    QRectF rr(penW/2.0,
             penW/2.0,
             r.width()- penW,
             r.height()- penW);
    painter->drawRoundedRect(rr,r1,r2);
    painter->restore();
}

void ReportRenderer::drawLabel(QDomElement e, QPainter *painter, double dpiX, double dpiY)
{
    QString m_Text = e.attribute("Text");
    _Orientacion m_Orientacion = e.attribute("Orientacion") == "V" ? Vertical : Horizontal;
    _Aling m_Alineacion =  e.attribute("Alineacion") == "L" ?  Left :
                           e.attribute("Alineacion") == "R" ?  Rigth:
                                                               Center;
    QString m_fontFamily = e.attribute("fontFamily");
    int m_fontSize = e.attribute("fontSize").toDouble();
    int m_fontWeigth = e.attribute("fontWeigth").toDouble();
    bool m_italicFont = e.attribute("italicFont").toDouble();
    QColor m_fontColor = ColorFromString(e.attribute("color"));
    bool m_underlined = e.attribute("underlined").toDouble();
    QPointF pos;
    pos.setX(e.attribute("x").toDouble() * dpiX);
    pos.setY(e.attribute("y").toDouble() * dpiY);
    QSize siz;
    siz.setWidth(e.attribute("w").toDouble()* dpiX +10);
    siz.setHeight(e.attribute("h").toDouble()* dpiY+10);
    painter->save();
    painter->translate(pos);
    QRectF r(QPointF(0,0),siz);
    QFont f(m_fontFamily,m_fontSize);
    f.setUnderline(m_underlined);
    f.setWeight(m_fontWeigth);
    f.setItalic(m_italicFont);
    painter->setPen(m_fontColor);
    painter->setFont(f);
    if(m_Orientacion == Vertical)
    {
        painter->translate(r.bottomLeft());
        painter->rotate(270);
        switch (m_Alineacion) {
        case Center:
            painter->drawText(r,Qt::TextWordWrap|Qt::AlignCenter,m_Text);
            break;
        case Rigth:
            painter->drawText(r,Qt::TextWordWrap|Qt::AlignRight,m_Text);
            break;
        default:
            painter->drawText(r,Qt::TextWordWrap|Qt::AlignLeft,m_Text);
            break;
        }
    }
    else
    {
        switch (m_Alineacion) {
        case Center:
            painter->drawText(r,Qt::TextWordWrap|Qt::AlignCenter,m_Text);
            break;
        case Rigth:
            painter->drawText(r,Qt::TextWordWrap|Qt::AlignRight,m_Text);
            break;
        default:
            painter->drawText(r,Qt::TextWordWrap|Qt::AlignLeft,m_Text);
            break;
        }
    }
    painter->restore();
}

void ReportRenderer::drawLine(QDomElement e, QPainter *painter, double dpiX, double dpiY, int printResolution)
{
    int  m_penWidth = e.attribute("penWidth").toDouble();
    QColor m_penColor = ColorFromString(e.attribute("penColor"));
    _Orientacion m_Orientacion = e.attribute("Orientacion") == "V" ? Vertical : Horizontal;
    Qt::PenStyle m_penStyle = static_cast<Qt::PenStyle>(e.attribute("penStyle").toDouble());
    QPointF pos;
    pos.setX(e.attribute("x").toDouble() * dpiX);
    pos.setY(e.attribute("y").toDouble() * dpiY);
    QSize siz;
    siz.setWidth(e.attribute("w").toDouble()* dpiX);
    siz.setHeight(e.attribute("h").toDouble()* dpiY);
    painter->save();
    painter->translate(pos);
    QRectF r(QPointF(0,0),siz);
    QPen pen;
    pen.setWidthF((m_penWidth / 100) * printResolution);
    pen.setStyle(m_penStyle);
    pen.setColor(m_penColor);
    painter->setPen(pen);
    if(m_Orientacion == Horizontal)
        painter->drawLine(0,r.height()/2,r.width(),r.height()/2);
    else
        painter->drawLine(r.width()/2,0,r.width()/2,r.height());
    painter->restore();
}

void ReportRenderer::drawImage(QDomElement e, QPainter *painter, double dpiX, double dpiY)
{
    QString m_ruta = e.attribute("Path");
    bool m_fromDB = e.attribute("fromBD").toDouble();
    QImage m_image;
    bool m_dinamica = e.attribute("Dinamic").toDouble();
    QPointF pos;
    pos.setX(e.attribute("x").toDouble() * dpiX);
    pos.setY(e.attribute("y").toDouble() * dpiY);
    QSize siz;
    siz.setWidth(e.attribute("w").toDouble()* dpiX +10);
    siz.setHeight(e.attribute("h").toDouble()* dpiY);
    if(m_fromDB)
    {
        //FALTA ESTA PARTE
    }
    else
    {
        QFile f(m_ruta);
        if(f.open(QFile::ReadOnly))
            m_image = QImage(m_ruta);
    }
    painter->save();
    painter->translate(pos);
    QRectF r(QPointF(0,0),siz);
    painter->drawImage(r,m_image);
    painter->restore();
}

void ReportRenderer::drawCodeBar(QDomElement e, QPainter *painter, double dpiX, double dpiY)
{
    QString m_code = e.attribute("Code");
    bool m_visibleCode = e.attribute("visibleCode").toDouble();
    QPointF pos;
    pos.setX(e.attribute("x").toDouble() * dpiX);
    pos.setY(e.attribute("y").toDouble() * dpiY);
    QSizeF siz;
    siz.setWidth(e.attribute("w").toDouble()* dpiX +10);
    siz.setHeight(e.attribute("h").toDouble()* dpiY+10);
    int codeSize = (e.attribute("codeSize").toInt());
    int barSize = (e.attribute("barSize").toInt());
    bool vertical = (e.attribute("vertical").toInt());
    painter->save();
    painter->translate(pos);
    QFont f1 = QFont(painter->font().family(),codeSize);
    QFont f("Free 3 of 9 Extended",barSize);
    painter->setFont(f);
    if(vertical)
    {
        QRectF _r(QPointF(0,0),siz);
        QRectF r(0,0,siz.height(),siz.width()+codeSize*dpiX);
        painter->translate(_r.bottomLeft());
        painter->rotate(270);
        painter->drawText(r,Qt::TextWordWrap|Qt::AlignCenter,m_code);
        if(m_visibleCode)
        {
            painter->setFont(f1);
            painter->drawText(r,Qt::AlignBottom|Qt::AlignCenter|Qt::TextJustificationForced,m_code);
        }
    }
    else
    {
        QRectF r(QPointF(0,0),siz);
        painter->drawText(r,Qt::AlignTop|Qt::AlignHCenter,m_code);
        if(m_visibleCode)
        {
            painter->setFont(f1);
            painter->drawText(r,Qt::AlignBottom|Qt::AlignCenter|Qt::TextJustificationForced,m_code);
        }
    }
    painter->restore();
}

QPair<QString,QString> ReportRenderer::getSql(QString s, QMap<QString, QString> queryClausules, bool prev)
{
    QStringList l = s.split(".");
    if(l.size()==2)
    {
        QString second = l.at(1);
        QString clausula = queryClausules.value(s);
        QString final;
        QTextStream t(&final);
        t << "SELECT * FROM " << second;
        if(!clausula.isEmpty())
            t << " WHERE " << clausula;
        if(prev)
            t << " limit 100";
        t<<";";
        QPair<QString,QString> p;
        p.first = s;
        p.second= final;
        return p;
    }
    else if(l.size()>2)
    {
        QStringList split = s.split("=");
        if(split.size()==2)
        {
            QStringList l2 = split.at(0).split(".");
            QString out = QString("%1.%2").arg(l2.at(0)).arg(l2.at(1));
            return getSql(out , queryClausules, prev);
        }
    }
    return QPair<QString,QString>(QString(),QString());
}

QString ReportRenderer::getRelationField(QString s , QSqlRecord r)
{
    QStringList split = s.split("=");
    if(split.size()==2)
    {
        QString value = r.value(split.at(0).split(".").at(2)).toString();
        QStringList to = split.at(1).split("->");
        QString key = to.at(0);
        QString final;
        QStringList l = key.split(".");
        if(l.size()==3)
        {
            QString second = l.at(1);
            QTextStream t(&final);
            t << "SELECT * FROM " << second;
            t << " WHERE " << l.at(2) << "=" << "'" << value << "'";
            t<<";";
        }
        QSqlDatabase db;
        db = QSqlDatabase::database("PRINCIPAL");
        QSqlQuery q(db);
        if(q.exec(final))
            if(q.next())
                return q.record().value(to.at(1)).toString();
    }
    return "";
}

QDomNode ReportRenderer::startPage(double pageUsable, int PFooterSiz, int RHSiz,int RFootSiz, QDomDocument doc, bool pageHeader, QDomNode pHeaderNode, QMap<QString, QSqlRecord> selects, bool reporHeader, QDomNode rHeaderNode)
{
    QDomNode toRet = doc.createElement("Page");
    if(reporHeader)
    {
        QDomNode child = rHeaderNode.firstChild();
        while(!child.isNull())
        {
            QDomElement ele = child.toElement();
            if(ele.attribute("id")=="Field")
            {
                ele.setAttribute("id","Label");
                QString text = "";
                int formato = ele.attribute("formato").toDouble();
                QStringList value = ele.attribute("Sql").split(".");
                if(value.size()== 3)
                {
                    QString key = value.at(0) + "." + value.at(1);
                    text = applyFormato(selects.value(key).value(value.at(2)).toString(),formato);
                }                
                ele.setAttribute("Text",text);
            }
            else if(ele.attribute("id")=="RelationalField")
            {
                ele.setAttribute("id","Label");
                QString text = "";
                int formato = ele.attribute("formato").toDouble();
                QStringList value = ele.attribute("Sql").split(".");
                if(value.size()>1)
                {
                    QString key = value.at(0) + "." + value.at(1);
                    text = applyFormato(getRelationField(ele.attribute("value"),selects.value(key)),formato);
                }
                ele.setAttribute("Text",text);
            }
            else if(ele.attribute("id")=="CodeBar")
            {
                QString text = "";
                QStringList value = ele.attribute("Sql").split(".");
                if(value.size()== 3)
                {
                    QString key = value.at(0) + "." + value.at(1);
                    text = selects.value(key).value(value.at(2)).toString();
                }                
                ele.setAttribute("Code",text);
            }
            else if(ele.attribute("id")=="Line")
            {
                bool globlaLine = ele.attribute("endPointName") != "Self";
                if(globlaLine)
                {
                    double footStart = pageUsable;
                    if(ele.attribute("endPointName") == "Pie de pagina")
                        footStart-= PFooterSiz;
                    else if(ele.attribute("endPointName") == "Pie de report")
                        footStart-= RFootSiz;
                    double LineEnd = footStart + ele.attribute("endPointPoint").toDouble();
                    double LineStart = ele.attribute("y").toDouble();
                    ele.setAttribute("h",LineEnd - LineStart);
                }
            }
            else if(ele.attribute("id")=="RoundRect")
            {
                bool globlaLine = ele.attribute("endPointName") != "Self";
                if(globlaLine)
                {
                    double footStart = pageUsable;
                    if(ele.attribute("endPointName") == "Pie de pagina")
                        footStart-= PFooterSiz;
                    else if(ele.attribute("endPointName") == "Pie de report")
                        footStart-= RFootSiz;
                    double LineEnd = footStart + ele.attribute("endPointPoint").toDouble();
                    double LineStart = ele.attribute("y").toDouble();
                    ele.setAttribute("h",LineEnd - LineStart);
                }
            }
            child = child.nextSibling();
        }
        toRet.appendChild(rHeaderNode);
    }
    if(pageHeader)
    {
        QDomNode node = pHeaderNode.cloneNode(true);
        QDomNode child = node.firstChild();
        while(!child.isNull())
        {
            QDomElement ele = child.toElement();
            if(ele.attribute("id")=="Field")
            {
                ele.setAttribute("id","Label");
                QString text = "";
                int formato = ele.attribute("formato").toDouble();
                QStringList value = ele.attribute("Sql").split(".");
                if(value.size()== 3)
                {
                    QString key = value.at(0) + "." + value.at(1);
                    text = applyFormato(selects.value(key).value(value.at(2)).toString(),formato);
                }
                ele.setAttribute("Text",text);
            }
            else if(ele.attribute("id")=="RelationalField")
            {
                ele.setAttribute("id","Label");
                QString text = "";
                int formato = ele.attribute("formato").toDouble();
                QStringList value = ele.attribute("Sql").split(".");
                if(value.size()>1)
                {
                    QString key = value.at(0) + "." + value.at(1);
                    text = applyFormato(getRelationField(ele.attribute("value"),selects.value(key)),formato);
                }
                ele.setAttribute("Text",text);
            }
            else if(ele.attribute("id")=="CodeBar")
            {
                QString text = "";
                QStringList value = ele.attribute("Sql").split(".");
                if(value.size()== 3)
                {
                    QString key = value.at(0) + "." + value.at(1);
                    text = selects.value(key).value(value.at(2)).toString();
                }
                ele.setAttribute("Code",text);
            }
            else if(ele.attribute("id")=="Line")
            {
                bool globlaLine = ele.attribute("endPointName") != "Self";
                if(globlaLine)
                {
                    double footStart = pageUsable - PFooterSiz;
                    double LineEnd = footStart + ele.attribute("endPointPoint").toDouble();
                    double LineStart = ele.attribute("y").toDouble();
                    if(reporHeader)
                        LineStart+= RHSiz;
                    ele.setAttribute("h",LineEnd - LineStart);
                }
            }
            else if(ele.attribute("id")=="RoundRect")
            {
                bool globlaLine = ele.attribute("endPointName") != "Self";
                if(globlaLine)
                {
                    double footStart = pageUsable - PFooterSiz;
                    double LineEnd = footStart + ele.attribute("endPointPoint").toDouble();
                    double LineStart = ele.attribute("y").toDouble();
                    ele.setAttribute("h",LineEnd - LineStart);
                }
            }
            child = child.nextSibling();
        }
        toRet.appendChild(node);
    }
    doc.appendChild(toRet);
    return toRet;
}

QDomNode ReportRenderer::endPage(QDomNode pageNode, QDomNode footerNode , QMap<QString, float> _Acums)
{
    QDomNode n = footerNode.cloneNode(true);
    pageNode.appendChild(n);
    QDomNode child = n.firstChild();
    while(!child.isNull())
    {
        QDomElement ele = child.toElement();
        if(ele.attribute("id")=="Acumulador")
        {
            ele.setAttribute("id","Label");
            QString text = "";
            int formato = ele.attribute("formato").toDouble();
            text = applyFormato(QString::number(_Acums.value(ele.attribute("target")),'f',2),formato);
            ele.setAttribute("Text",text);
        }
        child = child.nextSibling();
    }
    return n;
}

void ReportRenderer::parseFooters(QDomNode RFooter, bool haveRfooter, QDomNode PFooter, bool havePFooter, QMap<QString, QSqlRecord> selects)
{
    if(haveRfooter)
    {
        QDomNode child = RFooter.firstChild();
        while(!child.isNull())
        {
            QDomElement ele = child.toElement();
            if(ele.attribute("id")=="Field")
            {
                ele.setAttribute("id","Label");
                QString text = "";
                int formato = ele.attribute("formato").toDouble();
                QStringList value = ele.attribute("Sql").split(".");
                if(value.size()== 3)
                {
                    QString key = value.at(0) + "." + value.at(1);
                    text = applyFormato(selects.value(key).value(value.at(2)).toString(),formato);
                }
                ele.setAttribute("Text",text);
            }
            else if(ele.attribute("id")=="RelationalField")
            {
                ele.setAttribute("id","Label");
                QString text = "";
                int formato = ele.attribute("formato").toDouble();
                QStringList value = ele.attribute("Sql").split(".");
                if(value.size()>1)
                {
                    QString key = value.at(0) + "." + value.at(1);
                    text = applyFormato(getRelationField(ele.attribute("value"),selects.value(key)),formato);
                }
                ele.setAttribute("Text",text);
            }
            else if(ele.attribute("id")=="CodeBar")
            {
                QString text = "";
                QStringList value = ele.attribute("Sql").split(".");
                if(value.size()== 3)
                {
                    QString key = value.at(0) + "." + value.at(1);
                    text = selects.value(key).value(value.at(2)).toString();
                }
                ele.setAttribute("Code",text);
            }
            else if(ele.attribute("id")=="Image")
            {
                QByteArray b;
                QStringList value = ele.attribute("Path").split(".");
                if(value.size()== 3)
                {
                    QString key = value.at(0) + "." + value.at(1);
                    b = selects.value(key).value(value.at(2)).toByteArray();
                    ele.setAttribute("img-data",QString(b));
                }
            }
            child = child.nextSibling();
        }
    }
    if(havePFooter)
    {
        QDomNode child = PFooter.firstChild();
        while(!child.isNull())
        {
            QDomElement ele = child.toElement();
            if(ele.attribute("id")=="Field")
            {
                ele.setAttribute("id","Label");
                QString text = "";
                int formato = ele.attribute("formato").toDouble();
                QStringList value = ele.attribute("Sql").split(".");
                if(value.size()== 3)
                {
                    QString key = value.at(0) + "." + value.at(1);
                    text = applyFormato(selects.value(key).value(value.at(2)).toString(),formato);
                }
                ele.setAttribute("Text",text);
            }
            else if(ele.attribute("id")=="RelationalField")
            {
                ele.setAttribute("id","Label");
                QString text = "";
                int formato = ele.attribute("formato").toDouble();
                QStringList value = ele.attribute("Sql").split(".");
                if(value.size()>1)
                {
                    QString key = value.at(0) + "." + value.at(1);
                    text = applyFormato(getRelationField(ele.attribute("value"),selects.value(key)),formato);
                }
                ele.setAttribute("Text",text);
            }
            else if(ele.attribute("id")=="CodeBar")
            {
                QString text = "";
                QStringList value = ele.attribute("Sql").split(".");
                if(value.size()== 3)
                {
                    QString key = value.at(0) + "." + value.at(1);
                    text = selects.value(key).value(value.at(2)).toString();
                }
                ele.setAttribute("Code",text);
            }
            else if(ele.attribute("id")=="Image")
            {
                QByteArray b;
                QStringList value = ele.attribute("Path").split(".");
                if(value.size()== 3)
                {
                    QString key = value.at(0) + "." + value.at(1);
                    b = selects.value(key).value(value.at(2)).toByteArray();
                    ele.setAttribute("img-data",QString(b));
                }
            }
            child = child.nextSibling();
        }
    }
}

QColor ReportRenderer::ColorFromString(QString s)
{
    QStringList l= s.split(",");
    QColor c;
    c.setRed  (l.at(0).toDouble());
    c.setGreen(l.at(1).toDouble());
    c.setBlue (l.at(2).toDouble());
    c.setAlpha(l.at(3).toDouble());
    return c;
}

float ReportRenderer::getNumber(QString in, int formato)
{
    float f = 0;
    switch (formato) {
    case 0:
    case 3:
    case 4:
        f= in.toFloat();
        break;
    case 1:
    case 5:
    case 6:
        in.replace(".","");
        in.replace(",",".");
        f= in.toFloat();
        break;
    case 2:
        in.replace(",","");
        f = in.toFloat();
        break;
    default:
        f= 0;
    }
    return f;
}

QString ReportRenderer::applyFormato(QString in, int formato)
{
    if(formato == 0 || formato > 6)
        return in;
    bool ok;
    double d = in.toDouble(&ok);
    if(!ok)
        return in;
    QString aux = QString::number(d, 'f' , 2);
    QString aux2 = QString::number(d, 'f' , 3);
    QString aux3 = QString::number(d, 'f' , 4);
    if(formato == 4)
        return aux;
    else if(formato == 3)
        return aux.replace(".",",");
    else if(formato == 2)
    {
        QString entero = aux.split(".").at(0);
        QString final;
        int count = 0;
        for(int i = entero.size()-1 ; i>= 0 ; i--)
        {
            final.prepend(entero.at(i));
            count++;
            if(count%3 == 0 && i != 0)
                final.prepend(",");
        }
        final.append(".");
        final.append(aux.split(".").at(1));
        return final;
    }
    else if(formato == 1)
    {
        aux.replace(".",",");
        QString entero = aux.split(",").at(0);
        QString final;
        int count = 0;
        for(int i = entero.size()-1 ; i>= 0 ; i--)
        {
            final.prepend(entero.at(i));
            count++;
            if(count%3 == 0 && i != 0)
                final.prepend(".");
        }
        final.append(",");
        final.append(aux.split(",").at(1));
        return final;
    }
    else if(formato == 5)
    {
        aux2.replace(".",",");
        QString entero = aux2.split(",").at(0);
        QString final;
        int count = 0;
        for(int i = entero.size()-1 ; i>= 0 ; i--)
        {
            final.prepend(entero.at(i));
            count++;
            if(count%3 == 0 && i != 0)
                final.prepend(".");
        }
        final.append(",");
        final.append(aux2.split(",").at(1));
        return final;
    }
    else if(formato == 6)
    {
        aux3.replace(".",",");
        QString entero = aux3.split(",").at(0);
        QString final;
        int count = 0;
        for(int i = entero.size()-1 ; i>= 0 ; i--)
        {
            final.prepend(entero.at(i));
            count++;
            if(count%3 == 0 && i != 0)
                final.prepend(".");
        }
        final.append(",");
        final.append(aux3.split(",").at(1));
        return final;
    }
}

QString ReportRenderer::ColorString(QColor c)
{
    return QString("%1,%2,%3,%4").arg(c.red()).arg(c.green()).arg(c.blue()).arg(c.alpha());
}

QPrinter *ReportRenderer::getPrinter() const
{
    return printer;
}

void ReportRenderer::setPrinter(QPrinter *value)
{
    printer = value;
}

QDomDocument ReportRenderer::getDocIn() const
{
    return DocIn;
}

void ReportRenderer::setDocIn(const QDomDocument &value)
{
    DocIn = value;
}

QMap<QString, QString> ReportRenderer::getQueryClausules() const
{
    return queryClausules;
}

void ReportRenderer::setQueryClausules(const QMap<QString, QString> &value)
{
    queryClausules = value;
}
