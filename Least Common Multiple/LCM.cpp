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
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int num=1;
        int m,k;
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>m;
            num=num/gcd(num,m)*m; //注意小心a*b溢出,所以先除
        }
        cout<<num<<endl;
    }
    return 0;
}

