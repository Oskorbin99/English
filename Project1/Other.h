#include <iostream>
#include <ctime>
#include <vector>
using namespace std;
void secundomer_1(int secundomer)
{
    int a = time(NULL) - secundomer;
    int sec, min = 0, hour = 0;
    while (1)
    {
        if (a >= 3600)
        {
            hour++;
            a = a - 3600;
        }
        else if (a >= 60)
        {
            min++;
            a = a - 60;
        }
        else if (a < 60)
        {
            sec = a;
            break;
        }
    }
    cout << "Часов: " << hour << " Минут: " << min << " Секунд: " << sec << endl;
}
#pragma once