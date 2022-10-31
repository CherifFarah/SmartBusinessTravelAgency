#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "personnel.h"

#include <QMainWindow>

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouter_clicked();

    void on_supprimer_clicked();



    void on_ajouter_2_clicked();

    void on_modifier_clicked();

private:
    Ui::MainWindow *ui;
    Personnel Ptmp; //un objet qui fait appel à la methode supprimer()
};
#endif // MAINWINDOW_H
