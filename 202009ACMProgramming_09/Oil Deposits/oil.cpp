#include<iostream>
#include<cstring>
using namespace std;

char a[101][101];
int dir[8][2]={{0,-1},{0,1},{1,0},{-1,0},{1,-1},{1,1},{-1,-1},{-1,1}};
int vis[101][101];
int n,m,num;
void dfs(int x,int y){
    if(a[x][y]=='#' || vis[x][y]!=0 || x<0 || y<0 || x>=n || y>=m){
        return;
    }
    vis[x][y]=num;
    for(int i=0;i<8;i++){
        int xx=x+dir[i][0];
        int yy=y+dir[i][1];
        if(a[xx][yy]=='@' && !vis[xx][yy] && xx>=0 && xx<n && yy>=0 && yy<m){
            dfs(xx,yy);
        }
    }
}
int main(){
    int i,j;
    while(cin>>n>>m && (n+m)!=0){
        num=0;
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(a[i][j]=='@' && !vis[i][j]){
                    num++;
                    dfs(i,j);
                }
            }
        }
        cout<<num<<endl;
    }
    return 0;
}