#ifndef SCENE_H
#define SCENE_H

#include <QPair>
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

<<<<<<< HEAD
    QSqlQuery* m_employeesQuery;
    QSqlQuery* m_stardardsQuery;
=======
    /**
     * @brief Draw a horizontal line.
     * @param scene The graphics scene.
     */
    void drawLine(QGraphicsScene* scene);

    /**
     * @brief Sums up the days in a month multiplied by m_scale.
     * @param end The index od end.
     */
    int accumulateDays(int end);

    QSqlQuery* m_employeesQuery; /**< The employees query. */
    QSqlQuery* m_stardardsQuery; /**< The standards query. */
>>>>>>> 797ea13 (months now have the correct number of days)

    struct
    {
        int standardNumber = 0;
        int currentNumber  = 0;

    } m_standards[NUMBEROFMONTHS];

    int m_currentNumberRows                = 0;

    static const int m_scale               = 2;
    static const int m_heightRow           = 14;

<<<<<<< HEAD
    static const int m_monthsNumber        = 12;
    static const int m_dayOfMonth          = 30;
=======
    static const int m_daysInYear           = 365;    /**< The number of days in a year. */
>>>>>>> 797ea13 (months now have the correct number of days)

    static const int m_indentation         = 50;
    static const int m_widthEmployeeName   = 200;

<<<<<<< HEAD
    const char* m_months[NUMBEROFMONTHS] = {"ЯНВАРЬ", "ФЕВРАЛЬ", "МАРТ", "АПРЕЛЬ",
                                           "МАЙ", "ИЮНЬ", "ИЮЛЬ", "АВГУСТ", "СЕНТЯБРЬ",
                                           "ОКТЯБРЬ", "НОЯБРЬ", "ДЕКАБРЬ"};

=======
    const QPair<const char*, int> m_months[NUMBEROFMONTHS] =
    {
          qMakePair("ЯНВАРЬ", 31)
        , qMakePair("ФЕВРАЛЬ", 28)
        , qMakePair("МАРТ", 31)
        , qMakePair("АПРЕЛЬ", 30)
        , qMakePair("МАЙ", 31)
        , qMakePair("ИЮНЬ", 30)
        , qMakePair("ИЮЛЬ", 31)
        , qMakePair("АВГУСТ", 31)
        , qMakePair("СЕНТЯБРЬ", 30)
        , qMakePair("ОКТЯБРЬ", 31)
        , qMakePair("НОЯБРЬ", 30)
        , qMakePair("ДЕКАБРЬ", 31)
    }; /**< The months array. */
>>>>>>> 797ea13 (months now have the correct number of days)
};

#endif //SCENE_H
