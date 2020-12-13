#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct pos{
    int level;//所在层数
    int steps;//按过的按钮次数
};
int a[202],vis[202];
int n,s,e;

void bfs(int s,int e){
    pos cur,nex;
    cur.level=s;
    cur.steps=0;
    queue<pos>qu;
    qu.push(cur);
    vis[s]=1;//出发层s已标记
    while(!qu.empty()){
        cur=qu.front();//队列第一个元素
        qu.pop();
        if(cur.level==e){
            printf("%d\n",cur.steps);
            return;
        }
        nex.level=cur.level+a[cur.level];
        nex.steps=cur.steps+1;
        if(nex.level<=n){
            if(vis[nex.level]==0){
                vis[nex.level]=1;
                qu.push(nex);
            }
        }
        nex.level=cur.level-a[cur.level];
        nex.steps=cur.steps+1;
        if(nex.level>=1){
            if(vis[nex.level]==0){
                vis[nex.level]=1;
                qu.push(nex);
            }
        }      
    }
    printf("-1\n");
    return;
}

int main(){
    int i;
    while(scanf("%d",&n) && n!=0){
        scanf("%d %d",&s,&e);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            vis[i]=0;
        }
        bfs(s,e);
    }
    return 0;
}