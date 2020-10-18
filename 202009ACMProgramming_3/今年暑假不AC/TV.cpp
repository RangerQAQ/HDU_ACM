#include <iostream>
#include <algorithm>
using namespace std;
 
struct TV 
{
	int t1; 
	int t2;
}a[101]; 
 
bool cmp(TV u,TV v)//对节目按照结束时间从小到大排序，如果结束的时间相同，则按照开始的时间从大到小的排序！ 
{
	if(u.t2==v.t2){
        //为什么要将开始的时间从大到小排序呢？是因为如果结束时间相同的话，开始的 
    	return u.t1>v.t1;//越迟，看节目的时间越短，你就能尽可能的多看电视！
    }	 
	return u.t2<v.t2; 
}
 
int main()
{
	int n,i,j,k,t;
	while(cin>>n && n!=0)
	{
		for(i=0;i<n;i++)//有n个开始和结束时间，将时间输入 
			cin>>a[i].t1>>a[i].t2;
		sort(a,a+n,cmp);//对时间进行排序 
        k=1;
        t=a[0].t2;
		for(i=1;i<n;i++)//如果开始 的时间比他这个结束的时间迟，则就k++ 
		{
			if(a[i].t1>=t)//说明这个电视你能够看 
			{
				t=a[i].t2;
				k++;
			}
		}
		cout<<k<<endl;//k代表能看的电视的个数！ 
	}
	return 0;
}