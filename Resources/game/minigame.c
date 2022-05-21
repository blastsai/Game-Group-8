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
//thêm vào main
int minigame1()
{
    FILE *f;
    FILE *fd;
    fd=fopen("Dapan.txt","r");
    int *a;
    a=(int*)malloc(12*sizeof(int));
    for(int i=0;i<12;i++)
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
        for(i=0;i<5;i++)
        {
            printf("Câu hỏi %d:%s\n",i+1,s[b[i]]);
            printf("Câu trả lời:");
            n=input();
            if(n==a[b[i]])
            {
                mat++;
                if(t!=mat){
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

