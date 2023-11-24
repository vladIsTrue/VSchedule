/**
 * @file pgdbcontroller.h
 * @brief The PgDBController class declaration.
 *
 * This class provides methods for connecting to and interacting with a PostgreSQL database.
 */

#ifndef PGDBCONTROLLER_H
#define PGDBCONTROLLER_H

#include "idbcontroller.h"

class PgDBController : public IDBController
{
public:
    /**
     * @brief PgDBController constructor.
     */
    PgDBController();

    /**
     * @brief PgDBController constructor with parameters.
     * @param dbHost The hostname of the database server.
     * @param dbName The name of the database.
     * @param dbUserName The username for the database connection.
     * @param dbPassword The password for the database connection.
     */
    PgDBController(const QString &dbHost
                   , const QString &dbName
                   , const QString &dbUserName
                   , const QString &dbPassword);

    /**
     * @brief PgDBController destructor.
     */
    ~PgDBController();

    /**
     * @brief Connect to the PostgreSQL database.
     * @return True if the connection was successful, false otherwise.
     */
    bool connectToDB();

    /**
     * @brief Disconnect from the PostgreSQL database.
     */
    void disconnectFromDB();

    /**
     * @brief Check the connection to the PostgreSQL database.
     * @return True if the connection is active, false otherwise.
     */
    bool checkConnection();

private:
    QString m_dbDriver            {"QPSQL"};
    QString m_dbHost              {"localhost"};
    QString m_dbName              {"vacation_data"};
    QString m_dbUserName          {"username"};
    QString m_dbPassword          {"username"};
    QSqlDatabase m_db             {};
};

#endif // PGDBCONTROLLER_H
