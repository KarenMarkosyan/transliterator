#include <types.h>
#pragma once

/*!
 * \brief haveGoodTranslition - Естли полный перевод текста
 * \param text - массив слов
 * \return - существует ли хотябы один полный перевод текста
 */
bool haveGoodTranslition (const QList<Word> &text);
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
 int wordsToTexts(const QString &text, const QList<Word> &words, QList<QString> &texts);
 /*!
  * \brief writeTexts - Сохранить в файл список текстов.
  * \param fileName - Имя файла.
  * \param texts - Список текстов.
  * \return
  */
 bool writeTexts ( const QString &fileName, const QList<QString> &texts );
