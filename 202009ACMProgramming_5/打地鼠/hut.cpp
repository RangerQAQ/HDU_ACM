
#include <iostream>
#include <cmath> 
using namespace std;
 
int f[21][21]={0};
int dp[21][21]={0};
int main()
{
	int n,k,i,j,c,num;
	while(cin>>n>>k)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<k;j++)
			cin>>f[i][j];
		}
		num=0;
		for(i=1;i<n;i++)
		{
			num=99999;
			for(j=0;j<k;j++)
			{
				dp[i][j]=99999;
				for(c=0;c<k;c++)
				{
					dp[i][j]=min(dp[i][j],dp[i-1][c]+abs(f[i-1][c]-f[i][j]));
					if(dp[i][j]<num)
					num=dp[i][j];
				}
			}
			
		}
		cout<<num<<endl;
	} 
    return 0;
}
