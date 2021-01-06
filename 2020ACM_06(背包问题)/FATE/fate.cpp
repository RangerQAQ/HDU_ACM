//完全背包
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define N 101
 
int dp[N][N];
int v[N],w[N];
 
int  main()
{
	int n,m,k,s,i,j,l,locate,flag;
	
//	freopen("test.txt","r",stdin);
	while(scanf("%d%d%d%d",&n,&m,&k,&s)!=EOF)//还需的经验值，保留的忍耐度，怪的种数和最多的杀怪数
	{
		for(i=0;i<k;i++)
			scanf("%d%d",&v[i],&w[i]);//得到的经验值和会减掉的忍耐度
		
		memset(dp,0,sizeof(dp));
		for(i=0;i<k;i++)//怪的种数 
			for(j=w[i];j<=m;j++)//忍耐度 
				for(l=1;l<=s;l++)//怪个数 
					dp[j][l]=max(dp[j][l],dp[j-w[i]][l-1]+v[i]);  
		flag=0;    
        for(i=0;i<=m;i++)    
        {    
            if(flag)    
                break;    
            for(j=0;j<=s;j++)    
            {    
                if(dp[i][j]>=n)  //忍耐度/怪的个数 满足经验值  
                {    
                    locate=i;    
                    flag=1;    
                    break;    
                }    
            }    
        }    
        if(flag)    
            printf("%d\n",m-locate);//剩余的忍耐度    
        else    
            printf("-1\n");   
	}
	return 0;
}