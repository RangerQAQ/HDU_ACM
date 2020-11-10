#include<iostream>
#include<algorithm>
using namespace std;

int HN[5844],f2=1,f3=1,f5=1,f7=1;
int min(int a,int b,int c,int d)
{
   int f[5];
   f[1]=a;
   f[2]=b;
   f[3]=c;
   f[4]=d;
   int min=f[1];
   for(int i=2;i<5;i++){
       if(f[i]<min){
           min=f[i];
       }
    }
    return min;
}



int main()
{
    int t;
    HN[1]=1;
    for( int i=2; i<=5844; i++)
    {
        HN[i]=min(HN[f2]*2,HN[f3]*3,HN[f5]*5,HN[f7]*7);//状态转移方程
        if(HN[i]==HN[f2]*2) f2++;
        if(HN[i]==HN[f3]*3) f3++;
        if(HN[i]==HN[f5]*5) f5++;
        if(HN[i]==HN[f7]*7) f7++;
    }
    while(~scanf("%d",&t)&&t!=0)
    {
        if(t%10==1&&t%100!=11)
            printf("The %dst humble number is %d.\n",t,HN[t]);
        else if(t%10==2&&t%100!=12)
            printf("The %dnd humble number is %d.\n",t,HN[t]);
        else if(t%10==3&&t%100!=13)
            printf("The %drd humble number is %d.\n",t,HN[t]);
        else
            printf("The %dth humble number is %d.\n",t,HN[t]);
    }
    return 0;
}