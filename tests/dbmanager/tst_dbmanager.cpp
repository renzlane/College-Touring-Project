#include <QtTest>
#include "../../app/dbmanager.h"

// add necessary includes here

class tst_dbmanager : public QObject
{
	Q_OBJECT

public:
	tst_dbmanager();
	~tst_dbmanager();

private slots:
	void verifyOpen();

	void password_data();
	void password();

	void campusNames_data();
	void campusNames();

	void editing();

};

tst_dbmanager::tst_dbmanager()
{

}

tst_dbmanager::~tst_dbmanager()
{

}

void tst_dbmanager::verifyOpen()
{
	//QVERIFY(DbManager::instance().isOpen());
	if(!DbManager::instance().isOpen())
	{
		QFAIL("Cannot execute database tests because we couldn't open database");
	}
}

void tst_dbmanager::password_data()
{
	QTest::addColumn<QString>("userName");
	QTest::addColumn<QString>("password");
	QTest::addColumn<DbManager::LoginResult>("result");

	QTest::addRow("Admin")            << "admin"   << "1234"     << DbManager::LoginResult::admin;
	QTest::addRow("Student")          << "student" << "pass"     << DbManager::LoginResult::student;
	QTest::addRow("Bad admin pass")   << "admin"   << "pathword" << DbManager::LoginResult::fail;
	QTest::addRow("Bad student pass") << "student" << "burp"     << DbManager::LoginResult::fail;
	QTest::addRow("Bad username")     << "Admin22" << "password" << DbManager::LoginResult::fail;
}

void tst_dbmanager::password()
{
	QFETCH(QString, userName);
	QFETCH(QString, password);
	QFETCH(DbManager::LoginResult, result);


	QCOMPARE(
		DbManager::instance().LoginCheck(userName, password),
		result
				);
}

void tst_dbmanager::campusNames_data()
{
	QTest::addColumn<QString>("campusName");

	QTest::addRow("University of Oregon")
		<< "University of Oregon";
	QTest::addRow("Ohio State University")
		<< "Ohio State University";
	QTest::addRow("University of California, Irvine (UCI)")
		<< "University of California, Irvine (UCI)";
}

void tst_dbmanager::campusNames()
{
	QFETCH(QString, campusName);

	QVERIFY(DbManager::instance().campusNames().contains(campusName));
}

void tst_dbmanager::editing()
{
	DbManager::instance().deleteCampus("Hi!");
	DbManager::instance().deleteCampus("Someone's Fancy College");
	DbManager::instance().deleteCampus("Another Fancy College");
	QVERIFY(!DbManager::instance().campusNames().contains("Someone's Fancy College"));
	QVERIFY(!DbManager::instance().campusNames().contains("Hi!"));
	QVERIFY(!DbManager::instance().campusNames().contains("Another Fancy College"));

	DbManager::instance().addCampus("Hi!");
	QVERIFY(DbManager::instance().campusNames().contains("Hi!"));

	DbManager::instance().changeCampusName("Hi!", "Someone's Fancy College");
	QVERIFY(DbManager::instance().campusNames().contains("Someone's Fancy College"));
	QVERIFY(!DbManager::instance().campusNames().contains("Hi!"));

	DbManager::instance().addCampus("Another Fancy College");
	QVERIFY(DbManager::instance().campusNames().contains("Another Fancy College"));

	QCOMPARE(DbManager::instance().getDistance(
				 "Someone's Fancy College", "Another Fancy College"), -1
	);

	DbManager::instance().changeCampusDistance("Someone's Fancy College", "Another Fancy College", 5);
	QCOMPARE(DbManager::instance().getDistance(
				 "Someone's Fancy College", "Another Fancy College"), 5
	);

	QMap<QString, double> newSouvenirs;
	newSouvenirs.insert("Hi", 300);
	newSouvenirs.insert("GOodBye", 240);
	newSouvenirs.insert("Meepo Plush", 990.99);
	DbManager::instance().changeCampusSouvenirs("Someone's Fancy College", newSouvenirs);
	QCOMPARE(DbManager::instance().getSouvenirs("Someone's Fancy College"), newSouvenirs);

	DbManager::instance().changeSouvenirName("Someone's Fancy College", "Hi", "Hello");
	QCOMPARE(DbManager::instance().getSouvenirs("Someone's Fancy College")["Hello"], 300);

	DbManager::instance().changeSouvenirPrice("Someone's Fancy College", "Meepo Plush", 9001);
	QCOMPARE(DbManager::instance().getSouvenirs("Someone's Fancy College")["Meepo Plush"], 9001);

	DbManager::instance().addSouvenir("Someone's Fancy College", "Spinner", 800.25);
	QCOMPARE(DbManager::instance().getSouvenirs("Someone's Fancy College")["Spinner"], 800.25);

	// This should NOT change the price of 'Hello'
	DbManager::instance().addSouvenir("Someone's Fancy College", "Hello", 800.25);
	QCOMPARE(DbManager::instance().getSouvenirs("Someone's Fancy College")["Hello"], 300);

	// This should FAIL because there is already a "Spinner"
	QVERIFY(!DbManager::instance().changeSouvenirName("Someone's Fancy College", "Hello", "Spinner"));

	DbManager::instance().deleteSouvenir("Someone's Fancy College", "Hello");
	QVERIFY(!DbManager::instance().getSouvenirs("Someone's Fancy College").contains("Hello"));


	DbManager::instance().deleteCampus("Hi!");
	DbManager::instance().deleteCampus("Someone's Fancy College");
	DbManager::instance().deleteCampus("Another Fancy College");
	QVERIFY(!DbManager::instance().campusNames().contains("Someone's Fancy College"));
	QVERIFY(!DbManager::instance().campusNames().contains("Hi!"));
	QVERIFY(!DbManager::instance().campusNames().contains("Another Fancy College"));

}

QTEST_APPLESS_MAIN(tst_dbmanager)
#include "tst_dbmanager.moc"
