//01背包
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct node
{
    int cost;
    double pct;
}a[11000];
double  val[11000];
int main()
{
    int money,con;
    while(scanf("%d%d",&money,&con)!=EOF&&(money||con))
    {
        int i,j;
        double  s;
        for(i=0;i<con;i++)
        {
            scanf("%d%lf",&a[i].cost,&s);
            a[i].pct =1.0-s;//求反面概率！ 
        }
        int count=0;
        for(i=0;i<=money;i++)
        val[i]=1;
        for(i=0;i<con;i++)
        {
            for(j=money;j>=a[i].cost ;j--)
            {
                val[j]=min(val[j] ,val[j-a[i].cost]*a[i].pct );//这里是相乘！
				  
            }
        } 
        printf("%.1lf%%\n",100-val[money]*100);
    }
    return  0;
} 