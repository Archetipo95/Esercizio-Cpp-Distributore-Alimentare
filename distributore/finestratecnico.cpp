#include "finestratecnico.h"
#include "ui_finestratecnico.h"

finestraTecnico::finestraTecnico(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::finestraTecnico)
{
    ui->setupUi(this);
}

finestraTecnico::~finestraTecnico()
{
    delete ui;
}

void finestraTecnico::on_pushButton_released()
{
        hide();

}
