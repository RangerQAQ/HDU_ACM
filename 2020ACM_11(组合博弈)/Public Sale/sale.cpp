#include<iostream>
using namespace std;
int main()
{
	int n,m;
	while(cin>>m>>n)
	{
		if((m%(n+1)==0)) cout << "none" << endl;
		else
		{
			if(m<=n)
			{
				if(m==n) cout << m <<endl;	//如果m,n一样，那么第一次出价就一定要直接买下来 
				else
				{
					for(int i=m;i<=n-1;i++)   //或者就是比m大（包括m）到n（包括n）的都可以 
						cout << i << " ";
					cout << n << endl;
				}
			}
			else
			{
				cout << m%(n+1) << endl;  //如果m比n大，为了保证一定赢，就要出m%(n+1) 
			}
		}
	}			 
	return 0;
}