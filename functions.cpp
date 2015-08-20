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

}


bool isCorrectRules(const RulesMap &rules)
{

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


RulesMap createRulesMap(const QString &s)
{

}
