#include "LaivuMusis.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <string>

using namespace std;

LaivuMusis::LaivuMusis()
{
    kordinates = 0;
    max_Laivai = 10;
}

void LaivuMusis::isvalytiLenta()
{
    for (int i = 0; i < eilutes; i++)
    {
        for (int j = 0; j < stulpeliai; j++)
        {
            lenta[i][j] = 0;
        }
    }

}

int LaivuMusis::laivuSkaicius()
{
    int kiekis = 0;
    for (int i = 0; i < eilutes; i++)
    {
        for (int j = 0; j < stulpeliai; j++)
        {
            if(lenta[i][j] == 1)
            {
                kiekis++;
            }
        }
    }
    return kiekis;
}

void LaivuMusis::rodytiLenta()
{
    cout << "                     @| 0 1 2 3 4 5 6 7 8 9" << endl;
    cout <<  "                                  ----------------------" << endl;
    for (int i = 0; i < eilutes; i++)
    {
        cout << "                 ";
        cout << "                 " << kordinates << "| ";
        kordinates++;
        for (int j = 0; j < eilutes; j++)
        {
            cout << lenta[i][j] << " ";
        }
        cout << endl;
    }
}

void LaivuMusis::ivestiLaivai()
{
    int laivai = 0;
    while (laivai < max_Laivai)
    {
        int eil_poz = rand() % 10;
        int stulp_poz = rand() % 10;

        if (lenta[eil_poz][stulp_poz] != 1)
        {
            laivai++;
            lenta[eil_poz][stulp_poz] = 1;
        }
    }
}

bool LaivuMusis::atakuoti(int x, int y)
{
    if (lenta[x][y] == 1)
    {
        lenta[x][y] = 9;
        return true;
    }
    return false;
}
