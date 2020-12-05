//优先队列
#include <iostream>
#include <cstdio>
#include <cstring>
#include<queue>
using namespace std;
struct node{
    int x,y,t;
    friend bool operator<(node n1,node n2){
        return n2.t<n1.t;//重载了小于号,进行排序,t小的在前,使出队元素所记忆的时间层次递增
    }
};
int n,m;
char map[210][210];
int vis[210][210];
int ax,ay,rx,ry;
node ft;
int mx[]={1,0,-1,0};
int my[]={0,-1,0,1};

int judge(int x,int y){
    if(x<0||x>=n||y<0||y>=m){
        return 0;
    }
    if(map[x][y]=='#'){
        return 0;
    }
    if(vis[x][y]){
        return 0;
    }
    return 1;
}

void bfs(){
    priority_queue<node> q;//优先队列
    ft.x=rx;
    ft.y=ry;
    ft.t=0;
    q.push(ft);
    vis[rx][ry]=1;
    while(!q.empty()){
        ft=q.top();
        q.pop();
        int x=ft.x;
        int y=ft.y;
        if(x==ax&&y==ay){
            printf("%d\n",ft.t);
            return;
        }
        for(int i=0;i<4;i++){
            x=ft.x+mx[i];
            y=ft.y+my[i];
            if(!judge(x,y)){
                continue;
            }
            node nt;
            if(map[x][y]=='.'||map[x][y]=='a'){
                nt.x=x;
                nt.y=y;
                nt.t=ft.t+1;
                vis[x][y]=1;
                q.push(nt);
            }else if(map[x][y]=='x'){
                nt.x=x;
                nt.y=y;
                nt.t=ft.t+2;
                vis[x][y]=1;
                q.push(nt);
            }
        }
    }
    printf("Poor ANGEL has to stay in the prison all his life.\n");
}


int main()
{
    while(~scanf("%d%d",&n,&m)){
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            scanf("%s",&map[i]);
            for(int j=0;j<m;j++){
                if(map[i][j]=='a'){
                    ax=i,ay=j;
                }
                if(map[i][j]=='r'){
                    rx=i,ry=j;
                }
            }
        }
        bfs();
    }
    return 0;
}