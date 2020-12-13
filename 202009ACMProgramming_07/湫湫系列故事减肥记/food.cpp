//完全背包
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[100005];
int v[101];
int w[101];
int main()
{
    int t,sum;
    while(~scanf("%d",&t))
    {

        for(int i=1; i<=t; i++)
        {
            scanf("%d%d",&v[i],&w[i]);
        }
        scanf("%d",&sum);
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=t; i++)
        {
            for(int j=w[i]; j<=sum; j++)//与01背包不同,完全背包顺序,因为同一物品可多次选择
            {
                dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
            }
        }
        printf("%d\n",dp[sum]);
        
    }
    return 0;
}