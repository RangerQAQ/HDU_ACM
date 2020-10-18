#include<iostream>
using namespace std;

int main(){
    int a,b;
    while(cin>>a>>b && (a+b)!=0){
        int num=1;
        for(int i=0;i<b;i++){
            num=(num*a)%1000;
        }
        cout<<num<<endl;
    }
    return 0;
}