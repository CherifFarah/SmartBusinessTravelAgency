#ifndef DIALOG_H
#define DIALOG_H

#include <QPropertyAnimation>
#include <QHBoxLayout>
#include <QDialog>
#include <QLabel>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    Ui::Dialog *ui;
private:
    QPropertyAnimation *animation,*deleteFlightAnimation,*readFlightAnimation;
    int addTravelClicked,deleteTravelClicked,readTravelClicked,addTravelChanged,deleteTravelChanged,readTravelChanged;
};



#endif // DIALOG_H
