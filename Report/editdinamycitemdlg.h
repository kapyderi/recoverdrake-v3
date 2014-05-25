#ifndef EDITDINAMYCITEMDLG_H
#define EDITDINAMYCITEMDLG_H

#include <QDialog>
#include <QColorDialog>
#include <QSqlDatabase>

class EditDinamycItemDlg : public QDialog
{
    Q_OBJECT
public:
    explicit EditDinamycItemDlg(QWidget *parent = 0);    
    static QStringList zonas();
    static QStringList tablas(QString zona);
    static QStringList campos(QString tabla);

private:
    static bool isSet;
    static QStringList _zonas;
    static QMap<QString,QStringList> _tablas;
    static QMap<QString,QStringList> _campos;
    QSqlDatabase db;

};

#endif // EDITDINAMYCITEMDLG_H
