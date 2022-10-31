#ifndef VOYAGEINTERFACE_H
#define VOYAGEINTERFACE_H
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QHBoxLayout>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include "voyage.h"
#include <QMessageBox>

namespace Ui {
class VoyageInterface;
}

class VoyageInterface : public QDialog
{
    Q_OBJECT



public:
    void setClickedAnimation();
    void setAddTravelClicked(int value){addTravelClicked=value;};
    void setDeleteTravelClicked(int value){deleteTravelClicked=value;};
    void setReadTravelClicked(int value){readTravelClicked=value;};
    void setUpdateTravelClicked(int value){updateTravelClicked=value;};

    void setAddTravelChanged(int value){addTravelClicked=value;};
    void setDeleteChanged(int value){deleteTravelClicked=value;};
    void setReadTravelChanged(int value){readTravelClicked=value;};
    explicit VoyageInterface(QWidget *parent = nullptr);
    ~VoyageInterface();


private slots:
    void on_AjouterVoyageButton_clicked();

    void on_SupprimerVoyageButton_clicked();

    void on_AfficherVoyageButton_clicked();

    void on_AjouterButton_clicked();

    void on_DeleteButton_clicked();

    void on_ModifierVoyageButton_clicked();

    void on_Update_clicked();

    void on_tableViewUpdate_clicked();


private:
    Ui::VoyageInterface *ui;
    QPropertyAnimation *animation,*deleteFlightAnimation,*readFlightAnimation,*updateFlightAnimation;
    QParallelAnimationGroup *animationGroupe;
    int addTravelClicked,deleteTravelClicked,readTravelClicked,addTravelChanged,deleteTravelChanged,readTravelChanged,updateTravelClicked;
};

#endif // VOYAGEINTERFACE_H
