#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include<mmsystem.h>
#include <fstream>
#include <iostream>
#include<time.h>
#include "VNG.h"

//using namespace std;

void Minigame2();

void InputKey()
{
    int inputKey;
    int i=0;
    while(inputKey!=27)
    {
        inputKey=getch();
        switch (inputKey)
        {
        case 27: /* escape = abort */
            break;
        default:
            //cleardevice();
            setbkcolor(8);
            printf("%d ",inputKey);
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

void Day2();


int main()
{
    InitEverythings("FIND THE TRUTH");
    int menuSelect=-1;
    int gameData=0;

    PlaySound("Resources/Sound/girl ahh sound.wav",NULL,SND_ASYNC|SND_LOOP);

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

    int r[]= {1,2,3};
    while(1)
    {
        switch(gameData)
        {
        case 0:
            //Introduce();
            //StartConversation("Resources/Character/cjpg.jpg","Resources/cha.jpg","Mia","Xin chào các bạn, mình là Mia");
            Day2();
            gameData++;
            SaveData("GameData.txt",gameData);
            break;
        case 1:
            StartQuestion("","Resources/Menu.jpg","","1 cộng 3 bằng mấy \n\t 1.1 \t2.4 \t3.8 \t4.6  !!!",2);
            gameData++;
            SaveData("GameData.txt",gameData);
            break;
        case 2:
            gameData++;
            SaveData("GameData.txt",gameData);
            StartSelection("","Resources/aothatday.jpg","Trình","Ôi bạn ơi, bạn muốn uống viên nào!!!\n\t1. Viên kim cương 500k \t2. Viên vương miện \t3.Viên 10k",r,3);
            break;
        case 3:
            SaveData("GameData.txt",gameData);
            Minigame2();
            break;
        default:
            gameData=0;
            NewGame("GameData.txt");
            system("cls");
            printf("\n\n\tMục lưu game bị lỗi, vui lòng khởi động lại trò chơi.");
            break;
        }
    }

    //StartConversation("Resources/sex.jpg","Resources/cha.jpg","Mia","Có con cặc ý Có coặc ý Có con Có con cặc ý Có con cặc ý");
    //StartConversation("","Resources/Menu.jpg","","What !!!");
    //InputKey();
    //SaveData("GameData.txt",2000);
    //printf("%d",LoadData("GameData.txt"));
    //Flicker("Resources/Menu.jpg",20,30,RED);
    //Menu("Resources/Menu.jpg");
    //Shake("Resources/Menu.jpg",1);
    //HardFlicker("Resources/Menu.jpg",1,RED);
    //StartConversation("Resources/sex.jpg","Resources/cha.jpg","Mia","Có con cặc ý Có coặc ý Có con Có con cặc ý Có con cặc ý");
    getch();
    closegraph();

    Vector2 mousePos;

    return 0;
}

void Minigame2()
{
    system("cls");
    printf("Luật chơi: Hãy nhớ kĩ những số sắp xuất hiện sau đó bạn sẽ phải nhập lại đúng các số đó\n");
    system("pause");
    Sleep(1000);
    while(1)
    {
        srand(time(NULL));
        system("cls");
        printf("Các số chuẩn bị xuất hiện xin hãy sẵn sàng");
        Sleep(2000);
        system("cls");
        int a[4], b[4];
        int c=10;
        for (int i=0; i<4; i++)
        {
            a[i]=rand()%c;
            while((a[i]==a[i-1]) && (i>0))
            {
                a[i]=rand()%c;
            }
            printf("%d", a[i]);
            Sleep(400);
            system("cls");
            c*=10;
        }
        printf("Hãy nhập lại 5 số trên theo đúng thứ tự\n");
        scanf("%d %d %d %d", &b[0], &b[1], &b[2], &b[3]);
        int d=0;
        for (int i=0; i<4; i++)
        {
            if (a[i]!=b[i])
            {
                d++;
                break;
            }
        }
        if (d==0)
        {
            printf("Xin chúc mừng!!! Bạn đã trả lời đúng.");
            Sleep(500);
            break;
        }
        else
        {
            printf("Xin lỗi bạn đã trả lời sai. Vui lòng chơi lại.");
            Sleep(500);
            system("cls");
        }
    }

}

void InputFromWindow()
{
    InputKey();

    printf("Nhập số và enter: ");

    int num[4];
    int n=0;
    while(n<=3)
    {
        char tempString[10];
        int temp=0;
        char t=0;

        while((int)t!=13)
        {
            t=getch();
            printf("%c",t);
            if(t!=13) //nhập enter
                tempString[temp++]=t;
            if(t==32) //nhập space
                    break;
        }
        printf("%s ",tempString);
        sscanf(tempString,"%d",&num[n++]);
        system("cls");

    }
    printf("%d %d %d %d",num[0],num[1],num[2],num[3]);
}

void minigame1()
{
    FILE *f;
    FILE *fd;
    fd=fopen("Dapan.txt","r");
    int *a;
    a=(int*)malloc(7*sizeof(int));
    for(int i=0;i<7;i++)
    {
        fscanf(fd,"%d",&a[i]);
    }
    f=fopen("Cauhoi.txt","r");
    char s[7][40];
    StartConversation("Resources/nam.jpg","Resources/Trinh/day2minigame1-1.jpg","","Hãy vượt qua thử thách để đuổi lũ côn trùng đi!!!");
        int i;
        int n;
        int mat=0;
        printf("-----------------Tính nhanh--------------------\n");
        for (i=0; i<7; i++)
			{
			    fscanf(f, "%s", s+i);
			}
        for(int i=0;i<7;i++)
        {
            printf("Câu hỏi %d:%s\n",i+1,(s+i));
            n=input();
            printf("%d\n",n);
            if(n==a[i])
            {
                mat++;
                if(mat==1)
                {
                    StartAnswer("Resources/nam.jpg","Resources/Trinh/day2minigame1-2.jpg","","");
                }
                if(mat==2)
                {
                    StartAnswer("Resources/nam.jpg","Resources/Trinh/day2minigame1-3.jpg","","");
                }
                if(mat==3)
                {
                    StartAnswer("Resources/nam.jpg","Resources/Trinh/day2minigame1-4.jpg","","");
                }
                if(mat==4)
                {
                    StartAnswer("Resources/nam.jpg","Resources/Trinh/day2minigame1-5.jpg","","");
                }
                if(mat==5)
                {
                    StartAnswer("Resources/nam.jpg","Resources/Trinh/day2minigame1-6.jpg","","");
                }
                if(mat==6)
                {
                    StartAnswer("Resources/nam.jpg","Resources/Trinh/day2minigame1-7.jpg","","");
                }
                if(mat==7)
                {
                    StartAnswer("Resources/nam.jpg","Resources/Trinh/day2minigame1-7.jpg","","");
                }
            }
            else{

                i--;
                system("cls");
                printf("Bạn đã trả lời sai. Hãy tính lại\n");
            }
        }
        fclose(f);
        fclose(fd);
        free(a);
}
void Day2()
{

    StartConversation("Resources/Character/nam.jpg","Resources/Trinh/day2-1.jpg","","Sáng hôm sau mọi người hoảng hốt khi các thiết bị thông minh kể cả camera an ninh của mọi người đều bị đập hỏng không dùng được, các phương tiện đi lại cũng bị hư hại.");
    StartConversation("Resources/Character/nam.jpg","Resources/Trinh/day2-2.jpg","","Anh Minh quyết định và sửa xe để có thể đưa mọi người ra khỏi đây an toàn. Cả buổi sáng mọi người tâm sự với nhau và giúp đỡ anh Minh sửa xe.");
    StartConversation("Resources/Character/nam.jpg","Resources/Trinh/day2-3.jpg","","Đột nhiên mọi người nghe thấy tiếng giống gầm rú. Anh chị bảo đó là tiếng côn trùng hỗn tạp lại với nhau nhưng Ling lại thấy tiếng đo rất lạ.");
    StartConversation("Resources/Character/nam.jpg","Resources/Trinh/day2-4.jpg","","Mọi người ra ngoài kiểm tra kèm theo vũ khí tự vệ.  Đến nơi phát ra âm thanh to nhất, họ thấy tiếng côn trùng kết hợp lại không thành ra tiếng gì nữa mà chỉ như tiếng côn trùng bình thường.");
    StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-4.1.jpg","","Lại gần cái cây, mọi người thấy có rất nhiều những con côn trùng trên cây và bay xung quanh cây.Ling nói những tiếng tạo ra bởi côn trùng bay khỏi tổ cũng rất đặc biệt, mọi người thấy vậy liền lấy vũ khí ra đập vào cây");
    minigame1();
    StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-5.jpg","","5 cái ổ côn trùng được bịt có chủ đích bằng các tờ giấy được cuộn lại. Chính cách thông và bịt các đường đi của tổ côn trùng này làm tiếng lạ khi chúng bay ra.");
    StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-6.jpg","","Mọi người về khu kiểm lâm và mở tờ giấy, bất ngờ thay những tờ giấy khi ghép lại tạo thành một đoạn văn gồm x1, x2 ,x3, x4, x5, là “faoijf”, “ipokpq”, “rriqpqrprqr”, “ruqbiqooujffppqfg”,”rrotaphnapbgpajhfwbgkno”.");
    StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-7.jpg","","Những kí tự này liệu đang tồn tại những bí ản kinh khủng thế nào đây S0S S0S S0S??????");
    StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-8.jpg","","Mọi người thấy rằng đây chỉ là những khí tự vô nghĩa. Bế tắc, họ cùng nhau đi ngủ, riêng anh Nam sẽ thức đêm để canh mọi người.");
    StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-9.jpg","","Mọi người lại được phen tá hỏa khi anh Nam bị đánh bất tỉnh, nhưng mọi người đều không bị sao.");
    StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-10.jpg","","Hưng không chịu được quyết định mang vũ khí ra ngoài, mọi người không cản được và bị cuốn theo Hưng, trừ Ling ở lại chăm sóc anh Nam.");
    StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-11.jpg","","Trong lúc mọi người đang cố giữ bình tĩnh cho Hưng thì Ling từ trong nhà hét lên, khiến Hưng lao vút về nhà.");
    StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-12.jpg","","Nhưng xông vào nhà thì lại không thấy kẻ lạ mặt đâu, Ling nói hắn đang định phá tủ ở kia, khi nghe thấy tiếng động của mọi người lập tức rồi đi.  Ngay sau đó, anh Nam đã tỉnh lại, anh nói rằng mình bị đánh lén vào đầu nên bất tỉnh.");
    StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-13.jpg","","Anh đưa chìa khóa tủ cho mọi người và nói trong tủ đấy chính là bẫy động vật anh tự làm nhưng chưa hoàn thành.");
    StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-14.jpg","","Hưng cùng với anh Nam với sự sáng tạo đã hoàn thành và cải tiến cái bẫy. Hưng nói hắn muốn lấy cái bẫy chắc chắn do không muốn mọi người có cơ hội được sử dụng bẫy");
    StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-15.jpg","","Mọi người quyết định sẽ đặt bẫy này vào tối nay.");
    StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-16.jpg","","Mọi người vừa lên giường thì nghe thấy tiếng leng keng xung quanh ở ngoài lúc đi xa lúc đến gân. Tự nhiên “Choang” một cái – cái bẫy đã bắt được con gì đó.");
    StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-17.jpg","","Họ ra ngoài kiểm tra và biết được đấy là con chó hoang được đeo chiếc chuông ở chân, cổ và tay. Ling và Hiền cố giỗ con chó để nó bình tĩnh nhưng không được.");
    StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-18.jpg","","Hưng bất ngờ đè con chó xuống rồi lấy những chiếng chuông đi, sau đó đuổi con chó. Trong chuông mọi người phát hiện được 3 mảnh giấy khi ghép lại ra các gợi ý còn lại x6, x8, x10 lần lượt là “59”, “57931084”,”263930”.");
    StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-19.jpg","","Lại là những kí tự trông vô nghĩa nhưng đầy mờ ám và nguy hiểm");
    StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-20.jpg","","Nhưng cũng như trước, đó lại là những kỹ tự vô nghĩa, khác cái nó là số. Mọi người cũng lười không phân tích và đi ngủ, Nam và Hưng sẽ canh chừng mọi người.");
}



