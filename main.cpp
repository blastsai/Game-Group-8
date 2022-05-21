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

void Day2();
void Day3();
void phase4();
void PartOne();
void End1_1();
void End1_2();
void End2_1();
void End2_2();
void End();

int*ls;
int ChessQuiz();
int Minigame1();
int Minigame2();
int CalculusQuiz();
int PrintfQuiz();
int gameData=0;
int main()
{
    InitEverythings("FIND THE TRUTH");
    int menuSelect=-1;
    ls=(int*)calloc(sizeof(int),6);
    PlaySound(TEXT("Resources/UpdateSound/Relax.wav"), NULL, SND_LOOP | SND_ASYNC);
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


    while(1)
    {
        switch(gameData)
        {
        case 0:
            PartOne();
            gameData++;
            SaveData("GameData.txt",gameData);
            break;
        case 1:
            Day2();
            gameData++;
            SaveData("GameData.txt",gameData);
            break;
        case 2:
            Day3();
            break;
        case 3:
            phase4();
            gameData++;
            SaveData("GameData.txt",gameData);
            break;
        case 4:
            End();
            SaveData("GameData.txt",gameData);
            break;
        default:
            gameData=0;
            NewGame("GameData.txt");
            system("cls");
            printf("\n\n\tMục lưu game bị lỗi, vui lòng khởi động lại trò chơi.");
            break;
        }
    }
    closegraph();

    return 0;
}

void InputfromConsole(int *a)
{
    char tempString[10];
    int temp=0;
    char t=0;
    while(1)
    {
        t=getch();
        printf("%c",t);
        if(t!=13 && t!=32) //nh?p enter
            tempString[temp++]=t;
        if(t==32)
        {
            break;
        }
        if (t==13)
        {
            printf("\n");
            break;
        }

    }
    sscanf(tempString,"%d", a);
}

void Scanforminigame2(int a[])
{
    for(int i=0; i<4; i++)
    {
        InputfromConsole(&a[i]);
    }
}

int Minigame2()
{
    PlaySound(TEXT("Resources/UpdateSound/The Power In My Hands (feat Terence Kern).wav"), NULL, SND_LOOP | SND_ASYNC);
    printf("Luật chơi: Hãy nhớ kĩ những số sắp xuất hiện sau đó bạn sẽ phải nhập lại đúng các số đó\nVà một điều quan trọng là bạn chỉ có 10 lần chơi, xin hãy cẩn thận!!!");
    printf("\n---Nhấn phím bất kỳ để bắt đầu chơi---");
    getch();
    int k=10;
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
        printf("Hãy nhập lại 4 số trên theo đúng thứ tự\n");
        Scanforminigame2(b);
        int d=0;
        for (int i=0; i<4; i++)
        {
            if (a[i]!=b[i])
            {
                d++;
                break;
            }
        }
        if (k==0)
        {
            printf("Rất tiếc, bạn đã thua");
            printf("\n---Nhấn phím bất kỳ để quay lại cốt truyện---");
            getch();
            return 0;
        }
        else if (d==0)
        {
            printf("Xin chúc mừng!!! Bạn đã trả lời đúng.");
            printf("\n---Nhấn phím bất kỳ để tiếp tục quay lại cốt truyện---");
            getch();
            return 1;
        }
        else
        {
            printf("Xin lỗi bạn đã trả lời sai. Bạn còn %d mạng", --k);
            printf("\nVui lòng chơi lại.");
            printf("\n---Nhấn phím bất kỳ để chơi lại---");
            getch();
            system("cls");
        }
    }

    return -1;

}

