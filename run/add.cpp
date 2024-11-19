#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    cout<<"which two file :";
    cout<<endl;
    char in1[20],in2[20],out[20];
    cout<<"origin file name? :";
    cin>>in1>>in2;
    cout<<endl;
    cout<<"out file name? :";
    cin>>out;
    cout<<endl;
    double val1,val2;
    char mid,end;
    ifstream origin;
    ofstream comeout;
    comeout.open(out);
    origin.open(in1);
    int tmp=0;
    while(!origin.eof())
    {
        origin>>val1>>mid>>val2>>end;
        comeout<<fixed<<setprecision(8)<<val1<<","<<val2<<";";
    }
    origin.close();
    origin.open(in2);
    while(!origin.eof())
    {
        origin>>val1>>mid>>val2>>end;
        comeout<<fixed<<setprecision(8)<<val1<<","<<val2<<";";
    }
    comeout.close();
    origin.close();
    return 0;
}