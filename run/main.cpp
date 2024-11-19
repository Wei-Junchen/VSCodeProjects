#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    int count;
    cout<<"How many numbers into one group? :";
    cin>>count;
    cout<<endl;
    char in[20],out[20];
    cout<<"origin file name? :";
    cin>>in;
    cout<<endl;
    cout<<"out file name? :";
    cin>>out;
    cout<<endl;
    double val1,val2;
    char mid,end;
    ifstream origin;
    ofstream comeout;
    comeout.open(out);
    origin.open(in);
    int tmp=0;
    while(!origin.eof())
    {
        origin>>val1>>mid>>val2>>end;
        if(tmp==0)
            comeout<<fixed<<setprecision(8)<<val1<<","<<val2<<";";
        ++tmp;
        if(tmp==count) tmp=0;
    }
    comeout.close();
    origin.close();
    return 0;
}