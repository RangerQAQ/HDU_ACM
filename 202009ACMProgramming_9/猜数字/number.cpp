#include<iostream>
#include<cstring>

using namespace std;
int a[105],b[105],c[105];
 
int cal1(int a,int b)  //不一定对应
{
    int ans=0;
    int p1[4],p2[4],visi[4];
    int tt=0,i,j;
    while(a)
    {
        p1[tt++]=a%10;
        a/=10;
    }
    tt=0;
    while(b)
    {
        p2[tt++]=b%10;
        b/=10;
    }
 
    memset(visi,0,sizeof(visi));
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        {
            if(p1[i]==p2[j]&&!visi[j])
            {
                visi[j]=1;
                ans++;
                break;  //找到一个就跳出
            }
        }
    return ans;
}
 
int cal2(int a,int b)  //每一位都要对应
{
    int ans=0;
    int p1[4],p2[4];
    int tt=0,i;
    while(a)
    {
        p1[tt++]=a%10;
        a/=10;
    }
    tt=0;
    while(b)
    {
        p2[tt++]=b%10;
        b/=10;
    }
 
    for(i=0;i<4;i++)
        if(p1[i]==p2[i])
            ans++;
    return ans;
}
 
int main(){
    int n,i,j;
    while(cin>>n && n){
        int flag=0;
        int res;
        for(i=0;i<n;i++){
            scanf("%d %d %d",&a[i],&b[i],&c[i]);
        }
        for(i=1000;i<10000;i++){
            int cnt=0;
            for(j=0;j<n;j++){
                if(cal1(i,a[j])==b[j] && cal2(i,a[j])==c[j]){
                    cnt++;
                }
                else{
                    break;
                }
            }
            
            if(cnt==n && flag==1){
                flag=2;
                break;
            }
            else if(cnt==n && !flag){
                flag=1;
                res=i;
            }
        }
        if(flag==2){
            cout<<"Not sure"<<endl;
        }
        else{
            cout<<res<<endl;
        }
    }
    return 0;
}
 
