void SetColor(int backgound_color, int text_color);

//ẩn hiện thanh cuộn
void ShowScrollbar(BOOL Show);

//cấm thay đổi kích thước
void DisableResizeWindow();

HWND WINAPI GetConsoleWindowNT(void);

void InitWindowConsole();

void InitEverythings(char GameName[]);

void StartConversation(char charactorImageLink[],char imageLink[],char charactorName[],char conversation[]);

void StartQuestion(char charactorImageLink[],char imageLink[],char charactorName[],char question[],int rightAnswer);

int StartSellection(char charactorImageLink[],char imageLink[],char charactorName[],char conversation[],int rightSellection[],int rightSellectionLength);

int Menu(char menuImageLink[]);

int LoadData(char fileName[]);

void SaveData(char fileName[],int intData);

void ClearData(char fileName[]);

void SaveGame(int data,char fileName[]);

int LoadGame(char fileName[]);

void NewGame(char fileName[]);