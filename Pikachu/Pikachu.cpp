// Pikachu.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "USE.h"
int main()
{
    ///--- cac setup mac dinh ---///
    Setup();
    SetConsoleOutputCP(850);
    Logo_CPP();
    int start = 1;
    while (start)
    {
        int select = Menu();
        if (A == 1)
            Beep(1000, 200);
        Sleep(500);
        if (select == 1)
        {
            
        }
        if (select == 2)
        {
            
        }
        if (select == 3)
        {
            
        }
        if (select == 6)
        {
            

        }
        if (select == 7)
        {

        }
        if (select == 8)
        {

        }
        if (select == 9)
        {

        }
        if (select == 10)
        {

        }
        if (select == 11)
        {
            
            Setting();
            continue;
        }
        if (select == 12)
        {
            break;
        }
        clrscr();
    }
    loop = 0;
    S = 0;
    Logo_CPP();
    clrscr();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
