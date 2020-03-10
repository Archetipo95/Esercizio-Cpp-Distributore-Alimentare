#ifndef FINESTRAUTENTE_H
#define FINESTRAUTENTE_H

#include <QMainWindow>

namespace Ui {
class finestraUtente;
}

class finestraUtente : public QMainWindow
{
    Q_OBJECT

public:
    explicit finestraUtente(QWidget *parent = nullptr);
    ~finestraUtente();

private slots:
    void on_pushButton_released();

private:
    Ui::finestraUtente *ui;
};

#endif // FINESTRAUTENTE_H
