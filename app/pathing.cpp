#include "pathing.h"

namespace calc
{


//ALGORITHM THAT GETS THE SHORTEST PATH TO THE DESTINATION
QVector<route> ShortestPath(const QStringList &campusList, const QString &start)
{
    QVector<route> retRoute;
    QMap<QString, double> distancesFromEachTemp;
    QMap<QString, double> distancesFromEach;
    QMap<QString, double>::iterator it;
    QString nextCampus;
    static bool ifOnce = false;

    bool ifVisited = false;
    QVector<QString> visitedCampus;

    //INITIALIZATION
    retRoute.resize(campusList.size());
    visitedCampus.resize(campusList.size());
    retRoute[0].distance = 0;
    retRoute[0].nextCampus = start;
    retRoute[1].distance = 0;
    retRoute[1].nextCampus = "";

    //GETS THE DISTANCES OF ALL CAMPUSES IN THE LIST
    distancesFromEachTemp = DbManager::instance().getAllDistancesFrom(start);

    //GETS THE DISTANCES WITHIN THE INDICATED VISITING CAMPUSES
    for( it = distancesFromEachTemp.begin(); it != distancesFromEachTemp.end(); ++it)
    {
        for(int i = 0; i < campusList.size(); ++i){
            if(campusList[i] == it.key())
            {
                distancesFromEach.insert(it.key(), it.value());
            }
        }
    }

    visitedCampus[0] = start;

    //SETS VALUE FROM AFTER START TO BEFORE END
    for(int i = 1; i < campusList.size(); ++i)
    {
        qDebug() << "HELLO" << i;

        if(ifOnce == true){

            distancesFromEachTemp = DbManager::instance().getAllDistancesFrom(nextCampus);

            for( it = distancesFromEachTemp.begin(); it != distancesFromEachTemp.end(); ++it)
            {
                for(int i = 0; i < campusList.size(); ++i){
                    if(campusList[i] == it.key())
                    {
                        distancesFromEach.insert(it.key(), it.value());
                    }
                }
            }
        }

        retRoute[i].distance = 100000;

        for( it = distancesFromEach.begin(); it != distancesFromEach.end(); ++it)
        {
            for(int s = 0; s < visitedCampus.size(); ++s)
            {
                if(visitedCampus[s] == it.key()){
                    ifVisited = true;
                    break;
                }
            }

            if(it.value() < retRoute[i].distance  && ifVisited == false)
            {
                nextCampus = it.key();
                retRoute[i].nextCampus = it.key();
                retRoute[i].distance = it.value();
                visitedCampus[i] = it.key();
                retRoute[i].totalDistance = sumOfDistance(retRoute);
            }
            ifVisited = false;
        }

        ifOnce = true;
    }

    for(int i = 0; i < retRoute.size(); ++i){
        qDebug() << retRoute[i].nextCampus << "   " << retRoute[i].distance << "    " << retRoute[i].totalDistance;
    }

    return retRoute;
}


//FUNCTION THAT RETURNS SUM (TOTAL DISTANCE)
int sumOfDistance(QVector<route> retRoute)
{
	int sum = 0;
	for (int i = 0; i < retRoute.size(); ++i)
	{
        sum += retRoute[i].distance;
	}

	return sum;
}

//ADDS SOUVENIRS
void addSouvenir(QVector<souvenirInfo> &souvenirList,const QString &souvenirName, QString &campusName)
{
    bool ifContain = false;

    for(int i = 0; i < souvenirList.size(); ++i){
        if(souvenirList[i].name == souvenirName){
            ifContain = true;
        }
    }

    if(ifContain == true)
    {
        for(int i = 0; i < souvenirList.size(); ++i){
            if(souvenirList[i].name == souvenirName){
                souvenirList[i].quantity++;
                break;
            }
        }
    }else if(ifContain == false)
    {
        QMap<QString, double> tempMap = DbManager::instance().getSouvenirs(campusName);
        QMap<QString, double>::iterator it;
        souvenirInfo temp;

        //FINDS SOUVENIR PRICE
        for(it = tempMap.begin(); it != tempMap.end(); ++it){
            if(souvenirName == it.key()){
                temp.price = it.value();
                break;
            }
        }

        temp.name = souvenirName;
        temp.quantity = 1;
        temp.campus = campusName;
        souvenirList.push_back(temp);
    }
}

//REMOVES SOUVENIRS
void removeSouvenir(QVector<souvenirInfo> &souvenirList, const QString &souvenirName)
{
    for(int i = 0; i < souvenirList.size(); ++i){
        if(souvenirList[i].name == souvenirName){
            souvenirList[i].quantity--;

            if(souvenirList[i].quantity == 0){
                souvenirList.erase(souvenirList.begin() + i);
            }
            break;
        }
    }
}

//GETS TOTAL PRICE OF THE CAMPUS VISITED
void getTotalPrice(QVector<souvenirInfo> &souvenirList, QVector<totalCampus> &tCampuses)
{
    totalCampus tempTotal;
    bool ifIn = false;
    double sum = 0;



    for(int i = 0; i < souvenirList.size(); ++i)
    {
        for(int j = 0; j < tCampuses.size(); ++j){
            if(tCampuses[j].campus == souvenirList[i].campus){
                ifIn = true;
            }
        }

        if(!ifIn){
            tempTotal.campus = souvenirList[i].campus;
            tempTotal.price = 0;

            tCampuses.push_back(tempTotal);
        }
        ifIn = false;
    }

    for(int i = 0; i < tCampuses.size(); ++i)
    {
        sum = 0;

        for(int j = 0; j < souvenirList.size(); ++j){
            if(tCampuses[i].campus == souvenirList[j].campus){
                sum += (souvenirList[j].price * souvenirList[j].quantity);
            }
        }

        tCampuses[i].price = sum;
    }
}

//GETS GRAND TOTAL OF ALL THE CAMPUSES VISITED
double getGrandTotal(QVector<totalCampus> &tCampuses){
    double sum = 0;

    for(int i = 0; i < tCampuses.size(); ++i){
        sum += tCampuses[i].price;
    }

    return sum;
}



} // End namespace
