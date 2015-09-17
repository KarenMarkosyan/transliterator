#include <types.h>
#pragma once

/*!
 * \brief readText - Считывает текст из файла.
 * \param fileName - Имя файла из которого происходит считывание.
 * \param text - Считаный текс.
 * \return - Успешность операции.
 */
bool readText ( const QString &fileName, QString &text );
/*!
 * \brief readRules - Считывает набор правил из файла.
 * \param fileName - Имя файла из которого происходит считывание.
 * \param rules - Контейнер для правил.
 * \return - Успешность операции.
 */
bool readRules ( const QString &fileName, RulesMap &rules );
RulesMap createRulesMap(const QStringList &s);
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
 int wordsToTexts(const QString &text, const QList<Word> &words, QList<QString> &texts);
 /*!
  * \brief writeTexts - Сохранить в файл список текстов.
  * \param fileName - Имя файла.
  * \param texts - Список текстов.
  * \return
  */
 bool writeTexts ( const QString &fileName, const QList<QString> &texts );
