#ifndef DBMUSICA_H
#define DBMUSICA_H

#include <QDialog>

namespace Ui {
    class dbmusica;
}

class dbmusica : public QDialog {
    Q_OBJECT
public:
    dbmusica(QWidget *parent = 0);
    ~dbmusica();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::dbmusica *ui;
};

#endif // DBMUSICA_H
