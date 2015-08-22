#include "functions.h"


bool readText(const QString &fileName, QString &text)
{
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly)){
        text = file.readAll();
        file.close();
        return true;
    }
    return false;
}


bool readRules(const QString &fileName, RulesMap &rules)
{
    QString text;
    QStringList textInList;
    QFile file(fileName);
    QString key, val;
    if (file.open(QIODevice::ReadOnly)){
        text = file.readAll();
        textInList = text.split("\n");
        for (QStringList::iterator i = textInList.begin(); i != textInList.end(); ++i){ // Пребераем текст построчно
            if (i->contains(" ")){
                val = i->mid(0, i->indexOf(" "));
                key = i->mid(i->indexOf(" ")+1);
                rules.insert(key, val);
            }
            else{
                return false;
            }
        }
        file.close();
        return true;
    }
    return false;
}


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
    for (RulesMap::const_iterator i = rules.constBegin(); i != rules.constEnd(); ++i){
        key = i.key();
        val = i.value();
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


int textToWords(const QString &text, QList<Word> &words)
{

}


int wordsToTexts(const QString &text, const QList<Word> words, QList<QString> &texts)
{

}


void analyze(Word &word, const RulesMap &rules, QString bufer, int start, int end)
{

}


void analyzeAllWords(QList<Word> &words, const RulesMap &rules)
{

}


bool writeTexts(const QString &fileName, const QList<QString> &texts)
{

}


RulesMap createRulesMap(const QStringList &s)
{
    RulesMap rules;
    QString val, key;
    QStringList textInList = s;
    for (QStringList::iterator i = textInList.begin(); i != textInList.end(); ++i){ // Пребераем текст построчно
        if (i->contains(' ')){
            val = i->mid(0, i->indexOf(" "));
            key = i->mid(i->indexOf(" ")+1);
            rules.insert(key, val);
        }
        else if(*i != "\n"){
            return RulesMap();
        }
    }
    return rules;
}
