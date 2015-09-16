#include "inout.h"

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


int textToWords(const QString &text, QList<Word> &words)
{
    Word w;
    bool isWord = false;
    //Для каждого символа текста
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


int wordsToTexts(const QString &text, const QList<Word> &words, QList<QString> &texts)
{
    //Если нет ни одного слова
    if (words.isEmpty()){
        texts.clear();
        texts.append(text);
        return 1;
    }
    int count = 0;
    int defCount = 0;
    int itCount = 0;
    QString spaser;
    bool haveGoodTranslitionText = haveGoodTranslition(words);
    texts.clear();
    texts.append("");
    //Для каждого слова
    for (int i = 0; i < words.length(); ++i){
        int startSpaser = words[i].position + words[i].original.length();
        int endSpaser = -1;
        //Если не последнее слово
        if (i != words.length() - 1){
            endSpaser = words[i+1].position - startSpaser;
        }
        spaser = text.mid(startSpaser, endSpaser);
        defCount = texts.length();
        //Для каждого уже существующего текста
        for (int k = 0; itCount < defCount ; ++k){
            //Для каждого перевода слова
            for (int j = 0; j < words[i].translations.length(); ++j){
                // Создать копию перевода данного текста с
                if (!haveGoodTranslitionText || !words[i].translations[j].contains('?')){
                    count++;
                    texts.insert(k+count, texts[k] + words[i].translations[j] + spaser);
                }
            }
            texts.removeAt(k);
            k+=count-1;
            count = 0;
            itCount++;
        }
        itCount = 0;
    }
    return texts.length();
}


bool writeTexts(const QString &fileName, const QList<QString> &texts)
{
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly)){
        QTextStream output(&file);
        //Выводим колво текстов вответе
        output << "Количество вариантов перевода: " + QString::number(texts.count());
        //Выводим каждый текст
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
    //Для каждой строки
    for (QStringList::iterator i = textInList.begin(); i != textInList.end(); ++i){
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


bool haveGoodTranslition(const QList<Word> &text)
{
    bool res = true;
    for (QList<Word>::const_iterator i = text.constBegin(); i != text.constEnd(); ++i){
        res &= i->haveGoodTranslition;
    }
    return res;
}

