#ifndef DBLIBROS_H
#define DBLIBROS_H

#include <QDialog>

namespace Ui {
    class dblibros;
}

class dblibros : public QDialog {
    Q_OBJECT
public:
    dblibros(QWidget *parent = 0);
    ~dblibros();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::dblibros *ui;
};

#endif // DBLIBROS_H
