#ifndef TESTWORDSTOTEXTS_H
#define TESTWORDSTOTEXTS_H

#include <QObject>
#include <QtTest/QTest>

#include <functions.h>
class testWordsToTexts : public QObject
{
    Q_OBJECT
public:
    explicit testWordsToTexts(QObject *parent = 0);

signals:

public slots:

private Q_SLOTS:
    void test_data();
    void test();
};

#endif // TESTWORDSTOTEXTS_H
