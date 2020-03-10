#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonTecnico_released()
{
    winTecnico = new finestraTecnico(this);
    winTecnico->show();
}

void MainWindow::on_buttonUtente_released()
{
    winutente = new finestraUtente(this);
    winutente->show();
}
