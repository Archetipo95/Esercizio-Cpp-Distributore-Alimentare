#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <finestratecnico.h>
#include <finestrautente.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonTecnico_released();

    void on_buttonUtente_released();

private:
    Ui::MainWindow *ui;
    finestraTecnico *winTecnico;
    finestraUtente *winutente;
};

#endif // MAINWINDOW_H
