#ifndef FINESTRATECNICO_H
#define FINESTRATECNICO_H

#include <QMainWindow>

namespace Ui {
class finestraTecnico;
}

class finestraTecnico : public QMainWindow
{
    Q_OBJECT

public:
    explicit finestraTecnico(QWidget *parent = nullptr);
    ~finestraTecnico();

private slots:
    void on_pushButton_released();

private:
    Ui::finestraTecnico *ui;
};

#endif // FINESTRATECNICO_H
