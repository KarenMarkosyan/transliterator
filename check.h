#include <check.h>
#pragma once

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
 * \brief haveGoodTranslition - Естли полный перевод текста
 * \param text - массив слов
 * \return - существует ли хотябы один полный перевод текста
 */
bool haveGoodTranslition (const QList<Word> &text);
