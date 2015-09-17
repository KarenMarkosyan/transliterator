#include <inout.h>
#pragma once


 /*!
  * \brief analyze - Функция получения всех переводов данного слова
  * \param word - Слово для которого составляются переводы
  * \param rules - Набор правил в соответствии с которым переводим слово.
  * \param bufer - Строка перфикса.
  * \param start - Начало анализа слова.
  * \param end - конец анализа (-1 - до конца).
  */
 void analyze(Word& word, const RulesMap &rules, QString bufer = QString(), int start = 0, int len = 1);
 /*!
  * \brief analyzeAllWords - Перевести все слова из списка всеми возможными способами
  * \param words - Список слов
  * \param rules - Набор правил в соответствии с которым переводим.
  */
 void analyzeAllWords ( QList<Word>& words, const RulesMap &rules);
