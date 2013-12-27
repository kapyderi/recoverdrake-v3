#ifndef EDITOR_H
#define EDITOR_H

#include <QWidget>

namespace Ui {
    class Editor;
}

class Editor : public QWidget {
    Q_OBJECT
public:
    Editor(QWidget *parent = 0);
    ~Editor();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Editor *ui;
};

#endif // EDITOR_H