void Day2()
{
    PlaySound(TEXT("Resources/UpdateSound/Lurking.wav"), NULL, SND_LOOP | SND_ASYNC);
    StartConversation("Resources/Character/nam.jpg","Resources/Trinh/day2-1.jpg","","Sáng hôm sau mọi người hoảng hốt khi các thiết bị thông minh kể cả camera an ninh của mọi người đều bị đập hỏng không dùng được, các phương tiện đi lại cũng bị hư hại.");
    StartConversation("Resources/Character/nam.jpg","Resources/Trinh/day2-2.jpg","","Anh Minh quyết định và sửa xe để có thể đưa mọi người ra khỏi đây an toàn. Cả buổi sáng mọi người tâm sự với nhau và giúp đỡ anh Minh sửa xe.");
    StartConversation("Resources/Character/nam.jpg","Resources/Trinh/day2-3.jpg","","Đột nhiên mọi người nghe thấy tiếng giống gầm rú. Anh chị bảo đó là tiếng côn trùng hỗn tạp lại với nhau nhưng Ling lại thấy tiếng đo rất lạ.");
    StartConversation("Resources/Character/nam.jpg","Resources/Trinh/day2-4.jpg","","Mọi người ra ngoài kiểm tra kèm theo vũ khí tự vệ.  Đến nơi phát ra âm thanh to nhất, họ thấy tiếng côn trùng kết hợp lại không thành ra tiếng gì nữa mà chỉ như tiếng côn trùng bình thường.");
    StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-4.1.jpg","","Lại gần cái cây, mọi người thấy có rất nhiều những con côn trùng trên cây và bay xung quanh cây.Ling nói những tiếng tạo ra bởi côn trùng bay khỏi tổ cũng rất đặc biệt, mọi người thấy vậy liền lấy vũ khí ra đập vào cây");
    ls[1]=Minigame1();
    SaveDataArray("ls.txt",ls,6);
    if(ls[1])
    {
        StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-5.jpg","","5 cái ổ côn trùng được bịt có chủ đích bằng các tờ giấy được cuộn lại. Chính cách thông và bịt các đường đi của tổ côn trùng này làm tiếng lạ khi chúng bay ra.");
        StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-6.jpg","","Mọi người về khu kiểm lâm và mở tờ giấy, bất ngờ thay những tờ giấy khi ghép lại tạo thành một đoạn văn gồm x1, x2 ,x3, x4, x5, là “faoijf”, “ipokpq”, “rriqpqrprqr”, “ruqbiqooujffppqfg”,”rrotaphnapbgpajhfwbgkno”.");
        StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-7.jpg","","Những kí tự này liệu đang tồn tại những bí ản kinh khủng thế nào đây S0S S0S S0S??????");
        StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-8.jpg","","Mọi người thấy rằng đây chỉ là những khí tự vô nghĩa. Bế tắc, họ cùng nhau đi ngủ, riêng anh Minh sẽ thức đêm để canh mọi người.");
    }
    else
    {
        StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-8.jpg","","Lũ côn trùng quá hung hãn, mọi người chạy trốn về nhà.Sau đó, họ cùng nhau đi ngủ, riêng anh Minh sẽ thức đêm để canh mọi người.");
    }
    PlaySound(TEXT("Resources/UpdateSound/Guitar On The Water.wav"), NULL, SND_LOOP | SND_ASYNC);
    StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-8.jpg","","Mọi người thấy rằng đây chỉ là những khí tự vô nghĩa. Bế tắc, họ cùng nhau đi ngủ, riêng anh Minh sẽ thức đêm để canh mọi người.");
    StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-9.jpg","","Mọi người lại được phen tá hỏa khi anh Minh bị đánh bất tỉnh, nhưng mọi người đều không bị sao.");
    StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-10.jpg","","Hưng không chịu được quyết định mang vũ khí ra ngoài, mọi người không cản được và bị cuốn theo Hưng, trừ Ling ở lại chăm sóc anh Minh.");
    StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-11.jpg","","Trong lúc mọi người đang cố giữ bình tĩnh cho Hưng thì Ling từ trong nhà hét lên, khiến Hưng lao vút về nhà.");
    StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-12.jpg","","Nhưng xông vào nhà thì lại không thấy kẻ lạ mặt đâu, Ling nói hắn đang định phá tủ ở kia, khi nghe thấy tiếng động của mọi người lập tức rồi đi.  Ngay sau đó, anh Minh đã tỉnh lại, anh nói rằng mình bị đánh lén vào đầu nên bất tỉnh.");
    StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-13.jpg","","Anh đưa chìa khóa tủ cho mọi người và nói trong tủ đấy chính là bẫy động vật anh tự làm nhưng chưa hoàn thành.");
    StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-14.jpg","","Hưng cùng với anh Minh với sự sáng tạo đã hoàn thành và cải tiến cái bẫy. Hưng nói hắn muốn lấy cái bẫy chắc chắn do không muốn mọi người có cơ hội được sử dụng bẫy");
    StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-15.jpg","","Mọi người quyết định sẽ đặt bẫy này vào tối nay.");
    StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-16.jpg","","Mọi người vừa lên giường thì nghe thấy tiếng leng keng xung quanh ở ngoài lúc đi xa lúc đến gân. Tự nhiên “Choang” một cái – cái bẫy đã bắt được con gì đó.");
    StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-17.jpg","","Họ ra ngoài kiểm tra và biết được đấy là con chó hoang được đeo chiếc chuông ở chân, cổ và tay. Ling và Hiền cố giỗ con chó để nó bình tĩnh nhưng không được.");
    ls[2]=Minigame2();
    SaveDataArray("ls.txt",ls,6);
    if(ls[2])
    {
        StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-18.jpg","","Hưng bất ngờ đè con chó xuống rồi lấy những chiếng chuông đi, sau đó đuổi con chó. Trong chuông mọi người phát hiện được 3 mảnh giấy khi ghép lại ra các gợi ý còn lại x6, x8, x10 lần lượt là “59”, “57931084”,”263930”.");
        StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-19.jpg","","Lại là những kí tự trông vô nghĩa nhưng đầy mờ ám và nguy hiểm");
        StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-20.jpg","","Nhưng cũng như trước, đó lại là những kỹ tự vô nghĩa, khác cái nó là số. Mọi người cũng lười không phân tích và đi ngủ, Nam và Hưng sẽ canh chừng mọi người.");
    }
    else
    {
        PlaySound(TEXT("Resources/UpdateSound/Evans.wav"), NULL, SND_LOOP | SND_ASYNC);
        StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-18.1.jpg","","Con chó vùng vẫy quá mạnh, mọi người không thể giữ được nó chạy vụt ra ngoài rồi biến mất");
        StartConversation("Resources/Character/hung.jpg","Resources/Trinh/day2-20.jpg","","Sau đó, mọi người bàn luận rồi ai về phòng đấy ngủ, Nam và Hưng sẽ canh chừng mọi người.");
    }


}
void Day3()
{
    PlaySound(TEXT("Resources/UpdateSound/Evans.wav"), NULL, SND_LOOP | SND_ASYNC);
    StartConversation("", "Resources/Para3_image1.jpg", "", "Không như những hôm trước, đêm qua êm đềm mà không có gì lạ diễn ra. Mọi người cùng nhau chuẩn bị vào buổi sáng trong khi Nam và Hưng đi ngủ.");
    StartConversation("", "Resources/Para3_image2.jpg", "", " Đến chiều, mọi người nhận được tin vui khi xe sắp hoàn thành việc sửa chữa và mọi người có thể an tâm rời khỏi đây trong chiều mai. Mọi người ai cũng vui sướng và mong chờ qua ngày hôm nay.");
    StartConversation("", "Resources/Para3_image3.jpg", "", "Khi Ling đi vệ sinh xong, vừa bước ra ngoài thì đột nhiên đụng mặt kẻ lạ mặt đối mặt. Ling đứng sở ra nhìn hắn, hắn không định làm gì Ling, nhưng đe dọa Ling rằng “Nếu mày và nhóm mày tiếp tục đi xa hơn, thì mọi chuyện sẽ không còn đơn giản là bị phá hoại nữa đâu”, rồi hắn biến mất.");
    StartConversation("", "Resources/Para3_image4.jpg", "", " Ling quá sợ hãi rồi ngất đi. Khi tỉnh lại thì thấy mọi người đang chăm sóc Ling.");
    StartConversation("", "Resources/Para3_image5.jpg", "", "Sau khi nghe toàn bộ mọi chuyện, Nam nói rằng mình phải tìm được manh mối cuối cùng là x7 trước khi rời khỏi đây, vì hắn sẽ cố gắng thủ tiêu manh mối cuối cùng đó. Ling đồng ý và nói rằng rất có thể manh mối cuối cùng liên quan tới cái đèn nhấp nháy.");
    StartConversation("", "Resources/Para3_image6.jpg", "", "Vừa dứt lời thì đèn phòng nhấp nháy thật và nhấp nháy rất lạ, có vẻ có quy luật riêng.");
    StartQuestion("","Nhớ thêm ảnh câu hỏi ra x7","","Đèn nhấp nháy như là biểu thị: -..- --... ; Mã trên có 1 nghĩa gì\n\t1. x7 2. x10 3. x11 4.x12 ",1);
    StartConversation("","Nhớ thêm ảnh mọi người nhình thấy hộp điện bị khóa","","Mọi người đến chỗ khu điều khiển điện để kiểm tra. Anh Minh và chị Ngân bất ngời khi các mạch điều khiển bị khóa bằng mật khẩu, để mở phải nhập đúng mật khẩu");
    ls[3]=CalculusQuiz();
    SaveDataArray("ls.txt",ls,6);
    if(ls[3])
    {
        StartConversation("", "Resources/Para3_image8.jpg", "", "Là sinh viên khá trong lập trình Adruno, Ling nó rằng để có thể lên được các tín hiện như vậy, thì phải lập trình cho mạnh tự động rất phức tạp. Vì thế Ling cùng mọi người ra khu điều khiển điện.");
        StartConversation("", "Resources/Para3_image9.jpg", "", "Và thấy rằng bảng điện bị nối thêm 1 mạch Adruno, thậm chí nó có cả màn hình hiện lên các lệnh lập trình đấy.");
        StartConversation("", "Resources/Para3_image10.jpg", "", "Hưng và Ling ghi bắt đầu nghiên cứu. Kéo đến cuối họ thấy comment của hàm “ for(int i=0;i<INT.MAX;i++) printf(“45”); “ được lặp lại nhiều lần, có vẻ như người viết muốn mọi người để ý đến số 45, nên rất có thể x7=”45”.");
        StartConversation("", "Resources/Para3_image11.jpg", "", "Hưng nói rằng trong cặp Ling có sách “300 bài code thiếu nhi” và sẽ cố gắng nghiên với các manh mối từ anh chị kiểm lâm đưa với manh mối tìm được. Ling không hiểu sao trong cặp mình lại có cuốn sách đấy, nên chắc là do để quên.");
        StartConversation("", "Resources/Para3_image12.jpg", "", "Hưng và anh Hiền quyết định sẽ canh mọi người ngủ tối nay, anh Minh sẽ nghỉ ngơi để có thể đưa mọi người rời đi vào sáng mai, sau đó sẽ báo cảnh sát về những gì tìm được. ");
        ls[4]=PrintfQuiz();
        SaveDataArray("ls.txt",ls,6);
        if(ls[4])
        {
            if(ls[0]+ls[1]+ls[2]>=3)
            {
                StartConversation("", "Resources/Para3_image13.jpg", "", "Sáng dậy, Ling sốc nặng khi thấy cảnh tượng kinh hoàng, tất cả mọi người đều bị đánh vào đầu bất tỉnh, còn Nam bị đánh nhẹ sau đó giả vờ ngất nên tỉnh trước Ling, nhưng Ling thì bình an vô sự.");
                StartConversation("", "Resources/Para3_image14.jpg", "", "Nghiêm trọng hơn, Hưng đã bị chém chết.");
                StartConversation("", "Resources/Para3_image15.jpg", "", "Ling trách mình vì đã không nghe lời tên lạ mặt, Nam động viện Ling, nói rằng dù gì chuyện đã xảy ra, nên bây giờ hãy chăm sóc mọi người trước đã.");
                StartConversation("", "Resources/Para3_image16.jpg", "", "Trong lúc dìu xác của Hưng 2, người thấy cuốn sách được bôi đỏ bằng máu, đó là bảng mã ASCII và chương 1 của printf() .Sau một hồi đọc, họ hiểu được hàm ý Hưng để lại, đó chính là hàm trả về của printf(), ghép lại ra được 1220253948020. Nam đột nhiên nhớ ra số 45 rất quan trọng, và thay nó bằng mã ASCII, thì sẽ được 122025-948020.");
                StartConversation("", "Resources/Para3_image17.jpg", "", "Trước khi chết, Hưng còn để lại lời nhắn chữ “MAP” ở dưới bàn, có thể nó chính là tọa độ bản đồ. Họ đối chiếu với bản đồ khu vực và nhận ra đấy là số 122.025-9.28020 trên bản đồ.");
                StartConversation("", "Resources/Para3_image18.jpg", "", "Nam và Ling quyết định đi ra khu vực được đánh mốc đấy. Ra đến nơi, đó là khu vực vách núi dốc.");
                StartConversation("", "Resources/Para3_image19.jpg", "", "Đột nhiên Ling bị đẩy lăn xuống vách núi.");
                StartConversation("", "Resources/Para3_image20.jpg", "", "Ling cố gắng đứng dậy nghỉ ngơi và chui vào hốc núi nằm xuống.");
                StartConversation("", "Resources/Para3_image21.jpg", "", "Lúc nằm xuống Ling bất ngờ phát hiện nằm bên cạnh mình là Nam. Nhưng không phải là Nam như lúc đầu, đó là xác của Nam. Ling giật mình chạy ra khỏi hang.");
                StartConversation("", "Resources/Para3_image22.jpg", "", "Giật mình bất thình lình lần hai, trước cửa hang chí là kẻ lạ mặt. Hắn nhìn Ling, bắt đầu cởi mũ và khẩu trang, và lộ mặt; hắn là con gái !!!. Hắn kể lại mọi chuyện, và điều đó khiến Ling nhớ lại mọi chuyện trước khi xảy ra tai nạn:");
                gameData++;
                SaveData("GameData.txt",gameData);
            }
            else
            {
                //Đoạn này dù Hưng có giải được printf nhưng các manh mối ở trên không thu được nên không thể để Ling biết được tọa độ, sau đó sáng mn bị xiên all, Ling biến mất bí ẩn
            }

        }
        else
        {
            //Đoạn này là bị xiên all rồi Ling biến mất bí ẩn, thêm ảnh và hội thoại
        }
    }
    else
    {
        //Đoạn này là mở khóa không thành công, mọi người đi ngủ, sáng dậy mn đi về mang manh mối đi báo cảnh sát thì kẻ lạ mặt xuất hiện sau xe gây ra tai nạn
    }


}

