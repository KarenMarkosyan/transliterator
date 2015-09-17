#include <QString>
#include <QHash>
#include <QList>
#include <QFile>
#include <QTextStream>
#include <QStringList>

#pragma once

/*!
 * \brief RulesMap - Контейнер для хранения карты правил
 */
typedef QHash<QString, QString> RulesMap;
/*!
 * \brief The Word struct - описывает слово с его набором переводов
 */
struct Word{
    /*!
     * \brief original - Слово до перевода.
     */
    QString original;
    /*!
     * \brief translations - Список переводов.
     */
    QList<QString> translations;
    /*!
     * \brief positionInLine - Позиция слова в тексте.
     */
    int position;
    /*!
     * \brief haveGoodTranslition - Есть ли у слова хотябы один полный перевод
     */
    bool haveGoodTranslition;
    /*!
     * \brief operator == - Оператор сравнения
     * \param other
     * \return
     */
    bool operator ==(const Word& other){
        return original == other.original && translations == other.translations && position == other.position;
    }
};
