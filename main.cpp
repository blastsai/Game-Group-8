#include <graphics.h>
#include <stdio.h>
#include <conio.h>

void InputKey()
{
    int InputKey;
    int i=0;
    while(InputKey!=27)
    {
        InputKey=getch();
        switch (InputKey)
        {
        //case 8: /* backspace */
        //break;
        //case 13: /* return */
        //break;
        case 27: /* escape = abort */
            break;
        default:
            cleardevice();
            setbkcolor(8);
            setcolor(i++);
            outtext("W");
            printf("%d ",InputKey);
            break;
        }
    }
}

int main()
{
    initwindow(800,800,"Game");

    //readimagefile("Resources/sex.jpg",100,100,300,300);
    InputKey();

    getch();
    closegraph();

    return 0;
}
