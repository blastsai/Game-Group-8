#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <iostream>
#include <windows.h>

using namespace std;

void SetColor(int backgound_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}
//ẩn hiện thanh cuộn
void ShowScrollbar(BOOL Show)
{
    HWND hWnd = GetConsoleWindow();
    ShowScrollBar(hWnd, SB_BOTH, Show);
}
//cấm thay đổi kích thước
void DisableResizeWindow()
{
    HWND hWnd = GetConsoleWindow();
    SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}
HWND WINAPI GetConsoleWindowNT(void)
{
    //declare function pointer type
    typedef HWND WINAPI(*GetConsoleWindowT)(void);
    //declare one such function pointer
    GetConsoleWindowT GetConsoleWindow;
    //get a handle on kernel32.dll
    HMODULE hk32Lib = GetModuleHandle(TEXT("KERNEL32.DLL"));
    //assign procedure address to function pointer
    GetConsoleWindow = (GetConsoleWindowT)GetProcAddress(hk32Lib
    ,TEXT("GetConsoleWindow"));
    //check if the function pointer is valid
    //since the function is undocumented
    if(GetConsoleWindow == NULL){
        return NULL;
    }
    //call the undocumented function
    return GetConsoleWindow();
}

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
    SetColor(7,12);
    //thay đổi kích thước + vị trí
	HWND hWnd=GetConsoleWindowNT();
    MoveWindow(hWnd,0,396,1210,400,TRUE);
    //ẩn thanh cuộn
    ShowScrollbar(0);
    //cấm thay đổi kích thước;
    DisableResizeWindow();

    readimagefile("Resources/sex.jpg",3,0,1200,400);
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
