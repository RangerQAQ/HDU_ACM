#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    int w[1001],v[1001];
    int dp[1001];
    int m,n;
    while(scanf("%d %d",&m,&n) && (m+n)!=-2){
        memset(w,0,sizeof(w));
        memset(v,0,sizeof(v));
        memset(dp,999,sizeof(dp));
        dp[0]=0;
        for(int i=0;i<n;i++){
            cin>>w[i]>>v[i];
        }
        for(int i=0;i<=n;i++)
        {
           for(int j=m;j>=v[i];j--)
           {
              dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
           }
        }
    
        if(dp[m]<0){
            cout<<"-1"<<endl;
        }
        else{
            cout<<dp[m]<<endl;
        }
    }
    return 0;
}
