#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int used[1005];
int vis[1005];
int p[1005][105];
int num[1005];
int find(int u)//匈牙利算法邻接表模板
{
    int i,v;
    for(i=0;i<num[u];i++)
    {
        v=p[u][i];
        if(!vis[v])
        {
            vis[v]=1;
            if(used[v]==-1||find(used[v]))
            {
                used[v]=u;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int i,j,k,n,m,x;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d: (%d)",&x,&num[i]);//输入有些特殊
            for(j=0;j<num[x];j++)
            {
                scanf("%d",&p[x][j]);
            }
        }
        int ans=0;
        memset(used,-1,sizeof(used));//因为这里有0所以初始化-1
        for(i=0;i<n;i++)
        {
            memset(vis,0,sizeof(vis));
            if(find(i))
                ans++;
        }
        ans/=2;//因为二分图是对称的一对匹配算了两次
        printf("%d\n",n-ans);//最大独立集=顶点数-最大匹配
    }
    return 0;
}
