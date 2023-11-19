#ifndef PGDBCONTROLLER_H
#define PGDBCONTROLLER_H

#include "idbcontroller.h"

class PgDBController : public IDBController
{
public:
    PgDBController();
    PgDBController(const QString &dbHost
                   , const QString &dbName
                   , const QString &dbUserName
                   , const QString &dbPassword);
    ~PgDBController();

    bool connectToDB();
    void disconnectFromDB();
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
