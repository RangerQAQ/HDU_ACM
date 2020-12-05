//多重背包
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int i,j,k,m,n,T,ans;
	int u[110],v[110],w[110],dp[110];
	scanf("%d",&T);
	while(T --)
	{
		ans = 0;
		scanf("%d%d",&n,&m);
		for(i = 1; i <= m; i ++)
			scanf("%d%d%d",&u[i],&v[i],&w[i]);
		memset(dp,0,sizeof(dp));
		for(i = 1; i <= m; i ++)
		{
			for(j = n; j >= u[i]; j --)
			{
				for(k = 1; k <= w[i]; k ++)
					if(j >= k*u[i])
						dp[j] = max(dp[j],dp[j-k*u[i]]+v[i]*k);
				ans = max(ans,dp[j]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}