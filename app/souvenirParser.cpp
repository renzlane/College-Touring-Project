#include "souvenirParser.h"
#include <QStringList>
#include <QtGlobal>
#include <QtDebug>

const char ENTRY_SEPARATOR = 31;  // 31 is the ASCII "Unit separator"
const char CURRENCY = '$';

QMap<QString, double> stringToSouvenirs(const QString &souvenirString) {
	QStringList ssl = souvenirString.split(ENTRY_SEPARATOR, QString::SkipEmptyParts);
	QMap<QString, double> souvenirMap;

	for(QStringList::const_iterator it = ssl.begin(); it != ssl.end(); ++it) {
		QString name = it->trimmed();

		++it;
		if(it == ssl.end()) {
			qWarning() << "Encountered stray souvenir: " << name << endl;
		}
		else {
			QString priceWord = it->trimmed();
			priceWord = priceWord.replace(CURRENCY,"");

			bool ok = false;
			double price = priceWord.toDouble(&ok);

			if(ok) {
				souvenirMap[name] = price;
			}
			else {
				qWarning()
					<< "While deserializing souvenir " << name
					<< ", encountered bad price: " << priceWord
					<< endl;
			} // End if(ok)
		} // End if(it == ssl.end()) ... else ...
	} // End for loop

	return souvenirMap;
}

QString souvenirsToString(const QMap<QString, double> &souvenirMap) {
	return QString();
}
