#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <windows.h>
#include "VNG.h"

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
    InitFullScreen("FIND THE TRUTH");

    readimagefile("Resources/sex.jpg",50,0,1230,400);
    getch();
    int i=0;
    char s[]="\nCó cài lồn địt con bà mày Có cài lồn địt con bà mày Có cài lồn địt con bà mày Có cài lồn địt con bà mày Có cài lồn địt con bà mày";
    while(i<strlen(s))
    {
        printf("%c",s[i++]);
        Sleep(30);
    }
    //system("pause");
    system("cls");
    //InputKey();


    getch();
    closegraph();

    return 0;
}
