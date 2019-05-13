#include <QtTest>
#include <QString>
#include <QTest>
#include "../../app/pathing.h"

// add necessary includes here

class tst_pathing : public QObject
{
	Q_OBJECT

public:
	tst_pathing();
	~tst_pathing();

private slots:
	//void test_shortestPath_data();
	//void test_shortestPath();

};

tst_pathing::tst_pathing()
{

}

tst_pathing::~tst_pathing()
{

}
/*
void tst_pathing::test_shortestPath_data() {
	QTest::addColumn<QVector<QVector<double>>>("distances");
	QTest::addColumn<QVector<QVector<QString>>>("campusDestinations");
	QTest::addColumn<QVector<QString>>("initialCampuses");
	QTest::addColumn<QString>("start");
	QTest::addColumn<QString>("end");

	QString campusStart[4] =
	{ "Arizona State University", "Massachusetts Institute of Technology (MIT)",
			"Northwestern", "Ohio State University" };

	QString campusDest[4][3] =
	{
	{ "Massachusetts Institute of Technology (MIT)", "Northwestern",
			"Ohio State University" },
	{ "Arizona State University", "Northwestern", "Ohio State University" },
	{ "Arizona State University", "Massachusetts Institute of Technology (MIT)",
			"Ohio State University" },
	{ "Arizona State University", "Massachusetts Institute of Technology (MIT)",
			"Northwestern" } };

	double distances[4][3] =
	{
	{ 2636.0, 1756.0, 1865.0 },
	{ 2636.0, 993.0, 772.0 },
	{ 1756.0, 993.0, 335.0 },
	{ 1865.0, 772.0, 335.0 } };

	QVector<QVector<double>> testDistances;

	QVector<QVector<QString>> testCampusDestinations;
	testCampusDestinations.resize(4);
	testDistances.resize(4);

	QVector<QString> initialCampuses;

	for (int i = 0; i < 4; ++i)
	{
		initialCampuses.push_back(campusStart[i]);
		for (int j = 0; j < 3; ++j)
		{
			testDistances[i].push_back(distances[i][j]);
			testCampusDestinations[i].push_back(campusDest[i][j]);
		}
	}

	QTest::addRow("Test1")
			<< testDistances
			<< testCampusDestinations
			<< initialCampuses
			<< "Massachusetts Institute of Technology (MIT)"
			<< "Arizona State University";

}

void tst_pathing::test_shortestPath()
{
	QFETCH(QVector<QVector<double>>, distances);
	QFETCH(QVector<QVector<QString>>, campusDestinations);
	QFETCH(QVector<QString>, initialCampuses);
	QFETCH(QString, start);
	QFETCH(QString, end);

	//calc::shortestPath(distances, campusDestinations, initialCampuses, start, end);
}
*/
QTEST_APPLESS_MAIN(tst_pathing)

#include "tst_pathing.moc"
