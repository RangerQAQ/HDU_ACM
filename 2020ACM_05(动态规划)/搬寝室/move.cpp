#include<iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main(){
    int n,k,i;
    while(cin>>n>>k){
     int f[2001];
     int dp[2001][1001];//dp[i][j]表示前i件物品中取j对所需最小疲劳值
     for(i=1;i<=n;i++){
        scanf("%d",&f[i]);
     }
     memset(dp,9999999,sizeof(dp));
     for(i=1;i<=n;i++)
         dp[i][0] = 0;
     sort(f+1,f+n+1);
     for(i=2;i<=n;i++){
        for(int j=1;j<=i/2;j++){
           dp[i][j] = min(dp[i-2][j-1]+(f[i]-f[i-1])*(f[i]-f[i-1]),dp[i-1][j]);//考虑搬第i件(一定和第i-件作差最小)能否使疲劳值最小
        }   
     }
     cout<<dp[n][k]<<endl;
    }
    return 0;
}