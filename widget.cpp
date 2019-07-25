#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->PBcoke->setEnabled(false);
    ui->PBtea->setEnabled(false);
    ui->PBcoffee->setEnabled(false);
    ui->PBreset->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int n){
    money += n;
    ui->lcdNumber->display(money);
    if(money>=200){
        ui->PBcoke->setEnabled(true);
        ui->PBtea->setEnabled(true);
        ui->PBcoffee->setEnabled(true);
    }
    else if (money>=150){
        ui->PBcoke->setEnabled(false);
        ui->PBtea->setEnabled(true);
        ui->PBcoffee->setEnabled(true);
    }
    else if (money>=100){
        ui->PBcoffee->setEnabled(true);
        ui->PBcoke->setEnabled(false);
        ui->PBtea->setEnabled(false);
    }
    else{
        ui->PBtea->setEnabled(false);
        ui->PBcoke->setEnabled(false);
        ui->PBcoffee->setEnabled(false);
    }
    if(money>0){
        ui->PBreset->setEnabled(true);
    }
    else{
        ui->PBreset->setEnabled(false);
    }

}
void Widget::on_PB10_clicked()
{
   changeMoney(10);
}

void Widget::on_PB50_clicked()
{
    changeMoney(50);
}

void Widget::on_PB100_clicked()
{
     changeMoney(100);
}

void Widget::on_PB500_clicked()
{
     changeMoney(500);
}

void Widget::on_PBcoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_PBtea_clicked()
{
    changeMoney(-150);
}
void Widget::on_PBcoke_clicked()
{

   changeMoney(-200);
}
void Widget::on_PBreset_clicked()
{
    int i,j,k,l;
    i=j=k=l=0;
    while (money>=500){
        changeMoney(-500);
        i+=1;
    }
    while (money>=100){
        changeMoney(-100);
        j+=1;
    }
    while (money>=50){
        changeMoney(-50);
        k+=1;
    }
    while (money>=10){
        changeMoney(-10);
        l+=1;
    }    
    QMessageBox msg;
    QString status = QString("500: %1 100: %2 50: %3 10: %4").arg(i).arg(j).arg(k).arg(l);
    msg.information(nullptr,"RESET", status);
}
