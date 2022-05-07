#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include<mmsystem.h>
#include <fstream>
#include <iostream>
#include "VNG.h"

//using namespace std;

void InputKey()
{
    int InputKey;
    int i=0;
    while(InputKey!=27)
    {
        InputKey=getch();
        switch (InputKey)
        {
        case 27: /* escape = abort */
            break;
        default:
            //cleardevice();
            setbkcolor(8);
            printf("%d ",InputKey);
            break;
        }
    }
}

int main()
{
    InitEverythings("FIND THE TRUTH");
    //StartConversation("Resources/Character/cjpg.jpg","Resources/cha.jpg","Mia","Có con cặc ý Có coặc ý Có con Có con cặc ý Có con cặc ý");
    //StartConversation("Resources/sex.jpg","Resources/cha.jpg","Mia","Có con cặc ý Có coặc ý Có con Có con cặc ý Có con cặc ý");
    //StartConversation("","Resources/Menu.jpg","","What !!!");
    //InputKey();
    SaveData("GameData.txt",2000);
    //printf("%d",LoadData("GameData.txt"));
    Menu("Resources/Menu.jpg");
    StartQuestion("","Resources/Menu.jpg","","What !!!",2);
    StartConversation("Resources/sex.jpg","Resources/cha.jpg","Mia","Có con cặc ý Có coặc ý Có con Có con cặc ý Có con cặc ý");
    getch();
    closegraph();

    return 0;
}
