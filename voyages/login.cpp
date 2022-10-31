#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlag(Qt::FramelessWindowHint);
    ui->setupUi(this);
ui->mainFrame->setGeometry(100  ,90,801,491);
}

login::~login()
{
    delete ui;
}
