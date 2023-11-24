/**
 * @file scene.h
 * @brief The SceneCreator class declaration.
 *
 * This class is used to create a graphical scene using data received from the database
 */

#ifndef SCENE_H
#define SCENE_H

#include <QPair>
#include <QVector>
#include <QSqlError>
#include <QGraphicsScene>
#include <QtSql/QSqlQuery>

#define NUMBEROFMONTHS 12

/**
 * @brief The QueryCode enum represents different types of queries.
 *
 * The QueryCode enumeration is used when calling the setQueryFromDB function.
 * Responsible for which of the QSqlQuery type variables will contain the query result
 */
enum QueryCode
{
    EMPLOYEES = 0, /**< Employees query. */
    STANDARDS,     /**< Standards query. */
    LAST           /**< Last query. */
};

template<typename ostreamT>
ostreamT& operator << (ostreamT& out, const QueryCode& code)
{
    switch(code)
    {
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
    /**
     * @brief SceneCreator constructor.
     */
    SceneCreator();

    /**
     * @brief SceneCreator destructor.
     */
    ~SceneCreator();

    /**
     * @brief Set a query from the database.
     * @param query The query string.
     * @param code The query code.
     * @return The SQL error if any.
     *
     * This function executes a query and stores the result in a variable that corresponds to code
     */
    QSqlError setQueryFromDB(QString query, QueryCode code);

    /**
     * @brief Create a graphics scene.
     * @return The created scene.
     *
     * The function is responsible for creating a scene that should display the names of employees on the left,
     * all months of the year at the bottom, and the employee’s vacation period in the work area
     *
     */
    QGraphicsScene* createScene();

private:
    /**
     * @brief Fill the standards vector.
     */
    void fillStandardsVec();

    /**
     * @brief Add text to a rectangle.
     * @param scene The graphics scene.
     * @param itemRect The rectangle item.
     * @param text The text to add.
     */
    void addTextToRect(QGraphicsScene* scene, QGraphicsRectItem* itemRect, QString text);

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

    struct
    {
        int standardNumber = 0; /**< The standard number. */
        int currentNumber  = 0; /**< The current number. */

    } m_standards[NUMBEROFMONTHS]; /**< The standards array. */

    int m_currentNumberRows                 = 0;    /**< The current number of rows. */

    static const int m_scale                = 2;    /**< The scale. */
    static const int m_heightRow            = 14;   /**< The height of a row. */

    static const int m_daysInYear           = 365;    /**< The number of days in a year. */

    static const int m_indentation          = 50;   /**< The indentation. */
    static const int m_widthEmployeeName    = 200;  /**< The width of the employee name. */

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
};

#endif //SCENE_H
