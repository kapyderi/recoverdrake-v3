#ifndef VISUALREPORT_H
#define VISUALREPORT_H

#include <QMainWindow>

namespace Ui {
class VisualReport;
}

class VisualReport : public QMainWindow
{
    Q_OBJECT

public:
    explicit VisualReport(QWidget *parent = 0);
    ~VisualReport();

private:
    Ui::VisualReport *ui;
};

#endif // VISUALREPORT_H
