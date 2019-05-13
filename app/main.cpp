#include "mainwindow.h"
#include "souvenirParser.h"
#include <QApplication>
#include <QtGlobal>
#include <QtDebug>
#include "dbmanager.h"
#include "pathing.h"

int main(int argc, char *argv[])
{
	// These are a few example usages of the DbManager
	//qDebug() << DbManager::instance().getSouvenirs("Saddleback College");
	//qDebug() << DbManager::instance().getAllDistancesFrom("Arizona State University");
	//qDebug() << DbManager::instance().getDistance("Saddleback College", "Arizona State University");
	//qDebug() << DbManager::instance().getDistance("Massachusetts Institude of Technology (MIT)", "Arizona State University");
	//qDebug() << DbManager::instance().getDistance("Some place which does not exist", "Arizona State University");

	//qDebug() << DbManager::instance().addCampus("Hi!");
	//qDebug() << DbManager::instance().changeCampusName("Hi!", "Someone's Fancy College");
	//qDebug() << DbManager::instance().deleteCampus("Ohio State University");
	//qDebug() << DbManager::instance().changeCampusDistance("Massachusetts Institude of Technology (MIT)", "University of Texas", 600.4);

    // Thesse are examples of Pathing
    //    QString start = "Saddleback College";
    //    QStringList testList = {"Saddleback College", "Ohio State University", "Arizona State University", "Massachusetts Institude of Technology (MIT)", "Northwestern"};
    //    QString end = "Ohio State University";
    //    QVector<route> testV;
    //    testV = calc::ShortestPath(testList, start);


    // These are examples of adding/removing souvenrirs
//    QVector<souvenirInfo> souvenirList;
//    QString campusName = "Saddleback College";
//    QString souvenirBuy = "Hat";

//    calc::addSouvenir(souvenirList, souvenirBuy, campusName);

//    qDebug() << souvenirList[0].name << "   " << souvenirList[0].quantity;

//    calc::addSouvenir(souvenirList, souvenirBuy, campusName);
//    calc::addSouvenir(souvenirList, souvenirBuy, campusName);

//    qDebug() << souvenirList[0].name << "   " << souvenirList[0].quantity;

//    calc::removeSouvenir(souvenirList, souvenirBuy);
//    calc::removeSouvenir(souvenirList, souvenirBuy);
//    calc::removeSouvenir(souvenirList, souvenirBuy);
//    calc::addSouvenir(souvenirList, "Sweatshirt", campusName);
//    calc::addSouvenir(souvenirList, "Sweatshirt", campusName);

//    calc::addSouvenir(souvenirList, "Sweatshirt", campusName);

//    QString campusName2 = "Massachusetts Institude of Technology (MIT)";

//    calc::addSouvenir(souvenirList, "Tote Bag" , campusName2);
//    calc::addSouvenir(souvenirList, "Tote Bag" , campusName2);
//    calc::addSouvenir(souvenirList, "Tote Bag" , campusName2);


//    qDebug() << souvenirList[0].name << "   " << souvenirList[0].quantity;

      //THESE ARE SAMPLES FOR TOTAL/GRAND TOTAL
//    QVector<totalCampus> testTotal;

//    calc::getTotalPrice(souvenirList,testTotal);

//    for(int i = 0; i < testTotal.size(); ++i){
//        qDebug() << testTotal[i].price << "PRICE" << testTotal[i].campus;
//    }
//    double testDouble = calc::getGrandTotal(testTotal);
//    qDebug() << testDouble << "GRAND";


	// This just ensures that it attempts to connect right when the program starts.
	DbManager::instance();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
