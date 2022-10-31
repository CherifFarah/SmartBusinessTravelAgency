#ifndef G_HOTELES_H
#define G_HOTELES_H

#include <QDialog>
#include "hotel.h"

namespace Ui {
class G_Hoteles;
}

class G_Hoteles : public QDialog
{
    Q_OBJECT

public:
    explicit G_Hoteles(QWidget *parent = nullptr);
    ~G_Hoteles();

private slots:
    //void on_pushButton_clicked();

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

private:
    Ui::G_Hoteles *ui;
    Hotel H;
};

#endif // G_HOTELES_H
