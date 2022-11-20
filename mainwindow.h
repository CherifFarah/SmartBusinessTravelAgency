#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "arduino.h"
#include <QMainWindow>
#include "entreprise.h"
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void update_label();   // slot permettant la mise à jour du label état de la lampe 1,
    // ce slot est lancé à chaque réception d'un message de Arduino

    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_tabWidget_tabBarClicked(int index);

    void on_pushButton_3_clicked();

    void on_searchLine_textChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    entreprise e;
    QByteArray data; // variable contenant les données reçues

    Arduino A; // objet temporaire
};
#endif // MAINWINDOW_H
