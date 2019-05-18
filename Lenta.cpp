#include "Lenta.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <string>

using namespace std;

void Lenta::lentosSukurimas()
{
    for (int i = 0; i < eilutes; i++)
    {
        for (int j = 0; j < stulpeliai; j++)
        {
            lenta[i][j] = '-';
        }
    }
}

void Lenta::atnaujintiLenta(bool pt, int x, int y)
{
    int eil_poz = x;
    int stulp_poz = y;

    if (pt == true)
    {
        lenta[eil_poz][stulp_poz] = 'H'; // H = HIT
    }

    else
    {
        lenta[eil_poz][stulp_poz] = 'X'; // X = MISS
    }
}

void Lenta::rodytiLenta()
{
    int kiekis = 0;

    cout << "                                    0 1 2 3 4 5 6 7 8 9" << endl;
    for (int i = 0; i < eilutes; i++)
    {
        cout  << "                 ";
        cout  << "                 " << kiekis << " ";
        kiekis++;
        for (int j = 0; j < stulpeliai; j++)
        {
            cout << lenta[i][j] << " ";
        }
        cout << endl;
    }
}
