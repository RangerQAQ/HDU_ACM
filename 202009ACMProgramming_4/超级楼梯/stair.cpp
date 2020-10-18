#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        int m;
        cin>>m;
        int f[1001];
        f[2]=1;
        f[3]=2;
        if(m==2){
            cout<<1<<endl;
        }
        else if(m==3){
            cout<<2<<endl;
        }
        else{
            for(int i=4;i<=m;i++){
                f[i]=f[i-1]+f[i-2];
            }
            cout<<f[m]<<endl;
        }
    }
    return 0;
}