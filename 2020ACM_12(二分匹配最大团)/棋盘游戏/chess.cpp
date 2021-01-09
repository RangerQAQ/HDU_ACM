/*由于每一行每一列都只有一个“車”，相当于行、列做匹配，
让车的数量最多就是相当于求最大匹配数。故先用匈牙利算法板子求出最开始的匹配数。
至于“重要点”，只需要暴力遍历一遍，依次将可以放的格子标记为不可放，
每次跑匈牙利，如果匹配数减少了，说明该格子是重要点。
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

struct F{
    int x;
    int y;
}f[10001];

int k,uN,vN;
int g[105][105];
int linker[105];
bool used[105];

bool dfs(int u){
    for(int v=0;v<vN;v++){
        if(g[u][v] && !used[v]){
            used[v]=true;
            if(linker[v]==-1 || dfs(linker[v])){
                linker[v]=u;
                return true;
            }
        }
    }
    return false;
}

int hungary(){
    int res=0;
    memset(linker,-1,sizeof(linker));
    for(int u=0;u<uN;u++){
        memset(used,false,sizeof(used));
        if(dfs(u)){
            res++;
        }
    }
    return res;
}

int main(){
    int num=0;
    while(scanf("%d %d %d",&uN,&vN,&k)!=EOF){
        int ans=0;
        memset(g,0,sizeof(g));
        for(int i=0;i<k;i++){
            scanf("%d %d",&f[i].x,&f[i].y);
            g[f[i].x-1][f[i].y-1]=1;  
        }
        int h=hungary();
        for(int i=0;i<k;i++){
            g[f[i].x-1][f[i].y-1]=0;
            if(hungary() < h) 
               ans++;
            g[f[i].x-1][f[i].y-1]=1;
        }
        printf("Board %d have %d important blanks for %d chessmen.\n", ++num, ans, h);
    }
    return 0;
}
