//01背包
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int c[2001],w[2001],dp[2001][2001];//dp表示体积为v时考虑前i个物品的最大价值

int main(){
    int m,n,v,i,j;
    cin>>m;
    while(m--){
        scanf("%d %d",&n,&v);
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++){
            scanf("%d",&w[i]);
        }
        for(i=1;i<=n;i++){
            scanf("%d",&c[i]);
        }
        for(i=1;i<=n;i++){
            for(j=0;j<=v;j++){
                if(j>=c[i]){
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-c[i]]+w[i]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        cout<<dp[n][v]<<endl;
    }
    return 0;
}