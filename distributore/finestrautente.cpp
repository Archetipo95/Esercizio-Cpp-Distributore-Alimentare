#include "finestrautente.h"
#include "ui_finestrautente.h"

finestraUtente::finestraUtente(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::finestraUtente)
{
    ui->setupUi(this);
}

finestraUtente::~finestraUtente()
{
    delete ui;
}

void finestraUtente::on_pushButton_released()
{
    //torna su main
}
