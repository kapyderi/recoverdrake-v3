#ifndef PREGUNTA_H
#define PREGUNTA_H

#include <QDialog>

namespace Ui {
class Pregunta;
}

class Pregunta : public QDialog
{
    Q_OBJECT
    
public:
    explicit Pregunta(QWidget *parent = 0);
    ~Pregunta();
    
private:
    Ui::Pregunta *ui;
};

#endif // PREGUNTA_H
