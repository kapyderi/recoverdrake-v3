#ifndef DBOPCIONES_H
#define DBOPCIONES_H

#include <QDialog>

namespace Ui {
    class dbopciones;
}

class dbopciones : public QDialog {
    Q_OBJECT
public:
    dbopciones(QWidget *parent = 0);
    ~dbopciones();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::dbopciones *ui;
};

#endif // DBOPCIONES_H
