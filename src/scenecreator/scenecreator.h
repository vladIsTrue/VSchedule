#ifndef SCENE_H
#define SCENE_H

#include <QVector>
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
    void fillStandardsVec();
    void addTextToRect(QGraphicsScene* scene, QGraphicsRectItem* itemRect, QString text);

    QSqlQuery* m_employeesQuery;
    QSqlQuery* m_stardardsQuery;

    const int m_mounthCount         = 12; // it's bad
    const int m_heightRow           = 15;
    const int m_dayOfMounth         = 30;
    const int m_widthEmployeeName   = 200;
    const int m_scale               = 2;
    int m_currentRow                = 0;

    struct
    {
        int standardNumber = 0;
        int currentNumber = 0;

    } m_standards[12]; // it's bad

    const char* m_mounth[12] = {"ЯНВАРЬ", "ФЕВРАЛЬ", "МАРТ", "АПРЕЛЬ",
                               "МАЙ", "ИЮНЬ", "ИЮЛЬ", "АВГУСТ", "СЕНТЯБРЬ",
                               "ОКТЯБРЬ", "НОЯБРЬ", "ДЕКАБРЬ"};
};

#endif //SCENE_H
