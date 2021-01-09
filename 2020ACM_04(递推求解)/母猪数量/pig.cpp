#include<iostream>
using namespace std;

struct COW{
    long long y1;
    long long y2;
    long long y3;
    long long y4;
    long long y5;
}cow[42];

int main(){
    int n;
    cin>>n;
    cow[1].y1=1;
    cow[1].y2=0;
    cow[1].y3=0;
    cow[1].y4=0;
    cow[1].y5=0;
    for(int i=2;i<42;i++){
        cow[i].y1=4*(cow[i-1].y2+cow[i-1].y3+cow[i-1].y4);
        cow[i].y2=cow[i-1].y1;
        cow[i].y3=cow[i-1].y2;
        cow[i].y4=cow[i-1].y3;
        cow[i].y5=cow[i-1].y4;
    }
    while(n--){
       int m;
       cin>>m;
       cout<<cow[m].y1+cow[m].y2+cow[m].y3+cow[m].y4+cow[m].y5<<endl;
    }
    return 0;
}