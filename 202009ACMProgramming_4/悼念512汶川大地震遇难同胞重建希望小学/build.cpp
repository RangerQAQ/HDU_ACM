#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        int m;
        cin>>m;
        long long int a[55];
        a[1]=1;
        a[2]=3;
        a[3]=5;
        for(int i=4;i<=m;i++){
            a[i]=a[i-1]+2*a[i-2];
        }
        cout<<a[m]<<endl;
    }
    return 0;
}