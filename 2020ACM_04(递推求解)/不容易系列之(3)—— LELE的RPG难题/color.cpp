#include<iostream>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        long long int a[55];
        a[1]=3;
        a[2]=6;
        a[3]=6;
        for(int i=4;i<=n;i++){
            a[i]=a[i-1]+2*a[i-2];
        }
        cout<<a[n]<<endl;
    }
    return 0;
}