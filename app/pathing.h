#ifndef PATHING_H
#define PATHING_H

#include "dbmanager.h"
#include <QVector>
#include <QString>
#include <QMap>
#include <QPair>

//STRUCT ROUTE
struct route
{
	QString nextCampus;
    double distance;
    double totalDistance;
};

//SOUVENIR INFO STRUCT
struct souvenirInfo{
    QString name;
    int quantity;
    double price;
    QString campus;
};

//TOTAL CAMPUS STRUCT
struct totalCampus{
    QString campus;
    double price;
};

namespace calc
{

//FINDS THE SHORTEST PATH TO THE NEXT CAMPUS
QVector<route> ShortestPath(const QStringList &campusList, //HOLDS CAMPUSES TO VISIT
                            const QString &start );  //HOLDS THE START CAMPUS

//SUMS UP TOTAL DISTANCE TRAVELED
int sumOfDistance(QVector<route> retRoute); //ROUTE VECTOR

//ADDS SOUVENIRS
void addSouvenir(QVector<souvenirInfo> &souvenirList,const QString &souvenirName, QString &campusName);

//REMOVES SOUVENIRS
void removeSouvenir(QVector<souvenirInfo> &souvenirList, const QString &souvenirName);

//GETS TOTAL PRICE OF THE CAMPUS VISITED
void getTotalPrice(QVector<souvenirInfo> &souvenirList, QVector<totalCampus> &tCampuses);

//GETS GRAND TOTAL OF ALL THE CAMPUSES VISITED
double getGrandTotal(QVector<totalCampus> &tCampuses);

} // End namespace


#endif // PATHING_H
