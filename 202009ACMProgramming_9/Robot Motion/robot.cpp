#include<iostream>
#include<cstring>
using namespace std;

char a[15][15];
int vis[15][15];
int n,m,s;

void dfs(int x,int y,int step){
    if(x==0 || y==0 || x>n || y>m){
        cout<<step-1<<" "<<"step(s) to exit"<<endl;
        return;
    }
    if(vis[x][y]!=0){
        cout<<vis[x][y]-1<<" step(s) before a loop of "<<step-vis[x][y]<<" step(s)"<<endl;
        return;
    }
    else{
        vis[x][y]=step;
        if(a[x][y]=='N'){
            dfs(x-1,y,step+1);
        }
        else if(a[x][y]=='S'){
            dfs(x+1,y,step+1);
        }
        else if(a[x][y]=='E'){
            dfs(x,y+1,step+1);
        }
        else if(a[x][y]=='W'){
            dfs(x,y-1,step+1);
        }
    }
}

int main(){
    while(cin>>n>>m>>s && (n+m+s)!=0){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        memset(vis,0,sizeof(vis));
        dfs(1,s,1);
    }
    return 0;
}