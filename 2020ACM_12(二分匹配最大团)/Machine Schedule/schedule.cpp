#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int k,uN,vN;//u是左边定点数,v是右边
int g[510][510];
int linker[510];
bool used[510];

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
    while(scanf("%d %d %d",&uN,&vN,&k) && uN){
        int num,a,b;
        memset(g,0,sizeof(g));
        while(k--){
            scanf("%d %d %d",&num,&a,&b);
            if(a!=0 && b!=0){
                g[a][b]=1;
            }
        }
        printf("%d\n",hungary());
    }
    return 0;
}
