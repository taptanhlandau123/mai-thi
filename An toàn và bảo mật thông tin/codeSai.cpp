#include<iostream>
using namespace std;
int KT_So(char c)
{
    return c-'a';
}
char So_Kt(int n)
{
    return 'a'+n;
}
string P,K;
int main()
{
    string P,C="";
    int a,b;
    cout<<"Nhap chuoi P: ";
    getline(cin,P);
    cout<<"Nhap a: ";
    cin>>a;
    cout<<"Nhap b: ";
    cin>>b;
    //C = P/a + b => P = C-b * a
    for (int i = 0; i < P.size(); i++)
    {
        int m  = ((KT_So(P[i])/a)+b)%26;
        C+=So_Kt(m);
    }
    cout<<"Chuoi ma hoa: "<<C<<endl;
    P = "";
    for (int i = 0; i < C.size(); i++)
    {
        int m = ((KT_So(C[i])*a)-b)%26;
        P+= So_Kt(m);
    }
    cout<<"Chuoi giai ma: "<<P;
}

