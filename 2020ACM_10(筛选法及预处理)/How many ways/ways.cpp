#include<iostream>//记忆化搜索  终点位置方案数目为1，搜索过程记录搜到的每一点的方案数
using namespace std;

#define N 105
const int mod=10000;
int n,m;
int a[N][N];
int mark[N][N];
int dfs(int x,int y)
{
    if(mark[x][y]!=-1)
        return mark[x][y];
    int t,x1,y1,tmp;
    tmp=0;
    t=a[x][y];
    for(x1=0;x1<=t;x1++)
    {
        if(x+x1>=n)
            break;
        for(y1=0;x1+y1<=t;y1++)
        {
            if(y+y1>=m)
                break;
            if(x1+y1!=0)          //不能原地走
                tmp+=dfs(x+x1,y+y1);
        }
    }
    tmp%=mod;
    return mark[x][y]=tmp;
}
int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%d",&a[i][j]);
                mark[i][j]=-1;
            }
        }
        mark[n-1][m-1]=1;
        printf("%d\n",dfs(0,0));
    }
    return 0;
}
/*动态规划
#include"stdio.h"
#include"string.h"
#define M 10000
#define N 110
int main()
{
    int T,i,j,n,m,x,y,di,dj,t;
    int a[N][N],dp[N][N];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        memset(dp,0,sizeof(dp));
        dp[1][1]=1;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(dp[i][j])
                {
                    t=a[i][j];
                    for(x=0;x<=t;x++)
                    {
                        for(y=0;y<=t;y++)
                        {
                            if(x+y==0)
                                continue;
                            if(x+y>t)
                                break;
                            di=x+i;
                            dj=y+j;
                            if(di<=n&&dj<=m)
                                dp[di][dj]+=dp[i][j];
                            dp[di][dj]%=M;
                        }
                    }
                }
            }
        }
        printf("%d\n",dp[n][m]%M);
    }    
    return 0;
}
*/