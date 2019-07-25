#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void changeMoney(int n);
    int money {0};

private slots:
    void on_PB10_clicked();

    void on_PB50_clicked();

    void on_PB100_clicked();

    void on_PB500_clicked();

    void on_PBcoffee_clicked();

    void on_PBtea_clicked();

    void on_PBcoke_clicked();
    
    void on_PBreset_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
