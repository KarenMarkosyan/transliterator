#include <QString>
#include <QHash>
#include <QList>
#pragma once

/*!
 * \brief RulesMap - Контейнер для хранения карты правил
 */
typedef QHash<QString, QString> RulesMap;
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

    bool operator ==(const Word& other){
        return original == other.original && translations == other.translations && position == other.position;
    }
};


/*!
 * \brief readText - Считывает текст из файла.
 * \param fileName - Имя файла из которого происходит считывание.
 * \param text - Считаный текс.
 * \return - Успешность операции.
 */
bool readText ( const QString &fileName, const QString &text );
/*!
 * \brief readRules - Считывает набор правил из файла.
 * \param fileName - Имя файла из которого происходит считывание.
 * \param rules - Контейнер для правил.
 * \return - Успешность операции.
 */
bool readRules ( const QString &fileName, const RulesMap &rules );

RulesMap createRulesMap(const QString &s);
/*!
 * \brief isCorrectText - Проверяет состоили введенный текст из корректного набора символов (буквы текста только английские).
 * \param text - Проверяемый текст
 * \return - Является ли текст корректным.
 */
bool isCorrectText ( const QString &text );
/*!
 * \brief isCorrectRules - Проверяет является ли набор правил допустимым содержит корректную пару ([последовательность из латинских букв] = [последовательность из кирилических букв]).
 * \param rules - Набор правил
 * \return - Является ли набор правил корректным.
 */
bool isCorrectRules ( const RulesMap &rules );

/*!
  * \brief - textToWords - Переводит текст в список слов.
  * \param - text - Текст.
  * \param - words - Список слов.
  * \return - Количество слов.
  */
 int textToWords( const QString &text, QList<Word> &words);
 /*!
  * \brief wordsToTexts - Составляет набор выходных текстов.
  * \param text - Исходный текст.
  * \param words - Список слов.
  * \param texts - Список текстов.
  * \return - Количество текстов.
  */
 int wordsToTexts( const QString &text, const QList<Word> words, QList<QString> &texts);

 /*!
  * \brief analyze - Функция получения всех переводов данного слова
  * \param word - Слово для которого составляются переводы
  * \param rules - Набор правил в соответствии с которым переводим слово.
  * \param bufer - Строка перфикса.
  * \param start - Начало анализа слова.
  * \param end - конец анализа (-1 - до конца).
  */
 void analyze(Word& word, const RulesMap &rules, QString bufer = QString(), int start = 0, int end = -1);
 /*!
  * \brief analyzeAllWords - Перевести все слова из списка всеми возможными способами
  * \param words - Список слов
  * \param rules - Набор правил в соответствии с которым переводим.
  */
 void analyzeAllWords ( QList<Word>& words, const RulesMap &rules);

 /*!
  * \brief writeTexts - Сохранить в файл список текстов.
  * \param fileName - Имя файла.
  * \param texts - Список текстов.
  * \return
  */
 bool writeTexts ( const QString &fileName, const QList<QString> &texts );
