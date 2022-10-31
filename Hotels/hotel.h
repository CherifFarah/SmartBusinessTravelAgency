#ifndef HOTEL_H
#define HOTEL_H

#include <QString>
#include <QSqlQueryModel>

class Hotel
{
public:
    Hotel();
    Hotel(QString,QString,int,int);
    QString getnom();
    QString getadresse();
    int gettel();
    int getprix();
    void setnom(QString);
    void setadresse(QString);
    void settel(int);
    void setprix(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool update(QString Nom,QString adr,int prix,int tel);

private:
    QString nom,adresse;
    int tel,prix;
};

#endif // HOTEL_H
