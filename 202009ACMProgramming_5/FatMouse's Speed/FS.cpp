#include<iostream>

#include<algorithm>
using namespace std;

struct Mouse{
    int weight;
    int speed;
    int number;
}m[1001];
struct node{
	int pre;
	int num;
}dp[1001];

bool cmp(Mouse a,Mouse b){
    if(a.weight!=b.weight){
        return a.weight<b.weight;
    }
    else{
        return a.speed>b.speed;
    }  
}

int main(){
    int num=0;
    while(scanf("%d %d",&m[num].weight,&m[num].speed)!=EOF){
        m[num].number=num+1;
        num++;
    }
    sort(m,m+num,cmp);
    for(int k=0;k<num;k++)
	{
		dp[k].num=1;
		dp[k].pre=0;
	}

    int i,j,k,t;
    int max=1;
    for(j=1;j<i;j++)
	{
		for(k=0;k<j;k++)
		{
			if(m[k].speed>m[j].speed&&m[k].weight<m[j].weight)
			{
				if(dp[j].num<dp[k].num+1)
				{
					dp[j].num=dp[k].num+1;
					dp[j].pre=k;
				}
			}
		}
		if(dp[j].num>max)
		{
			max=dp[j].num;
			t=j;
		}
	}
    printf("%d\n",max);
	int p[1111];
    for(j=1;j<=max;j++)
	{
		p[j]=t;
		t=dp[t].pre;
	}
	for(k=max;k>=1;k--)
		printf("%d\n",m[p[k]].number);
	return 0;
}