void PartOne()
{
    PlaySound(TEXT("Resources/UpdateSound/Shenanigans_.wav"), NULL, SND_LOOP | SND_ASYNC);
    StartConversation("","Resources/image/image_1.jpg","","Ling là một học sinh chăm chỉ học ở 1 trường Đại Học danh giá.");
    StartConversation("","Resources/image/image_2.jpg","","Sau 1 buổi đi chơi cùng với gia đình ở 1 vùng núi rừng");
    StartConversation("","Resources/image/image_3.jpg","","Gia đình Ling đã gặp nạn sau 1 vụ sạt lở. Tai nạn khiến bố mẹ Ling thiệt mạng, Ling bị hôn mê và 1 người không rõ danh tính đi với gia đình.");
    StartConversation("","Resources/image/image_4.jpg","","Sau khi tỉnh lại, Ling luôn cảm thấy có gì đó uẩn khúc trong vụ tai nạn này nên quyết định quay lại nơi xảy ra tai nạn để điều tra");
    StartConversation("","Resources/image/image_5.jpg","",".Đi cùng Ling gồm bạn Nam, Hưng, và Hiền. Họ gọi cho đội kiểm lâm ở khu rừng và quyết định ở lại khu kiểm lâm 1 tuần để cùng Ling đi điều tra dưới danh nghĩa là sinh viên tình nguyện.");
    StartConversation("","Resources/image/image_6.jpg","","Đến khu kiểm lâm, nhóm được quản lý và ở tại 1 khu riêng. Người quản lý nhóm gồm chị Ngân và anh Minh");
    StartConversation("","Resources/image/image_7.jpg","","Vào buổi đêm trong lúc nhóm nghỉ ngơi tâm sự, anh chị kể rằng, từ lúc gia đình Linh xảy ra tai nạn ở đây xuất hiện rất nhiều hiện tượng lạ như tiếng ai đó gào vào buổi đêm, tiếng leng keng xung quanh khu kiểm, đèn bị nhấp nháy bất thường. Mọi người nghe xong rợi hết cả tóc gáy và quyết định tối mai sẽ đi điều tra.");
    StartConversation("","Resources/image/image_8.jpg","","Sau khi nhóm chấn tĩnh lại, chị Ngân nói rằng nạn nhân trước khi gặp nạn ở vụ sạt lở để lại 1 lời nhắn, chị đã kịp chụp trước khi đưa cho cảnh sát rồi để mọi người xem, hiện giờ không biết lời nhắn đó là của ai trong vụ tai nạn và nó có ý nghĩa gì. Lời nhắn đó là “ printf(“%s”, x1); printf(“%s”, x2); printf(“%s”, x3); printf(“%s”, x4); printf(“%s”, x5); printf(“%s”, x6); printf(“%s”, x7); printf(“%s”, x8); printf(“%s”, x9); printf(“%s”, x10); ”");
    StartConversation("","Resources/image/image_9.jpg","","Sáng hôm sau khi mọi người tỉnh dậy, nhóm được các anh chị kiểm lâm nấu ăn sáng và không bắt dậy sớm vì thấy nhóm hôm qua đã mệt và bị anh chị dọa hơi quá");
    StartConversation("","Resources/image/image_10.jpg","",". Sau khi nhóm chấn tĩnh lại, chị Ngân nói rằng nạn nhân trước khi gặp nạn ở vụ sạt lở để lại 1 lời nhắn, chị đã kịp chụp trước khi đưa cho cảnh sát rồi để mọi người xem, hiện giờ không biết lời nhắn đó là của ai trong vụ tai nạn và nó có ý nghĩa gì. Lời nhắn đó là“ printf(“%s”, x1); printf(“%s”, x2); printf(“%s”, x3); printf(“%s”, x4); printf(“%s”, x5); printf(“%s”, x6); printf(“%s”, x7); printf(“%s”, x8); printf(“%s”, x9); printf(“%s”, x10); ”  Có vẻ nạn nhân là người thích lập trình, mà cả gia đình đều theo khuynh hướng lập trình nên không biết ai thật.");
    StartConversation("","Resources/image/image_11.jpg","","Một trong những điều đó là những cái đinh xuất hiện bất thường ở khu rừng keo gần đây.");
    StartConversation("","Resources/image/image_12.jpg","","Đến buổi chiều được nghỉ ngơi, nhóm quay lại khu rừng keo và ghi lại chi tiết những bất thường ở đây. Ling lúc đến khu này luôn cảm thấy lạnh lạnh như bị ai đang theo dõi nên lúc nào cũng phải rúc vào đi gần ai đó.");
    StartConversation("","Resources/image/image_13.jpg","","Sau đó, nhóm cùng nhau về nơi nghỉ ngơi và phân tích. Sau 1 hồi phân tích, họ thấy các vị trí đóng đinh hao hao giống x9.");
    StartConversation("","Resources/image/image_14.jpg","","Mọi người mừng rỡ vì tìm thấy manh mối, nhưng dần cũng đi vào bế tắc và chán nản. Sau một lúc lâu không có kết quả mọi người quyết định đi ngủ và để đến mai.");
    StartConversation("","Resources/image/image_15.jpg","","Mặc dù đi ngủ nhưng ở trong chăn, Ling vẫn đang bấm điện thoại.");
    StartConversation("","Resources/image/image_16.jpg","","Tình cờ khi Ling vào chơi cờ vua, Linh thấy được số lượng cái đinh ở trên mỗi cây và màu sắc của đinh tượng trưng cho các quân cờ.");
    ls[0]=ChessQuiz();
    SaveDataArray("ls.txt",ls,6);
    PlaySound(TEXT("Resources/UpdateSound/Lurking.wav"), NULL, SND_LOOP | SND_ASYNC);
    switch(ls[0])
    {
    case 1:
        StartConversation("","Resources/image/image_17.jpg","","Sau 1 hồi giải các thế cờ, Ling nhận thấy chỉ cần đi 2 nước là Nbd2 và Hd4xTa4 là có thể chiếu hết vua đen dù đen có đi nước nào chăng nữa, từ đó suy ra có thể x9 = ”Nb2d2 Hd4xTa4”.");
        StartConversation("","Resources/image/image_18.jpg","","Ling đang vui sướng thì cửa sổ đột nhiên bật ra và có bóng người đen hiện sau cửa sổ. Quá sợ, Ling hét lên khiến mọi người giật mình.");
        break;
    case 0:
        StartConversation("","Resources/image/image_18.jpg","","Cửa sổ đột nhiên bật ra và có bóng người đen hiện sau cửa sổ. Quá sợ, Ling hét lên khiến mọi người giật mình.");
        break;
    }
    StartConversation("","Resources/image/image_19.jpg","","Linh ấp úng nói có ai đó ở ngoài, và chui vào chăng của Hưng, anh Minh đi ra ngoài kiểm tra nhưng không thấy ai. Linh nó rằng tên đó mặc áo hoodie đen, luôn trùm đầu bằng mũ của áo và đeo và đeo khẩu trang đen");
    StartConversation("","Resources/image/image_20.jpg","","Sau đó Linh kể hết cho mọi người đầu đuôi câu chuyện, mọi người dỗ Linh sau đó đi ngủ.");
}

