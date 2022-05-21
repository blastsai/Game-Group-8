void SetColor(int backgound_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}
//Show Hide scroll bar
void ShowScrollbar(BOOL Show)
{
    HWND hWnd = GetConsoleWindow();
    ShowScrollBar(hWnd, SB_BOTH, Show);
}
//Disable Resize Window
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
    if(GetConsoleWindow == NULL)
    {
        return NULL;
    }
    //call the undocumented function
    return GetConsoleWindow();
}

void InitWindowConsole()
{
    //SetColor(7,12);
    //Change location and size of console window
    HWND hWnd=GetConsoleWindowNT();
    MoveWindow(hWnd,0,405,1290,350,TRUE);
    //Hide scroll bar
    ShowScrollbar(0);
    //forbid changing size of console window
    DisableResizeWindow();
}

void InitEverythings(char GameName[])
{
    SetConsoleOutputCP(CP_UTF8);
    InitWindowConsole();
    initwindow(1290,400,GameName);
}

void StartConversation(char charactorImageLink[],char imageLink[],char charactorName[],char conversation[])
{
    cleardevice();
    readimagefile(imageLink,50,0,1230,400);
    readimagefile(charactorImageLink,100,200,300,400);

    system("cls");
    int i=0;
    printf("\t%s\n\t",charactorName);
    while(i<strlen(conversation))
    {
        printf("%c",conversation[i++]);
        Sleep(10);
        if(kbhit())
        {
            getch();
            system("cls");
            printf("\t%s\n\t",charactorName);
            printf("%s",conversation);
            break;
        }
    }
    printf("\n\n\t---Nhấn phím bất kì để tiếp tục---");
    getch();
    Beep(500,200);
    system("cls");
}

void StartQuestion(char charactorImageLink[],char imageLink[],char charactorName[],char question[],int rightAnswer)
{
    cleardevice();
    readimagefile(imageLink,50,0,1230,400);
    readimagefile(charactorImageLink,100,200,300,400);
    system("cls");
    while(1)
    {
        int i=0;
        printf("\t%s\n\t",charactorName);
        while(i<strlen(question))
        {
            printf("%c",question[i++]);
            if(kbhit())
            {
                getch();
                system("cls");
                printf("\t%s\n\t",charactorName);
                printf("%s",question);
                break;
            }
            Sleep(10);
        }

        printf("\n\n\tNhập câu trả lời của bạn: ");
        int inputKey=getch();
        Beep(500,200);
        printf("%c",inputKey);
        if(inputKey==rightAnswer+48)
            break;

        char wrongCoversation[]="\n\n\t\tCâu trả lời của bạn bị sai";

        i=0;
        while(i<strlen(wrongCoversation))
        {
            printf("%c",wrongCoversation[i++]);
            Sleep(10);
        }
        system("cls");
    }
    system("cls");
}

int StartSelection(char charactorImageLink[],char imageLink[],char charactorName[],char conversation[],int rightSellection[],int rightSellectionLength)
{
    cleardevice();
    readimagefile(imageLink,50,0,1230,400);
    readimagefile(charactorImageLink,100,200,300,400);

    while(1)
    {
        system("cls");
        int i=0;
        printf("\t%s\n\t",charactorName);
        while(i<strlen(conversation))
        {
            printf("%c",conversation[i++]);
            Sleep(30);
        }
        printf("\n\n\t---Nhập lựa chọn của bạn: ");
        int answer=getch();
        printf("%c",answer);
        Beep(500,200);

        for(int j=0; j<rightSellectionLength; j++)
        {
            if(answer-48==rightSellection[j])
                return answer-48;
        }
        printf("\n\n\tLựa chọn của bạn không hợp lệ");
        Sleep(1000);
    }

    return -1;
}

int Menu(char menuImageLink[])
{
    cleardevice();
    readimagefile(menuImageLink,50,0,1230,400);
    while(1)
    {

        printf("Nhập lựa chọn của bạn: ");
        int input=getch();
        printf("%c",input);
        switch(input)
        {
        case 49:
            return 1;
        case 50:
            return 2;
        case 51:
            return 3;
        default:
            system("cls");
            printf("\tLựa chọn của bạn không hợp lệ, hãy nhập lại.\n");
            break;
        }
    }

    return -1;

}

int LoadData(char fileName[])
{
    std::fstream data;
    data.open(fileName,std::ios_base::in);
    if(data.fail())
    {
        data.open(fileName,std::ios_base::out);
        data<<0;
        return 0;
    }

    int x;
    data>>x;
    data.close();
    return x;
}

void SaveData(char fileName[],int intData)
{
    std::ofstream data;
    data.open(fileName,std::ios_base::out);
    data<<intData;
    data.close();
}

void ClearData(char fileName[])
{
    SaveData(fileName,0);
}

