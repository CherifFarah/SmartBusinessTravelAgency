#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "voyageinterface.h"
#include "login.h"
#include "dialog.h"
#include <QTabWidget>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//setAttribute(Qt::WA_TranslucentBackground);
//setWindowFlag(Qt::FramelessWindowHint);
}

MainWindow::~MainWindow()
{

    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    //login l;
    //l.exec();
//    Dialog d;
//    d.exec();
    VoyageInterface v;
    v.exec();
}
