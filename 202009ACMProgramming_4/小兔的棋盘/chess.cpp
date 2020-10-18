#include<iostream>
using namespace std;

int main(){
    int n;
    int num=1;
    long long f[40];//注意溢出
    f[0]=1;
    f[1]=1;
    for(int i=2;i<36;i++){
        f[i]=0;
        for(int j=0;j<i;j++){            
            f[i]+=(f[j]*f[i-j-1]);          
        }
    }
    while (scanf ("%d",&n) && n != -1)
		printf ("%d %d %lld\n",num++,n,f[n] * 2);
	return 0;
}