void SaveGame(char fileName[],int data)
{
    FILE *f;
    f=fopen(fileName,"w");
    fprintf(f,"%d",data);
    fclose(f);
}

int LoadGame(char fileName[])
{
    while(1)
    {
        int d;
        FILE *f;
        f=fopen(fileName,"r");
        if(f==NULL)
        {
            SaveGame(fileName,0);
            continue;
        }
        fscanf(f,"%d",&d);
        fclose(f);
        return d;
    }
    return -1;
}

void NewGame(char fileName[])
{
    SaveGame(fileName,0);
}

void Flicker(char imageLink[],int numberOfFlashes,int delayTime,int color)
{
    int c=0;
    while(c<numberOfFlashes)
    {
        readimagefile(imageLink,50,0,1230,400);
        Sleep(delayTime);
        cleardevice();
        setbkcolor(color);
        c++;
    }
    setbkcolor(BLACK);
}

void Shake(char imageLink[],int numberOfShake)
{
    int c=0;
    while(c<numberOfShake)
    {
        readimagefile(imageLink,50,0,1230,400);
        Sleep(20);
        //cleardevice();
        readimagefile(imageLink,40,10,1220,410);
        Sleep(20);
        //cleardevice();
        readimagefile(imageLink,50,0,1230,400);
        Sleep(20);
        //cleardevice();
        readimagefile(imageLink,60,10,1240,410);
        Sleep(20);
        //cleardevice();
        c++;
    }
    cleardevice();
}

void HardFlicker(char imageLink[],int numberOfFlashes,int color)
{
    int c=0;
    setbkcolor(color);
    while(c<numberOfFlashes)
    {
        readimagefile(imageLink,50,0,1230,400);
        Sleep(20);
        cleardevice();
        readimagefile(imageLink,40,10,1220,410);
        Sleep(20);
        cleardevice();
        readimagefile(imageLink,50,0,1230,400);
        Sleep(20);
        cleardevice();
        readimagefile(imageLink,60,10,1240,410);
        Sleep(20);
        cleardevice();
        c++;
    }
    setbkcolor(BLACK);
    cleardevice();
}

void HardShake(char imageLink[],int shakeTimes)
{
    int c=0;
    while(c<shakeTimes)
    {
        readimagefile(imageLink,50,0,1230,400);
        Sleep(10);
        readimagefile(imageLink,50,20,1230,420);
        Sleep(10);
        readimagefile(imageLink,50,0,1230,400);
        c++;
    }
}

typedef struct Vector2
{
    float x;
    float y;
} Vector2;

Vector2 GetMousePostion()
{
    Vector2 mousePos;
    POINT pnt;
    GetCursorPos(&pnt);
    ScreenToClient(GetForegroundWindow(), &pnt);
    mousePos.x=pnt.x;
    mousePos.y=pnt.y;
    return mousePos;
}

bool IsMouseLeftClick()
{
    return GetAsyncKeyState(VK_LBUTTON);
}

void StartAnswer(char charactorImageLink[],char imageLink[],char charactorName[],char conversation[])
{
    cleardevice();
    readimagefile(imageLink,50,0,1230,400);
    readimagefile(charactorImageLink,100,200,300,400);

    system("cls");
    int i=0;
    printf("\t%s\n\t",charactorName);
    while(i<strlen(conversation))
    {
        printf("%c",conversation[i++]);
        Sleep(10);
    }
    system("cls");
}
int input()
{
    printf("Nhập đáp án và enter: ");
    int n=0;
    int num;
    char tempString[1];
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
    sscanf(tempString,"%d",&num);
    system("cls");
    return num;
}

void SaveDataArray(char fileName[],int data[],int len)
{
    FILE *f;
    f=fopen(fileName,"w");
    for(int i=0;i<len;i++)
        fprintf(f,"%d ",data[i]);
    fclose(f);
}

int*LoadDataArray(char fileName[],int len)
{
    while(1)
    {
        int*arr=(int*)malloc(sizeof(int)*len);
        FILE *f;
        f=fopen(fileName,"r");
        if(f==NULL)
        {
            f=fopen(fileName,"w");
            continue;
        }
        for(int i=0;i<len;i++)
            fscanf(f,"%d",&arr[i]);
        fclose(f);
        return arr;
    }

    return NULL;
}
//thêm vào VNG.h
int random(int a,int b)
{
    return a+rand()%(b+1-a);
}

int randomAnswer(int s[])
{
    srand(time(0));
    int check;
    int b[100];
    int count=0;
    int i=0;
    int dem=0;
    int j=0;
    while(i<5)
    {
        check=random(0,12);
        for(int j=0;j<dem;j++)
        {
            if(b[j]==check)
            {
                count++;
            }
        }
        if(count==0)
        {
            s[j]=check;
            j++;
            i++;
        }
        b[dem]=check;
        count=0;
        dem++;
    }
    return *s;
}
