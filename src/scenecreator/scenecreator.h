#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QtSql/QSqlQuery>

enum QueryCode
{
    EMPLOYEES = 0,
    STANDARDS,
    LAST
};

class SceneCreator : public QObject
{
    Q_OBJECT
public:
    SceneCreator();
    ~SceneCreator();

    void setQueryFromDB(QString query, QueryCode code);
    QGraphicsScene* createScene();

private:
    QSqlQuery* m_employeesQuery;
    QSqlQuery* m_stardardsQuery;
};

#endif //SCENE_H
