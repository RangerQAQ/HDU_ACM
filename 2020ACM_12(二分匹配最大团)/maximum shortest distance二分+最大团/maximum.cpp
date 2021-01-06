#include<iostream>
using namespace std;
const int N=65;
int ans,f[N],set[N][N],a[N][N];//f[i]记录i-N中点构成的最大团的点的数量 记录的目的是为了剪枝
double b[N][N];
struct node
{
    double x,y;
}p[N];
double getdist(node a,node b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
bool dfs(int num,int dep)
{
    int i,j;
    if(!num)
    {
        if(dep>ans)
        {
            ans=dep;
            return 1;
        }//剪枝1 如果新加入的点与之前的最大团相连 因为不可能得到更大的dep了 所以return1
        return 0;
    }
    for(i=1;i<=num;i++)
    {
        if(dep+num-i+1<=ans)
            return 0;//剪枝2 如果当前已构成的团中点的数量加上剩余所有点的数量也没有超过ans 计算就没有意义了
        int u=set[dep][i];
        if(dep+f[u]<=ans)
            return 0;//剪枝3 如果当前的深度加上当前i点到最后一个点的最大团中点的数量还是也没有超过ans 计算就没有意义了
        int cnt=0;
        for(j=i+1;j<=num;j++)
            if(a[u][set[dep][j]])
                set[dep+1][++cnt]=set[dep][j];
        if(dfs(cnt,dep+1))
            return 1;//剪枝1
    }
    return 0;
}
int main()
{
    int n,i,j,num,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        double l=0,r=20000;
        for(i=1;i<n;i++)
            for(j=i+1;j<=n;j++)
            {
                b[i][j]=b[j][i]=getdist(p[i],p[j]);
 
            }
        while(r-l>1e-4)
        {
            double m=(r+l)/2;
            ans=0;
            for(i=1;i<n;i++)
                for(j=i+1;j<=n;j++)
                    a[i][j]=a[j][i]=(b[i][j]>=m*m);
            for(i=n;i>=1;i--)
            {
                num=0;
                for(j=i+1;j<=n;j++)
                    if(a[i][j])
                        set[1][++num]=j;
                dfs(num,1);
                f[i]=ans;
            }
            if(ans>=k)
                l=m;
            else
                r=m;
        }
        printf("%.2lf\n",l);
    }
    return 0;
}