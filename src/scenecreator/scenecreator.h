#ifndef SCENE_H
#define SCENE_H

#include <QVector>
#include <QSqlError>
#include <QGraphicsScene>
#include <QtSql/QSqlQuery>

#define NUMBEROFMONTHS 12

enum QueryCode
{
    EMPLOYEES = 0,
    STANDARDS,
    LAST
};

template<typename ostreamT>
ostreamT& operator << (ostreamT& out, const QueryCode& t)
{
    switch(t) {
    case EMPLOYEES: return (out << "EMPLOYEES");
    case STANDARDS: return (out << "STANDARDS");
    case LAST:      return (out << "LAST");
    }
    return (out);
}

class SceneCreator : public QObject
{
    Q_OBJECT
public:
    SceneCreator();
    ~SceneCreator();

    QSqlError setQueryFromDB(QString query, QueryCode code);
    QGraphicsScene* createScene();

private:
    void fillStandardsVec();
    void addTextToRect(QGraphicsScene* scene, QGraphicsRectItem* itemRect, QString text);
    void drawLine(QGraphicsScene* scene);

    QSqlQuery* m_employeesQuery;
    QSqlQuery* m_stardardsQuery;

    struct
    {
        int standardNumber = 0;
        int currentNumber  = 0;

    } m_standards[NUMBEROFMONTHS];

    int m_currentNumberRows                = 0;

    static const int m_scale               = 2;
    static const int m_heightRow           = 14;

    static const int m_monthsNumber        = 12;
    static const int m_dayOfMonth          = 30;

    static const int m_indentation         = 50;
    static const int m_widthEmployeeName   = 200;

    const char* m_months[NUMBEROFMONTHS] = {"ЯНВАРЬ", "ФЕВРАЛЬ", "МАРТ", "АПРЕЛЬ",
                                           "МАЙ", "ИЮНЬ", "ИЮЛЬ", "АВГУСТ", "СЕНТЯБРЬ",
                                           "ОКТЯБРЬ", "НОЯБРЬ", "ДЕКАБРЬ"};

};

#endif //SCENE_H
