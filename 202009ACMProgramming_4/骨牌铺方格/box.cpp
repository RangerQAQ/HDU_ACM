#include<iostream>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        long long int a[55];
        a[1]=1;
        a[2]=2;
        a[3]=3;
        for(int i=4;i<=n;i++){
            a[i]=a[i-1]+a[i-2];
        }
        cout<<a[n]<<endl;
    }
    return 0;
}