#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "g_hoteles.h"
#include "ui_g_hoteles.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground);
        setWindowFlags(Qt::FramelessWindowHint);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_connect_clicked()
{
    G_Hoteles g;
    g.exec();
}