void End()
{
    PlaySound(TEXT("Resources/UpdateSound/Death.wav"), NULL, SND_LOOP | SND_ASYNC);
    int r1[2]= {1,2},r;
    r=StartSelection("","","","Nếu bạn là Hiền, người bị mất người bạn thân là Hưng và bị giết bởi chính tay Ling, bạn nghĩ sao về Ling:\n\t1.Ling con độc ác máu lạnh, không xứng đáng được làm người/n/t2.Ling là người chụi nhiều quá khứ đau khổ, nên không thể trách Ling tất cả được",r1,2);
    if(r==1)
    {
        switch(StartSelection("","","","Bạn sẽ nói Ling như thế nào:\n\t1.Nói bóng gió Ling\n\t2.Chửi thẳng vào mặt Ling",r1,2))
        {
        case 1:
            End1_2();
            break;
        case 2:
            End1_1();
            break;
        }
    }
    else
    {
        switch(StartSelection("","","","Bạn sẽ nói Ling như thế nào:\n\t1.Bạn sẽ động viên Ling và hứa sẽ giúp đỡ Ling\n\t2.Nhìn Ling và rời đi vì thất vọng",r1,2))
        {
        case 1:
            End2_1();
            break;
        case 2:
            End2_2();
            break;
        }
    }


}


