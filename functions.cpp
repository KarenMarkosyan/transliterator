
void analyze(Word &word, const RulesMap &rules, QString bufer, int start, int len)
{
    QString translition;
    QString translatablePart = word.original.mid(start, len);
    //Проводим регистронезависимый поис по словарб выделенной подстроки
    for (RulesMap::const_iterator i = rules.constBegin(); i != rules.constEnd() && translition.isEmpty(); ++i){
        if (translatablePart.toLower() == i.key().toLower()){
            translition = i.value();
        }
    }
    //Если поиск не дал результатов то переводом считается ?
    if (translition.isEmpty()){
        translition = "?";
    }
    //Добавляяем перевод к уже имеющийся части перевода
    bufer += translition;
    if (word.original.length() == start + len){//Если переведены все символы слова
        //Добавляем перевод в список переводов и проверяем является ли перевод полным
        word.translations.append(bufer);
        word.haveGoodTranslition |= (bufer.indexOf("?") == -1);
        bufer.clear();
    }
    else{
        //Вызываем следующую итерацию рекурсии
        analyze(word, rules, bufer, start + len, 1);
        analyze(word, rules, bufer.mid(0, bufer.length() - translition.length()), start, len + 1);
    }
}


void analyzeAllWords(QList<Word> &words, const RulesMap &rules)
{
    // Для каждого слова вызвать функцию анализа
    for (QList<Word>::iterator i = words.begin(); i != words.end(); ++i){
        i->haveGoodTranslition = false;
        analyze(*i, rules);
    }
}
