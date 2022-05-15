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

void Introduce()
{
    SaveGame("GameData.txt",0);
    //StartConversation("Resources/Character/cjpg.jpg","Resources/cha.jpg","Mia","Có con cặc ý Có coặc ý Có con Có con cặc ý Có con cặc ý");
}
void Day1()
{
    //StartConversation("Resources/sex.jpg","Resources/cha.jpg","Mia","Có con cặc ý Có coặc ý Có con Có con cặc ý Có con cặc ý");
    //StartConversation("Resources/sex.jpg","Resources/cha.jpg","Mia","Có con cặc ý Có coặc ý Có con Có con cặc ý Có con cặc ý");
    //StartConversation("Resources/sex.jpg","Resources/cha.jpg","Mia","Có con cặc ý Có coặc ý Có con Có con cặc ý Có con cặc ý");
    //StartConversation("Resources/sex.jpg","Resources/cha.jpg","Mia","Có con cặc ý Có coặc ý Có con Có con cặc ý Có con cặc ý");
    //StartConversation("Resources/sex.jpg","Resources/cha.jpg","Mia","Có con cặc ý Có coặc ý Có con Có con cặc ý Có con cặc ý");
}



int main()
{
    InitEverythings("FIND THE TRUTH");
    int menuSelect;
    int gameData=0;
    PlaySound("girl ahh sound.wav",NULL,SND_SYNC);

    do
    {
        menuSelect=Menu("Resources/Menu.jpg");
        switch(menuSelect)
        {
        case 1:
            gameData=LoadGame("GameData.txt");
            break;
        case 2:
            NewGame("GameData.txt");
            break;
        case 3:
            system("cls");
            printf("\n\tThoát game");
            return 1;
        default:
            break;
        }
    }
    while(menuSelect==-1);

    switch(gameData)
    {
    case 0:
        Introduce();
        break;
    case 1:
        break;
    default:
        gameData=0;
        NewGame("GameData.txt");
        system("cls");
        printf("\n\n\tMục lưu game bị lỗi, vui lòng khởi động lại trò chơi.");
        break;
    }
    //StartConversation("Resources/Character/cjpg.jpg","Resources/cha.jpg","Mia","Có con cặc ý Có coặc ý Có con Có con cặc ý Có con cặc ý");
    StartConversation("Resources/sex.jpg","Resources/cha.jpg","Mia","Có con cặc ý Có coặc ý Có con Có con cặc ý Có con cặc ý");
    //StartConversation("","Resources/Menu.jpg","","What !!!");
    //InputKey();
    //SaveData("GameData.txt",2000);
    //printf("%d",LoadData("GameData.txt"));
    //Flicker("Resources/Menu.jpg",20,30,RED);
    //Menu("Resources/Menu.jpg");
    //Shake("Resources/Menu.jpg",1);
    //HardFlicker("Resources/Menu.jpg",1,RED);
    //StartQuestion("","Resources/Menu.jpg","","What !!!",2);
    //StartConversation("Resources/sex.jpg","Resources/cha.jpg","Mia","Có con cặc ý Có coặc ý Có con Có con cặc ý Có con cặc ý");
    getch();
    closegraph();

    Vector2 mousePos;

    return 0;
}


