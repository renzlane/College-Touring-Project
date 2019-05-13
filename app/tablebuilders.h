#ifndef TABLEBUILDERS_H
#define TABLEBUILDERS_H

#include <QString>
#include <QTableWidget>

// TODO Make this one accept a list of campuses

/**
 * @brief Populates the given table with distances from the selected campus.
 * @param table
 *   Address of table to populate. MUST HAVE AT LEAST TWO COLUMNS.
 * @param selectedCampus
 *   Campus to get the distances from.
 */
void buildDistanceTable(QTableWidget *table, QString selectedCampus);

/**
 * @brief Populates the given table with its souvenirs.
 * @param table
 *   Address of table to populate. MUST HAVE AT LEAST TWO COLUMNS.
 * @param selectedCampus
 *   Campus to get the distances from.
 */
void buildSouvenirTable(QTableWidget *table, QString selectedCampus);


#endif // TABLEBUILDERS_H
