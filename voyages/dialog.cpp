#include "ui_dialog.h"
#include "dialog.h"


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

            animation=new QPropertyAnimation(ui->AjouterVoyageButtond,"geometry");
            animation->setDuration(700);
            animation->setStartValue(ui->AjouterVoyageButtond->geometry());
            animation->setEndValue(QRect(150,210,161,41));
            QEasingCurve curve;
            curve.setType(QEasingCurve::OutSine);
            //outSine/outBounce/outBack
            animation->setEasingCurve(curve);
            animation->start();
}

Dialog::~Dialog()
{

    delete ui;
}
