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
        if (text.indexOf('\r'))
            textInList = text.split("\r\n");
        else
            textInList = text.split("\n");
        rules = createRulesMap(textInList);
        return !rules.isEmpty();
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
    Word w;
    bool isWord = false;
    for(int i = 0; i < text.length(); ++i ){
        if (isWord) {
            if (text[i].isLetter() || text[i] == '`'){
                w.original.append(text[i]);
            }
            else{
                words.append(w);
                w.original.clear();
                isWord = false;
            }
        }
        else{
            if (text[i].isLetter() || text[i] == '`'){
                w.position = i;
                w.original.append(text[i]);
                isWord = true;
            }
        }
    }
    if (isWord){
        words.append(w);
    }
    return words.count();
}


int wordsToTexts(const QString &text, const QList<Word> words, QList<QString> &texts)
{
    if (words.isEmpty()){
        texts.clear();
        texts.append(text);
        return 1;
    }
    QString spaser;
    QList<QString> tmpText;
    bool haveGoodTranslition = true, haveLocalGoodTranslition = false;
    for (int i = 0; i < words.length(); ++i){
        for (int j = 0; j < words[i].translations.length(); ++j){
            haveLocalGoodTranslition = haveLocalGoodTranslition || !words[i].translations[j].contains('?');
        }
        haveGoodTranslition &= haveLocalGoodTranslition;
        haveLocalGoodTranslition = false;
    }
    texts.clear();
    texts.append("");
    for (int i = 0; i < words.length(); ++i){
        int startSpaser = words[i].position + words[i].original.length();
        int endSpaser = -1;
        if (i != words.length() - 1){
            endSpaser = words[i+1].position - startSpaser;
        }
        spaser = text.mid(startSpaser, endSpaser);
        for (int j = 0; j < words[i].translations.length(); ++j){
            if (!haveGoodTranslition || !words[i].translations[j].contains('?')){
                for (int k = 0; k < texts.length(); ++k){
                    tmpText.append(texts[k] + words[i].translations[j] + spaser);
                }
            }
        }
        texts = tmpText;
        tmpText.clear();
    }
    return texts.length();
}


void analyze(Word &word, const RulesMap &rules, QString bufer, int start, int len)
{
    QString translition;
    QString translatablePart = word.original.mid(start, len);

    for (RulesMap::const_iterator i = rules.constBegin(); i != rules.constEnd() && translition.isEmpty(); ++i){
        if (translatablePart.toLower() == i.key().toLower()){
            translition = i.value();
        }
    }
    if (translition.isEmpty()){
        translition = "?";
    }
    bufer += translition;
    if (word.original.length() == start + len){
        word.translations.append(bufer);
        bufer.clear();
    }
    else{
        analyze(word, rules, bufer, start + len, 1);
        analyze(word, rules, bufer.mid(0, bufer.length() - translition.length()), start, len + 1);
    }
}


void analyzeAllWords(QList<Word> &words, const RulesMap &rules)
{
    for (QList<Word>::iterator i = words.begin(); i != words.end(); ++i)
        analyze(*i, rules);
}


bool writeTexts(const QString &fileName, const QList<QString> &texts)
{
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly)){
        QTextStream output(&file);
        output << "Количество вариантов перевода: " + QString::number(texts.count());
        for (int i = 0; i < texts.length(); ++i){
            output << "\nПеревод №" + QString::number(i+1) + "\n------------------------------------------------------------\n"
                   << texts[i];
        }
        return true;
    }
    return false;
}


RulesMap createRulesMap(const QStringList &s)
{
    RulesMap rules;
    QString val, key;
    QStringList textInList = s;
    for (QStringList::iterator i = textInList.begin(); i != textInList.end(); ++i){ // ╧ЁхсхЁрхь ЄхъёЄ яюёЄЁюўэю
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
