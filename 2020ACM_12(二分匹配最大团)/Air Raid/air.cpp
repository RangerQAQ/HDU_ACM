//最小路径覆盖：在一个二分图中，最少用几条路径能把所有的点覆盖
//（路径不交叉，即每个点只属于一条路）。每条路径由连续的边组成。

//最小路径覆盖数 = 二分图中顶点数 - 最大匹配数
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int k,m;//k是边数,m是定点数
int g[510][510];
int linker[510];
bool used[510];

bool dfs(int u){
    for(int v=0;v<m;v++){
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
    for(int u=0;u<m;u++){
        memset(used,false,sizeof(used));
        if(dfs(u)){
            res++;
        }
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    while(n--){
        scanf("%d %d",&m,&k);
        int num,a,b;
        memset(g,0,sizeof(g));
        while(k--){
            scanf("%d %d",&a,&b);
            g[a-1][b-1]=1;
        }
        printf("%d\n",m-hungary());
    }
    return 0;
}