void End1_1()
{
    StartConversation("","Resources/Ending/End1/3.jpg","","Ling nhớ lại lời nói của kẻ lạ mặt, xã hội này vốn tàn nhẫn, mặc dù biết tình trạng của Ling nhưng lại không hề thông cảm cho Ling.\n\tLing nhìn về tương lai mờ mịt không lối thoát, nhìn hiện tại không còn gì để mất.");
    StartConversation("","Resources/Ending/End1/4.jpg","","Trong lúc Y tá không để ý, Ling thoát ra và chạy trốn.");
    StartConversation("","Resources/Ending/End1/7.jpg","","Ling muốn đến một nơi mà không ai biết mình, một nơi mà Ling sẽ được sống một cách bình thường. Nhưng cuộc chạy trốn thất bại, Ling bị bắt về viện.");
    StartConversation("","Resources/Ending/End1/8.jpg","","Ling thấy rằng mình không thể sống ở xã hội này được, nên đã nhân lúc y tá không để ý lần nữa nên đã tự giải thoát chính mình ở tầng 26 của bệnh viện.");

}
void End1_2()
{
    StartConversation("","Resources/Ending/End1/3.jpg","","Ling nhớ lại lời nói của kẻ lạ mặt, xã hội này vốn tàn nhẫn, mặc dù biết tình trạng của Ling nhưng lại không hề thông cảm cho Ling.\n\tLing nhìn về tương lai mờ mịt không lối thoát, nhìn hiện tại không còn gì để mất.");
    StartConversation("","Resources/Ending/End1/4.jpg","","Vì vửa nãy Hiền chửi Ling nên Ling rất cay.\n\tTrong lúc Y tá không để ý, Ling thoát ra và đánh ngất y tá rồi chạy trốn.");
    StartConversation("","Resources/Ending/End1/5.jpg","","Ling đến chỗ của Hiền, trước khi thanh toán Hiền, sắc mặt Ling không khác gì kẻ lạ mặt và giảng lại đạo lý cho chính Hiền.");
    StartConversation("","Resources/Ending/End1/6.jpg","","Sau đó đi thanh toán những người đã khiến Ling phải chịu khổ trong quá khứ một cách không thương tiếc.");
    StartConversation("","Resources/Ending/End1/8.jpg","","Biết hành động của mình sẽ không thể tha thứ, Ling nhảy lầu giải thoát mình khỏi xã hội này. Khác với những lần trước, lần nay Ling đã thực sự chết.");
}

