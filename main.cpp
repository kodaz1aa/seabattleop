#define _WIN32_WINNT 0x0500
#define _WIN32_WINNT 0x0601
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include "LaivuMusis.h"
#include "Lenta.h"
typedef struct _CONSOLE_FONT_INFOEX
{
    ULONG cbSize;
    DWORD nFont;
    COORD dwFontSize;
    UINT  FontFamily;
    UINT  FontWeight;
    WCHAR FaceName[LF_FACESIZE];
} CONSOLE_FONT_INFOEX, *PCONSOLE_FONT_INFOEX;
//the function declaration begins
#ifdef __cplusplus
extern "C" {
#endif
BOOL WINAPI SetCurrentConsoleFontEx(HANDLE hConsoleOutput, BOOL bMaximumWindow, PCONSOLE_FONT_INFOEX
                                    lpConsoleCurrentFontEx);
#ifdef __cplusplus
}
#endif
#include <string>

using namespace std;

int main()
{
    char isnaujo;
    char start;
    srand((unsigned)time(NULL)); // kad nebutu same rand nr each time
    SetConsoleTitle("LAIVU MUSIS");
    system("color 5F");
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 800, 620, TRUE);
    int
    newWidth=15,
    newHeight=27;
    CONSOLE_FONT_INFOEX fontStructure= {8};
    fontStructure.cbSize=sizeof(fontStructure);
    fontStructure.dwFontSize.X=newWidth;
    fontStructure.dwFontSize.Y=newHeight;
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    SetCurrentConsoleFontEx(hConsole, true, &fontStructure);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "                                         L";
    system("color 5F");
    cout << "A";
    system("color 5F");
    cout << "I";
    system("color 5F");
    cout << "V";
    system("color 5F");
    cout << "U";
    system("color 5F");
    cout << " ";
    system("color 5F");
    cout << "M";
    system("color 5F");
    cout << "U";
    system("color 5F");
    cout << "S";
    system("color 5F");
    cout << "I";
    system("color 5F");
    cout << "S";
    cout << endl;
    cout << endl;
    cout << "                              JOG PRADETI ZAIDIMA, IVESKITE p: ";
    cin >> start;

    if (start == 'p')
    {
        do
        {
            system("CLS");

            LaivuMusis zmogus;
            LaivuMusis kompas;

            Lenta zmogausLenta;
            Lenta kompoLenta;

            zmogus.isvalytiLenta();
            zmogus.ivestiLaivai();

            kompas.isvalytiLenta();
            kompas.ivestiLaivai();

            zmogausLenta.lentosSukurimas();
            kompoLenta.lentosSukurimas();
            cout << "                                       Tavo lenta: " << endl;
            cout << endl;
            zmogausLenta.rodytiLenta();
            cout << endl;
            cout << "                                    Kompiuterio lenta: " << endl;
            cout << endl;
            kompoLenta.rodytiLenta();
            cout << endl;

            int poz1, poz2;
            char pasiduoti;
            int zmogus_rasti = 0;
            int zmogus_like = 10;

            int kompas_rasti = 0;
            int kompas_like = 10;

            bool zmogus_hit;
            bool kompas_hit;


            while (zmogus_rasti < 10 || kompas_rasti < 10)
            {

                int kompas_attack_EIL = rand() % 10;
                int kompas_attack_STULP = rand() % 10;

                if (kompas.atakuoti(kompas_attack_EIL, kompas_attack_STULP) == true)
                {
                    kompas_hit = true;
                    kompas_rasti++;
                    kompas_like--;
                    cout << "Kompiuteris pataike i jusu laiva siose kordinatese " << "<" << kompas_attack_EIL << " , " << kompas_attack_STULP << ">" << endl;
                    cout << "Kompiuterio viso rasta: " << kompas_rasti << " | Like: " << kompas_like << endl;
                }
                else
                {
                    kompas_hit = false;
                    cout << "Isvengete kulkos! Kompiuteris nepataike" << endl;
                }

                poz1 = 11;
                poz2 = 11;

                while (poz1 > 9 || poz2 > 9)
                {
                    if(kompas_rasti == 10 || zmogus_rasti == 10)
                    {
                        break;
                    }
                    cout << "Iveskite, kurias kordinates norite atakuoti (stulpelis , eilute): ";
                    cin >> poz1 >> poz2;

                    while (cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                        cout << "blogas ivedimas, iveskite dar karta: ";
                        cin >> poz1 >> poz2;
                    }
                }

                if (zmogus.atakuoti(poz1, poz2))
                {
                    zmogus_hit = true;
                    zmogus_rasti++;
                    zmogus_like--;
                    cout << "Pataikei i laiva koordinatese: " << "<" << poz1 << ", " << poz2 << ">" << endl;
                    cout << "Viso pataikyta i: " << zmogus_rasti << " laivu, o like: " << zmogus_like << " laivu" << endl;
                }
                else
                {
                    zmogus_hit = false;
                    cout << "nepataikei, bandyk toliau " << endl;
                    cout << "               Kompo pataikyta: " << kompas_rasti << endl;
                    cout << "               Zaidejo pataikyta: " << zmogus_rasti << endl;
                }

                cout << "Tu turi likusiu laivu: " << kompas.laivuSkaicius() << endl;
                cout << "Nori pasiduoti(t/n)? :";
                cin >> pasiduoti;

                system("CLS");

                zmogausLenta.atnaujintiLenta(zmogus_hit, poz1, poz2);
                kompoLenta.atnaujintiLenta(kompas_hit, kompas_attack_EIL, kompas_attack_STULP);

                cout << "Tavo lenta: " << endl;
                zmogausLenta.rodytiLenta();
                cout << "Kompo lenta" << endl;
                kompoLenta.rodytiLenta();

                if (pasiduoti == 't')
                {
                    break;
                }
                else if (zmogus_rasti == 10 || kompas_rasti == 10)
                {
                    break;
                }
            }

            cout << "Zaidimo pabaiga " << endl;
            cout << "Tavo lenta: " << endl;
            cout << "skaicius 9 ten kur pataikyti laivai " << endl;
            zmogus.rodytiLenta();
            cout << "############################################################################################" << endl;
            cout << "Kompo lenta: ";
            kompas.rodytiLenta();

            cout << "ar norite zaisti is naujo, ar baigti (z/b)?";
            cin >> isnaujo;
        }
        while(isnaujo=='z' || isnaujo == 'Z');
    }

    return 0;
}


