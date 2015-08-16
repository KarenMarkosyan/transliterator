#ifndef TESTANALYZE_H
#define TESTANALYZE_H
#pragma once

#include <QObject>
#include <QTest>

#include <functions.h>

class testAnalyze : public QObject
{
    Q_OBJECT
public:
    explicit testAnalyze(QObject *parent = 0);

signals:

public slots:

private Q_SLOTS:
    void test_data();
    void test();
};

#endif // TESTANALYZE_H
