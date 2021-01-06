#include<iostream>//以矩阵表示图,求最大团
using namespace std;

int Map[51][51];
int p[51];
int n,ans;

bool ok(int to,int num){
    for(int i=1;i<num;i++){
        if(!Map[p[i]][to]){
            return false;
        }
    }
    return true;
}

void dfs(int u,int num){
    if(num>ans){
        ans=num;
    }
    for(int i=u+1;i<=n;i++){
        if(ok(i,num)){
            p[num+1]=i;
            dfs(i,num+1);
        }
    }
}

int main(){
    while(scanf("%d",&n) && n){
        ans=0;
        int i,j;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                scanf("%d",&Map[i][j]);
            }
        }
        for(i=1;i<=n;i++){
            p[1]=i;
            dfs(i,1);
        }
        printf("%d\n",ans);
    }
    return 0;
}