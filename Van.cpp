#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>

void cottruyen1()
{
    cleardevice();
    outtextxy(200, 200, "effg");
}
void cottruyen2()
{
    cleardevice();
    outtextxy(200, 200, "Vu Thanh Van");
}
void cottruyen1_2()
{
    cleardevice();
    outtextxy(200, 200, "Doan tuyet nang di");
}
void cottruyen1_1()
{
    cleardevice();
    outtextxy(200, 200, "FOlontino");
}
void giaido1()
{
    cleardevice();
    outtextxy(200, 200, "...");
}
void giaido2()
{
    cleardevice();
    outtextxy(200, 200, "...");
}
void cottruyen2_1()
{
    cleardevice();
    outtextxy(200, 200, "Alime");
}
void cottruyen2_2()
{
    cleardevice();
    outtextxy(200, 200, "Harem");
}
int main()
{
    initwindow(800, 800);
    settextstyle(0, 0, 3);
    outtextxy(200, 200, "Mo dau cau truyen");
    getch();
    outtextxy(200, 200, "Tinh huong");
    outtextxy(200, 300, "Lua chon 1");
    outtextxy(200, 400, "Lua chon 2");
    char c;
    while(1)
    {
        c=getch();
        if (c=='1')
        {
            cottruyen1();
            getch();
            cleardevice();
            outtextxy(200, 200, "Giai do 1");
            getch();
            giaido1();
            while(1)
            {
                c=getch();
                if (c=='1')
                {
                    cottruyen1_1();
                    break;
                }
                else
                {
                    cottruyen1_2();
                    break;
                }
                break;
            }

        }
        else if (c=='2')
        {
            cottruyen2();
            getch();
            cleardevice();
            outtextxy(200, 200, "Giai do 2");
            getch();
            giaido2();
            while(1)
            {
                c=getch();
                if (c=='1')
                {
                    cottruyen2_1();
                    break;
                }
                else
                {
                    cottruyen2_2();
                    break;
                }
            }
            break;
        }
    }





    getch();
    return 0;
}


