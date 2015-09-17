#include "check.h"

bool isCorrectText(const QString &text)
{
    for (QString::const_iterator i = text.constBegin(); i != text.constEnd(); ++i){
        if (i->isLetter()){
            if (!((*i >= 'a' && *i <= 'z') || (*i >= 'A' && *i <= 'Z'))){
                return false;
            }
        }
    }
    return true;
}

bool isCorrectRules(const RulesMap &rules)
{
    QString key, val;
    //Для каждого правила
    for (RulesMap::const_iterator i = rules.constBegin(); i != rules.constEnd(); ++i){
        key = i.key();
        val = i.value();
        //Для каждого символа ключа
        for (QString::const_iterator j = key.constBegin(); j != key.constEnd(); ++j){
            if (j->isLetter()||*j == '`'){
                if (!((*j >= QChar('a') && *j <= QChar('z')) || *j == '`' || (*j >= QChar('A') && *j <= QChar('Z')))){
                    return false;
                }
            }
            else{
                return false;
            }
        }
        //Для каждого символа значения
        for (QString::const_iterator j = val.constBegin(); j != val.constEnd(); ++j){
            if (j->isLetter()){
                if (!((*j >= QChar(1040) && *j <= (1105)))){
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    return true;
}

bool haveGoodTranslition(const QList<Word> &text)
{
    bool res = true;
    for (QList<Word>::const_iterator i = text.constBegin(); i != text.constEnd(); ++i){
        res &= i->haveGoodTranslition;
    }
    return res;
}
