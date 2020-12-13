#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		long long fn = 0; 
		long long fa = 0;
		long long fb = 1;
		for (int i = 1;i < b - a + 1;i++)
		{
			fn = fa + fb;
			fa = fb;
			fb = fn;
		}
		cout<<fn<<endl;
	}
	return 0;
}