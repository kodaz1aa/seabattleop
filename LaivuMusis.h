#ifndef LAIVUMUSIS_H
#define LAIVUMUSIS_H

#pragma once

class LaivuMusis
{
public:
    LaivuMusis();
    void isvalytiLenta();
    int laivuSkaicius();
    void rodytiLenta();
    void ivestiLaivai();
    bool atakuoti(int x, int y);
private:
    const int static eilutes = 10;
    const int static stulpeliai = 10;
    int kordinates;
    int max_Laivai;
    int lenta[eilutes][stulpeliai];
};

#endif // LAIVUMUSIS_H
