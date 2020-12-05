//完全背包
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[10005];
int w[3]={150,200,350};
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        memset(dp,0,sizeof(dp));
        for(int i=0; i<3; i++)
            for(int k=w[i]; k<=n; k++)
            {
                dp[k] = max( dp[k], dp[k-w[i]]+w[i] );
            }
        printf("%d\n",n-dp[n]);


    }
    return 0;
}