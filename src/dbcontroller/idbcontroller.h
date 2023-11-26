/**
 * @file idbcontroller.h
 * @brief The IDBController interface declaration.
 *
 * This interface provides methods for connecting to and interacting with a database.
 */

#ifndef IDBCONTROLLER_H
#define IDBCONTROLLER_H

#include <QtSql>
#include <QString>

class IDBController
{
public:
    /**
     * @brief Connect to the database.
     * @return True if the connection was successful, false otherwise.
     */
    virtual bool connectToDB() = 0;

    /**
     * @brief Disconnect from the database.
     */
    virtual void disconnectFromDB() = 0;

    /**
     * @brief Check the connection to the database.
     * @return True if the connection is active, false otherwise.
     */
    virtual bool checkConnection() = 0;
};

#endif // IDBCONTROLLER_H
