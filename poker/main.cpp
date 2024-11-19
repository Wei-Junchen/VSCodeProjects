#include <iostream>
#include <time.h>
#include <stdlib.h>
#define MOD 25
#define LEAST 7
using namespace std;

struct card
{
    int index;  
    string num;
    card* prev;
    card* next; 
};

card* generateCards(void)
{
    card* cards=new card;
    card* head=cards;
    cards->prev=nullptr;
    cards->next=nullptr;
    for(int i=1;i<=13;++i)
    {
        for(int j=0;j<4;++j)
        {
            cards->index=i;
            if(i==8)
            {
                cards->num="10";
                cards->next=new card;
                (cards->next)->prev=cards;
            }
            else if(i==9)
            {           
                cards->num="J";
                cards->next=new card;
                (cards->next)->prev=cards;
            }
            else if(i==10)
            {
                cards->num="Q";
                cards->next=new card;
                (cards->next)->prev=cards;
            }
            else if(i==11)
            {
                cards->num="K";
                cards->next=new card;
                (cards->next)->prev=cards;
            }
            else if(i==12)
            {   
                cards->num="A";
                cards->next=new card;
                (cards->next)->prev=cards;
            } 
            else if(i==13)
            {
                cards->num="2";
                cards->next=new card;
                (cards->next)->prev=cards;
            }
            else
            {
                cards->num=to_string(i+2);
                cards->next=new card;
                (cards->next)->prev=cards;
            }
            cards=cards->next;
        }
    }
    cards->index=14;
    cards->num="sJ";
    cards->next=new card;
    (cards->next)->prev=cards;
    cards=cards->next;
    cards->index=15;
    cards->num="BJ";
    cards->next=head;
    head->prev=cards;
    return head;
}

card* deck[3][20];
int length[3]={-1,-1,-1};

void insertDeck(card* card,int group)//group:0,1,2
{
    if(length[group]==-1)
    {
        ++length[group];
        deck[group][length[group]]=card;
        return;
    }
    int left=0,right=length[group],mid;
    while(true)
    {
        mid=(left+right)/2;
        if(deck[group][mid]->index>card->index)
        {
            if(mid==0)
            {
                ++length[group];
                for(int i=length[group];i>=1;--i) deck[group][i]=deck[group][i-1];
                deck[group][0]=card;
                break;
            }
            else if((deck[group][mid-1]->index>=card->index&&mid==1))
            {
                ++length[group];
                for(int i=length[group];i>=1;--i) deck[group][i]=deck[group][i-1];
                deck[group][0]=card;
                break;
            }
            else if(deck[group][mid-1]->index<=card->index)
            {
                ++length[group];
                for(int i=length[group];i>=mid+1;--i) deck[group][i]=deck[group][i-1];
                deck[group][mid]=card;
                break;
            }
            else right=mid;
        }
        else if(deck[group][mid]->index<card->index)
        {
            if(mid==length[group])
            {
                ++length[group];
                deck[group][length[group]]=card;
                break;
            }
            else if(deck[group][mid+1]->index<=card->index&&mid+1==length[group])
            {
                ++length[group];
                deck[group][length[group]]=card;
                break;
            }
            else if(deck[group][mid+1]->index>=card->index)
            {
                ++length[group];
                for(int i=length[group];i>=mid+2;--i) deck[group][i]=deck[group][i-1];
                deck[group][mid+1]=card;
                break;
            }
            else left=mid;
        }
        else
        {
            ++length[group];
            for(int i=length[group];i>=mid+1;--i) deck[group][i]=deck[group][i-1];
            deck[group][mid]=card;
            break;
        }
    }
}

card* randomDistribute(card* cards)
{
    srand(time(0));
    int random;
    for(int i=0;i<51;++i)
    {
        random=rand()%MOD+LEAST;
        for(int j=0;j<random;++j) cards=cards->next;
        if(i%3==0) insertDeck(cards,0);
        else if(i%3==1) insertDeck(cards,1);
        else insertDeck(cards,2);
        (cards->prev)->next=cards->next;
        (cards->next)->prev=cards->prev;
        cards=cards->next;
    }
    return cards;
}

int main()
{
    card* rest=randomDistribute(generateCards());
    for(int i=0;i<3;++i)
    { 
        for(int j=0;j<=length[i];++j)
        {
            cout<<deck[i][j]->num<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<3;++i)
    {
        cout<<rest->num<<" ";
        rest=rest->next;
    }
    cout<<endl;
    return 0;
}