void End2_1()
{
    StartConversation("","Resources/Ending/End2/2.1.1.jpg","","Sau khi bác sĩ rời đi, Hiền ở lại động viên thấu hiểu Ling. Ling nhớ lại câu nói của Nam hãy tiếp tục sống, tiếp tục cố gắng dù có thế nào.");
    StartConversation("","Resources/Ending/End2/2.1.2.jpg","","Với sự giúp đỡ của Hiền, Ling dần bình thường lại và được xuất viện, hòa nhập với mọi người.");
}
void End2_2()
{
    StartConversation("","Resources/Ending/End2/2.1.3.jpg","","Sau khi bác sĩ rời đi, Hiền ở lại nhưng chỉ nói có vài câu động viên lấy lẹ rồi cũng rời đi.\n\tLing hiểu nỗi đau của Hiền trong mắt của Ling nên không có phản ứng gì.");
    StartConversation("","Resources/Ending/End2/2.2.1.jpg","","Sau khi điều trị thành công, Ling trở về nhà. Mặc dù cố gắng tiếp tục sống, nhưng cuộc sống quá khó khăn vì mọi người không ai chấp nhận quá khứ của Ling.");
    StartConversation("","Resources/Ending/End2/2.2.2.jpg","","Không còn gì cả, không bạn bè, tiền bạc, cuộc sống khó khăn áp lực vất vả.");
    StartConversation("","Resources/Ending/End2/2.2.3.jpg","","Ling tìm kiếm cái sự giải thoát cho mình bằng một sợi dây. ");
}

