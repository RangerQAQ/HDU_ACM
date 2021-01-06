#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int a[22],vis[22];
int n;

bool primer(int x){
    int i;
    for(i=2;i<=sqrt(x);i++){
        if((x % i)==0){
            return false;
        }
    }
    return true;
}

void dfs(int num){
    if(num==n && primer(a[1]+a[n])){
        for(int i=1;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<a[n]<<endl;
    }
    else{
        for(int i=2;i<=n;i++){
            if(vis[i]==0 && primer(a[num]+i)){
                a[num+1]=i;
                vis[i]=1;
                dfs(num+1);
                vis[i]=0;
            }
        }
    }
}

int main(){
    int count=0;
    while(cin>>n){
        memset(vis,0,sizeof(vis));
        a[1]=1;
        count++;
        cout<<"Case "<<count<<":"<<endl;
        dfs(1);
        cout<<endl;
    }
}