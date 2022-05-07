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
    readimagefile(imageLink,50,0,1230,400);
    readimagefile(charactorImageLink,100,200,300,400);

    system("cls");
    int i=0;
    printf("\t%s\n\t",charactorName);
    while(i<strlen(conversation))
    {
        printf("%c",conversation[i++]);
        Sleep(30);
    }
    printf("\n\n\t---Nhấn phím bất kì để tiếp tục---");
    getch();
    Beep(500,200);
    system("cls");
}

void StartQuestion(char charactorImageLink[],char imageLink[],char charactorName[],char question[],int rightAnswer)
{
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
            Sleep(30);
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

int StartSellection(char charactorImageLink[],char imageLink[],char charactorName[],char conversation[],int rightSellection[],int rightSellectionLength)
{
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

        for(int j=0;j<rightSellectionLength;j++)
        {
            if(answer==rightSellection[j])
                return answer;
        }
        printf("\n\n\tLựa chọn của bạn không hợp lệ");
        Sleep(1000);
    }

    return -1;
}

int Menu(char menuImageLink[])
{
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