void phase4()
{
    PlaySound(TEXT("Resources/UpdateSound/Doll Dance.wav"), NULL, SND_LOOP | SND_ASYNC);
    StartConversation("","Resources/Nam/1.jpg","","Vào ngày đẹp, gia đình Ling quyết định tổ chức đi chơi cùng với người yêu của Ling, chính là Nam");
    StartConversation("","Resources/Nam/2.jpg","","Những ngày đi chơi diễn ra suôn sẻ, vui vẻ của Ling tự nhiên như biến mất sau 1 đêm. Ling trở nên cáu gắt, khó ở, hay hạch sách Nam.");
    StartConversation("","Resources/Nam/3.jpg","","Nam cũng hiểu tình trạng bệnh của Ling, nên cố giữ bình tĩnh và động viên Ling, Nam biết Ling bây giờ không còn là Ling nữa. Nam cố gắng hòa đồng với Ling, nhằm có thể hòa đồng với Ling lúc này. ");
    StartConversation("","Resources/Nam/4.jpg","","Nhưng mọi chuyện dần đi quá xa, Ling bắt đầu đổ lỗi cho Nam không yêu mình nữa, không còn quan tâm nữa. Sau đó đổ tội cho Nam cắm sừng Ling, đưa những lời miệt thị với Nam.Dù vậy Nam vẫn bình tĩnh rồi để Ling một mình nhằm cho Ling chấn tĩnh lại ");
    StartConversation("","Resources/Nam/5.jpg","","Nhưng chuyện không ngờ đã xảy ra Ling đã bất ngờ đâm Nam.");
    StartConversation("","Resources/Nam/6.jpg","","Biết là Ling không còn bình tĩnh được,Nam chạy cắt và cắt đuôi được Ling.");
    StartConversation("","Resources/Nam/7.jpg","","Sau đó đặt ra những ký hiệu gợi ý ở các khu rừng rồi chui vào 1 cái hang dưới vách núi rồi bắt đầu gọi cứu hộ.");
    StartConversation("","Resources/Nam/8.jpg","","Nhưng điều Nam không ngờ tới là Ling bám theo vết máu và đã tìm ra Nam. ");
    StartConversation("","Resources/Nam/9.jpg","","Trong cơ giận dữ, Ling giết luôn Nam một cách dã man. ");
    StartConversation("","Resources/Nam/10.jpg","","Sau một lúc, Ling đột nhiên như trở lại, thấy những gì mình đã, quá sợ hãi, ");
    StartConversation("","Resources/Nam/11.jpg","","Ling chạy đi mà không biết đi đâu trong cơn mưa lớn. ");
    StartConversation("","Resources/Nam/12.jpg","","Bất ngờ gặp bố mẹ Ling.Thấy bộ dang của Ling, bố mẹ Ling sợ hãi và hỏi Ling ổn không.");
    StartConversation("","Resources/Nam/13.jpg","","Ling không nói gì mà trèo lên vách núi gần đó. ");
    StartConversation("","Resources/Nam/14.jpg","","Vừa trèo lên xong, vách núi sạt lở, chôn vùi bố mẹ Ling và khiến họ thiệt mạng. Ling ở trên đầu cũng bị cuốn đi.");
    StartConversation("","Resources/Nam/15.jpg","","Mặc dù không nghiêm trọng như bố mẹ nhưng Ling vẫn bị bất tỉnh");
    StartConversation("Resources/Nam/16.1.jpg","Resources/16.jpg","Người lạ mặt","Ling hoàng hồn hỏi người lạ mặt là ai, hỏi tại sao lại biết mọi chuyện. Hắn nói không quan trọng, nhiện vụ của hắn là bảo vệ Ling khỏi sự thật động trờ đó, bây giờ chỉ cần rời khỏi đây và sẽ sống một cuộc sống của người bình thường. Nếu không, Ling sẽ bị mọi người đánh giá, bị xã hội bỏ rơi, xa lánh. Hắn nói về xã hội “Xã hội này rất tàn nhẫn, nó sẽ dùng quá khứ để phán xét và vùi dập bạn cho dù hiện tại bạn có tốt thế nào chăng nữa”. Vì thế cần giấu nghẹm bí mật này đi, và Ling sẽ được sống một cuộc sống bình thường. Ling lưỡng lự định rời đi theo hắn nhưng đột nhiên Nam xuất hiện sau hắn.");
    StartConversation("Resources/Nam/17.1.jpg","Resources/17.jpg","Nam","Nam ngăn Ling rời đi và nói rằng tốt nhất hãy chấp nhận sự thật: “Xã hội này vốn tàn nhẫn, và chúng ta phải chấp nhận sống chung với nó”. Nam nói rằng Ling phải chấp nhận bản thân, dù gì sớm hay muộn mọi người cũng sẽ biết được sự thật. Và quan trọng hơn, mọi người biết được tình trạng của Ling và sẽ thông cảm cho Ling. Hai người cãi nhau nảy lửa và càng ngày càng gay gắt.");
    StartConversation("","Resources/Nam/18.jpg","","Quá sốc và áp lực, Ling bất ngờ ngất đi  trước sự ngỡ ngàng của 2 người.");
    StartConversation("","Resources/Nam/19.jpg","","Ling tỉnh dậy, bác sĩ vui mừng báo cho mọi người. Mọi người nói Ling đã hôn mê được vài ngày rồi.");
    StartConversation("","Resources/Nam/20.jpg","","Ling lúc này đã nhớ mọi thứ thứ nên xin lỗi mọi người, cảm ơn mọi người đã cứu mình khi gặp nạn.");
    StartConversation("","Resources/Nam/21.jpg","","Bác sĩ dặn dò mọi người, trước khi rời đi, trong đó hãy nhẹ nhàng với Ling vì Ling đã trải qua quá nhiều cú sốc.");
}

