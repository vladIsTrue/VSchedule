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
ostreamT& operator<<(ostreamT& out, const QueryCode& code)
{
    switch(code)
    {
        case EMPLOYEES: return (out << "EMPLOYEES");
        case STANDARDS: return (out << "STANDARDS");
        case LAST:      return (out << "LAST");
    }
    return (out);
}

class SceneCreator
{
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
    QSqlError setQueryFromDB(const QString& query, const QueryCode code);

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
    static const int m_scale             = 2;    /**< The scale. */
    static const int m_heightRow         = 14;   /**< The height of a row. */
    static const int m_numberofmounth    = 12;   /**< The number of mounth. */

    static const int m_daysInYear        = 365;  /**< The number of days in a year. */

    static const int m_indentation       = 50;   /**< The indentation. */
    static const int m_widthEmployeeName = 200;  /**< The width of the employee name. */

    struct Standard
    {
        int standardNumber = 0; /**< The standard number. */
        int currentNumber  = 0; /**< The current number. */
    };

    QVector<Standard> m_standards{m_numberofmounth};

    QVector<QPair<QString, int>> m_months
    {
          qMakePair(QString("ЯНВАРЬ"),   31)
        , qMakePair(QString("ФЕВРАЛЬ"),  28)
        , qMakePair(QString("МАРТ"),     31)
        , qMakePair(QString("АПРЕЛЬ"),   30)
        , qMakePair(QString("МАЙ"),      31)
        , qMakePair(QString("ИЮНЬ"),     30)
        , qMakePair(QString("ИЮЛЬ"),     31)
        , qMakePair(QString("АВГУСТ"),   31)
        , qMakePair(QString("СЕНТЯБРЬ"), 30)
        , qMakePair(QString("ОКТЯБРЬ"),  31)
        , qMakePair(QString("НОЯБРЬ"),   30)
        , qMakePair(QString("ДЕКАБРЬ"),  31)
    };  /**< The months vector. */

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

     /**
     * @brief Adds a row to the scene based on the data from the employeesQuery.
     *
     * This function adds a row to the scene for each unique employee name in the employeesQuery.
     * The row contains the employee's name and a rectangle representing their vacation duration.
     * The rectangle's tooltip displays the start and end dates of the vacation.
     *
     * @param scene The scene to which the row is added.
     * @param employeesQuery The query containing the employee data.
     * @param oldName A reference to the last added employee name.
     */
    void addRow(QGraphicsScene* scene, QSqlQuery* employeesQuery, QString& oldName);

    /**
     * @brief Adds months to the scene.
     *
     * This function adds a row to the scene for each month in the year.
     * The row contains a text item representing the month's name.
     *
     * @param scene The scene to which the months are added.
     */
    void addMonths(QGraphicsScene* scene);

    int m_currentNumberRows = 0; /**< The current number of rows. */

    QSqlQuery* m_employeesQuery; /**< The employees query. */
    QSqlQuery* m_stardardsQuery; /**< The standards query. */
};

#endif //SCENE_H
