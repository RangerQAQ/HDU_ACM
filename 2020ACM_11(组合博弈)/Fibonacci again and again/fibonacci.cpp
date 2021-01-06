#include<iostream>
#include<cstring>
using namespace std;
#define N 1001

int f[N];//可以取走的石子个数
int sg[N];
int mess[N]; //用来求mex{}    
void getSG(int n)
{
    int i,j;
    memset(sg,0,sizeof(sg));
    for(i=1;i<=n;i++)
    {
        memset(mess,0,sizeof(mess));
        for(j=1;f[j]<=i;j++)
            mess[sg[i-f[j]]]=1;
        for(j=0;j<=n;j++)    //求mes{}中未出现的最小的非负整数
        {
            if(mess[j]==0)
            {
                sg[i]=j;
                break;
            }
        }
    }
}
int main()
{
    int i,m,n,p;
    f[0]=f[1]=1;
    for(i=2;i<=16;i++)
        f[i]=f[i-1]+f[i-2];
    getSG(1000);
    while(scanf("%d%d%d",&m,&n,&p)!=EOF)
    {
        if(m==0&&n==0&&p==0)
            break;
        if((sg[m]^sg[n]^sg[p])==0)
            printf("Nacci\n");
        else
            printf("Fibo\n");
    }
    return 0;
}