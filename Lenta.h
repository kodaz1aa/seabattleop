#ifndef LENTA_H
#define LENTA_H

class Lenta
{
public:
    void lentosSukurimas();
    void atnaujintiLenta(bool pt, int x, int y);
    void rodytiLenta();
private:
    const static int eilutes = 10;
    const static int stulpeliai = 10;
    char lenta[eilutes][stulpeliai];
};

#endif // LENTA_H
