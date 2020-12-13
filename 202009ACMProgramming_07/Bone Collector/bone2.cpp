//将dp数组一维化
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int c[2001],w[2001],dp[2001];
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
            for(j=v;j>=c[i];j--){//一维数组要保证, 在第i次外循环时, 调用的dp[v-c[i]]实际上是基于第i-1次循环得到的值.
                                 //而逆序保证了, 对于dp[v], 它要调用的dp[v-c[i]]一定是第i层循环还没有更新过的,即dp[w-wi]只有可能是第i-1层存储的数据
               dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
            }
        }
        cout<<dp[v]<<endl;
    }
    return 0;
}