#include "editdinamycitemdlg.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include <QSqlError>

bool EditDinamycItemDlg::isSet = false;
QStringList EditDinamycItemDlg::_zonas;
QMap<QString,QStringList> EditDinamycItemDlg::_tablas;
QMap<QString,QStringList> EditDinamycItemDlg::_campos;

EditDinamycItemDlg::EditDinamycItemDlg(QWidget *parent) :
    QDialog(parent)
{
    db=QSqlDatabase::database("PRINCIPAL");
    if(!isSet)
    {
        QString value, valor;
        QStringList ZoneVerif;
        ZoneVerif << "Clave" << "pelis";
        _zonas << "General";
        QStringList groupTables;
        QSqlQuery q(db);
        q.exec("SELECT name FROM sqlite_master WHERE type='table'");
        while(q.next())
        {
            valor = q.record().value(0).toString();
            for (int a=0;a<ZoneVerif.count();a++)
            {
                value = ZoneVerif.value(a);
                if (value.contains(valor))
                    groupTables << q.record().value(0).toString();
            }
        }
        _tablas.insert("General",groupTables);
        QStringListIterator it(groupTables);
        while(it.hasNext())
        {
            QString tabla = it.next();
            QStringList campos;
            QString s = QString("PRAGMA TABLE_INFO('"+tabla+"')");
            q.exec(s);
            while(q.next())
            {
                campos << q.record().value(1).toString();
            }
            _campos.insert(tabla,campos);
        }
        isSet = true;
    }
}

QStringList EditDinamycItemDlg::zonas()
{
    return EditDinamycItemDlg::_zonas;
}

QStringList EditDinamycItemDlg::tablas(QString zona)
{
    return _tablas.value(zona);
}

QStringList EditDinamycItemDlg::campos(QString tabla)
{
    return _campos.value(tabla);
}
