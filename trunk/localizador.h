#ifndef LOCALIZADOR_H
#define LOCALIZADOR_H

#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QFileInfo>

namespace Ui {
    class Localizador;
}

class Localizador : public QDialog
{
    Q_OBJECT

public:
    explicit Localizador(QWidget *parent = 0);
    ~Localizador();
    QString Local;
    QString Local1;
    QString getSize(QString Dir);

private slots:
    void on_pushButton_3_clicked();
    void on_pbAgregar_clicked();
    void on_pbEliminar_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Localizador *ui;
    QStringList listaArchivos;
    float tamanio;
    float limite;
};

#endif // LOCALIZADOR_H