int ChessQuiz()
{
    PlaySound(TEXT("Resources/UpdateSound/Magical.wav"), NULL, SND_LOOP | SND_ASYNC);
    cleardevice();
    readimagefile("Resources/chess/chess1.jpg",400,0,900,400);
    system("cls");
    printf("\n\tĐi nước nào để có thể chiếu hết nhỉ\n\t 1.Hxf6+(Hậu trắng ăn mã đen) \t 2.Xc1(Xe trắng chồng quân với hậu) \t3.h3(Lên tốt ở góc đuổi hậu đi) \t4.Mbd2(chuyển mã ra giữa bàn cờ)\n");
    printf("\tNhập nước bạn muốn đi: ");
    char ip=(char)getch();
    printf("%c",ip);
    delay(500);
    int attemp=0;
    while(ip!='1')
    {
        system("cls");
        attemp++;
        if(attemp==3)
            return 0;
        printf("Hmm, hình như không phải, vậy phải đi nước nào nhỉ\n\t1.Hxf6+(Hậu trắng ăn mã đen) \t2.Xc1(Xe trắng chồng quân với hậu) \t3.h3(Lên tốt ở góc đuổi hậu đi) \t4.Mbd2(chuyển mã ra giữa bàn cờ)\n\tNhập nước bạn muốn đi: ");
        ip=(char)getch();
        printf("%c",ip);
        delay(500);
    }

    system("cls");
    cleardevice();
    readimagefile("Resources/chess/chess1.1.jpg",400,0,900,400);
    delay(1000);
    cleardevice();
    readimagefile("Resources/chess/chess1.2.jpg",400,0,900,400);
    printf("\n\tẤn phím bất kỳ để tiếp tục");
    getch();
    system("cls");
    printf("\n\Hình như đúng rồi này, chỉ cần 1 nước nữa là chiếu hết\n\t1.Xc1(xe ra hàng thứ 3) \t2.h3(lên tốt đuổi hậu đi) \t3.Txf6(Tượng trắng ở ô đen ăn tốt) \t4.Tc6(Tượng trắng ở ô trắng lên hàng ngang thứ 6 thí tượng)\n");
    printf("Nhập nước bạn muốn đi: ");

    ip=(char)getch();
    printf("%c",ip);
    delay(500);
    attemp=0;
    while(ip!='3')
    {
        system("cls");
        attemp++;
        if(attemp==3)
            return 0;
        printf("Hmm, hình như không phải, vậy phải đi nước nào nhỉ\n\t1.Xc1(xe ra hàng thứ 3) \t2.h3(lên tốt đuổi hậu đi) \t3.Txf6(Tượng trắng ở ô đen ăn tốt) \t4.Tc6(Tượng trắng ở ô trắng lên hàng ngang thứ 6 thí tượng)\n\tNhập nước bạn muốn đi: ");
        ip=(char)getch();
        printf("%c",ip);
        delay(500);
    }

    readimagefile("Resources/chess/chess1.3.jpg",400,0,900,400);


    printf("\n\tYeah mình chiếu hết rồi!!!\nẤn phím bất kỳ để tiếp tục");
    getch();
    return 1;

}

int Minigame1()
{
    PlaySound(TEXT("Resources/UpdateSound/Fight On.wav"), NULL, SND_LOOP | SND_ASYNC);
    FILE *f;
    FILE *fd;
    fd=fopen("Dapan.txt","r");
    int *a;
    a=(int*)malloc(12*sizeof(int));
    for(int i=0; i<12; i++)
    {
        fscanf(fd,"%d",&a[i]);
    }
    f=fopen("Cauhoi.txt","r");
    char s[12][40];
    StartConversation("Resources/nam.jpg","Resources/Trinh/day2minigame1-1.jpg","","Hãy vượt qua thử thách để đuổi lũ côn trùng đi!!!");
    int i;
    int n;
    int t;
    int mat=0;
    for (i=0; i<12; i++)
    {
        fscanf(f,"%s",s+i);
    }
    int b[50];
    randomAnswer(b);
    for(i=0; i<5; i++)
    {
        printf("Câu hỏi %d:%s\n",i+1,s[b[i]]);
        printf("Câu trả lời:");
        n=input();
        if(n==a[b[i]])
        {
            mat++;
            if(t!=mat)
            {
                if(mat==1)
                {
                    StartAnswer("Resources/nam.jpg","Resources/Trinh/day2minigame1-4.jpg","","");
                }
                if(mat==2)
                {
                    StartAnswer("Resources/nam.jpg","Resources/Trinh/day2minigame1-5.jpg","","");
                }
                if(mat==3)
                {
                    StartAnswer("Resources/nam.jpg","Resources/Trinh/day2minigame1-6.jpg","","");
                }
                if(mat==4)
                {
                    StartAnswer("Resources/nam.jpg","Resources/Trinh/day2minigame1-7.jpg","","");
                }
                if(mat==5)
                {
                    StartAnswer("Resources/nam.jpg","Resources/Trinh/day2minigame1-7.jpg","","");
                }
                t=mat;
            }
        }
    }
    fclose(f);
    fclose(fd);
    free(a);
    if(mat==5)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int CalculusQuiz()
{
    cleardevice();
    readimagefile("Resources/chess/matkhau.jpg",50,0,1230,400);
    system("cls");
    printf("\nNhâp mật khẩu từ bàn phím, mật khẩu chỉ có 1 chữ số: ");
    int x=getch();
    int attemp=5;
    while(x!=(int)'0')
    {
        system("cls");
        attemp--;
        if(attemp<=0)
        {
            return 0;
        }
        printf("Mật khẩu sai, bạn còn %d lần thử, mời bạn nhập lại: ",attemp);
        x=getch();
        printf("%c",(char)x);
        delay(500);
    }
    if(attemp<7)
    {
        system("cls");
        printf("Đáp án đúng rồi chúc mừng bạn");
        return 1;
    }
}

int PrintfQuiz()
{
    cleardevice();
    readimagefile("Resources/chess/printfQuest.jpg",50,0,1230,400);
    system("cls");
    printf("\nHàm printf trả về gì: \n0. Không trả về gì cả\t1. Trả về số kí tự trong dấu ngoặc\t3. Trả về 1 nếu in ra thành công và 0 nếu thất bại\t4. Trả về về số ký tự được viết lên màn hình\n");
    printf("Nhập câu trả lời: ");
    int x=getch();
    int attemp=2;
    while(x!=(int)'4')
    {
        system("cls");
        attemp--;
        if(attemp<=0)
        {
            return 0;
        }
        printf("Hmm, hình như không phải, trả về gì nhỉ: \n0. Không trả về gì cả\t1. Trả về số kí tự trong dấu ngoặc\t3. Trả về 1 nếu in ra thành công và 0 nếu thất bại\t4. Trả về về số ký tự được viết lên màn hình");
        printf("Nhập câu trả lời: ");
        x=getch();
        printf("%c",(char)x);
        delay(500);
    }

    return 1;
}









