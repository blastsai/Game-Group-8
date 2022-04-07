#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <iostream>
#include <windows.h>

using namespace std;

void InputKey()
{
    int InputKey;
    int i=0;
    while(InputKey!=27)
    {
        InputKey=getch();
        Beep(1200,200);
        switch (InputKey)
        {
        case 8: /* backspace */
            break;
        case 13: /* return */
            break;
        case 27: /* escape = abort */
            break;
        default:
            //cleardevice();
            setbkcolor(8);
            //printf("%d ",InputKey);
            break;
        }
    }
}

int main()

{
    SetConsoleOutputCP(CP_UTF8);
    initwindow(1200,400,"Game");

    readimagefile("Resources/cc.jpg",0,0,1200,400);
    getch();
    int i=0;
    char s[]="Có cài lồn địt con bà mày Có cài lồn địt con bà mày Có cài lồn địt con bà mày Có cài lồn địt con bà mày Có cài lồn địt con bà mày";
    while(i<strlen(s))
    {
        printf("%c",s[i++]);
        Sleep(20);
    }
    system("cls");
    //InputKey();


    getch();
    closegraph();

    return 0;
}


