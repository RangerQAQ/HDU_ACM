#include<iostream>
using namespace std;

int main(){
    int n;
    int a[21];
    int b[21];
    int c[21];
    a[0]=1;
    b[0]=1;
    c[0]=1;
    for(int i=1;i<21;i++){
        a[i]=a[i-1]+b[i-1]+c[i-1];
        b[i]=b[i-1]+a[i-1];
        c[i]=c[i-1]+a[i-1];
    }
    cin>>n;
    while(n--){
        int m;
        cin>>m;
        cout<<a[m]<<endl;
    }
    return 0;
}