#ifndef VOYAGE_H
#define VOYAGE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
class voyage
{

private:
    QString cin;
    QString destination;
    QString dateVoyage;
    float prixBillet;
public:
    voyage();
    voyage(QString cin,QString destination,QString date,float prix);

//setters
    void setCin(QString cin){this->cin=cin;};
    void setDestination(QString destination){this->destination=destination;};
    void setDate(QString date){this->dateVoyage=date;};
    void setPrix(float prix){this->prixBillet=prix;};

//getters
    QString getCin(){return cin;};
    QString getDestination(){return destination;};
    QString getDate(){return dateVoyage;};
    float getPrix(){return prixBillet;};

bool ajouterVoyage();
QSqlQueryModel *afficherVoyage();
bool SupprimerVoyage(QString Cin);
bool modifierVoyage(QString Cin,QString Destination,QString Date,float Prix);


};

#endif // VOYAGE_H
