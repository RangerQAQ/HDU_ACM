#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int m;
        int t;
        cin>>m;
        int f[9];
        int num=m % 10;
        f[1]=num;
        for(int k=2;k<9;k++){
            f[k]=(f[k-1] * num) % 10;
        }

        for(int j=2;j<9;j++){
           if(f[j]==f[1]){
               t=j-1;
               break;
           }
        }
        if(m<=t){
            cout<<f[m]<<endl;
        }
        else{
            cout<<f[t+ m%t]<<endl;
        }
    }
    return 0;
}