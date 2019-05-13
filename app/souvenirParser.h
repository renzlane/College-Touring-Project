#ifndef SOUVENIRPARSER_H
#define SOUVENIRPARSER_H

#include <QMap>
#include <QString>

/**
 * @brief stringToSouvenirs
 * @param souvenirString
 * @return TODO
 */
QMap<QString, double> stringToSouvenirs(const QString &souvenirString);

/**
 * @brief souvenirsToString
 * @param souvenirMap
 * @return TODO
 */
QString souvenirsToString(const QMap<QString, double> &souvenirMap);

#endif // SOUVENIRPARSER_H
