#include <stdio.h>

typedef struct
{
    char name[20];
    int vote;
}candidate;

int compare(char* s1,char* s2)
{
    int index=0;
    while(s1[index]!='\0'||s2[index]!='\0')
    {
        if(s1[index]!=s2[index]) return 0;
        ++index;
    }
    return 1;
}

int main(void)
{
    candidate can[3];
    for(int i=0;i<3;++i)
    {
        scanf("%s",can[i].name);
        can[i].vote=0;
    }
    for(int i=0;i<6;++i)
    {
        char name[20]={};
        scanf("%s",name);
        for(int j=0;j<3;++j)
            if(compare(name,can[j].name))
                can[j].vote++;
    }
    for(int i=0;i<3;++i)
        printf("%s %d\n",can[i].name,can[i].vote);
    int best=0;
    for(int i=1;i<3;++i)
        if(can[i].vote>can[best].vote)
            best=i;
    printf("\n%s : %d is first\n",can[best].name,can[best].vote);
    return 0;
}