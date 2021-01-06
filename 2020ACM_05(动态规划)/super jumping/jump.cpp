#include<iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,i,j;
    int f[1001];
    int d[1001];
    while(cin>>n && n){
        for(i=0;i<n;i++){
            scanf("%d",&f[i]);
            d[i]=0;
        }
        d[0]=f[0];
        for(j=1;j<n;j++){
            for(i=0;i<j;i++){
                if(f[j]>f[i]){
                   d[j]=max(d[j],d[i]+f[j]);
                }
            }
            d[j]=max(d[j],f[j]);
        }
        int max=d[0];
        for(i=1;i<n;i++){
            if(d[i]>max)
               max=d[i];
        }
        printf("%d\n",max);
    }
    return 0;
}