#include<iostream>
using namespace std;

int gcd(int a,int b){
    while(a!=b){
        if(a>b){
            a=a-b;
        }
        else{
            b=b-a;
        }
    }
    return a; 
}
int main(){
    int n,m,num;
    while(cin>>n>>m){
        num=n/gcd(n,m)*m; //注意小心a*b溢出,所以先除
        cout<<num<<endl;

    }
    return 0;
}

