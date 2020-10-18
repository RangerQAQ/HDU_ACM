#include<iostream>
#include<algorithm>
using namespace std;

struct homework
{
	int time;
	int score;
} H[1001];

bool cmp(homework a,homework b)
{
	return a.score > b.score;
}

int main()
{
	int mark[1001]={0},m,N,i,j,sum;
	cin >> m;
	for(int k=0;k<m;k++)
	{
		cin >> N;
		for(i=0;i<N;i++)
		 cin >> H[i].time; 
		for(i=0;i<N;i++)
		 cin >> H[i].score;
      
        sort(H,H+N,cmp);
        sum=0;
		for(i=0;i<N;i++)
	    {
            
     		for(j = H[i].time;j>=1;j--)//先给分数大的安排时间，而且要在期限或以前
     		{                          //否则就超期了
		     	if(mark[j]==0)       //mark数组标记已经有了安排的那天
		     	{
	     			mark[j] = 1;
	     			break;
	     		}
		    }
		    if(j==0)//说明没有找到安排时间，只能扣分了           
		    {
     			sum += H[i].score;
     		}
			  
     	}
     	for(i=0;i<1001;i++){
     	  mark[i]=0;
        }

     	cout<<sum<<endl;
		  
	}
}