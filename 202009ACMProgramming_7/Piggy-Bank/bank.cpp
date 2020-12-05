//完全背包
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[10005];
int v[10005];
int w[10005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int e,f,n,a;
        scanf("%d%d",&e,&f);
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&v[i],&w[i]);
        }
        a=f-e;
        for(int i=1; i<=a; i++)
        {
            dp[i]=10000000;//把dp数组从1到a的每一位都定义为最大值，使得方便查找最小值
        }
        dp[0]=0;
        for(int i=0; i<n; i++)
        {
            for(int j=w[i]; j<=a; j++)//与01背包不同,完全背包顺序,因为同一物品可多次选择
            {
                dp[j]=min(dp[j],dp[j-w[i]]+v[i]);//这个就是与常规的完全背包一点不同就是这个是查找最小值，常规的是查找最大值
            }
        }
        if(dp[a]<10000000)//如果dp小于定义时的最大值，就证明有情况可以把罐子装到正好重量
        {
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[a]);
        }
        else//如果没有，就证明没有一种情况可以把罐子正好装满
        {
            printf("This is impossible.\n");
        }
    }
    return 0;
}