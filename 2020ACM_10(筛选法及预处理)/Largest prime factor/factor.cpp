#include<iostream>
#include<algorithm>
using namespace std;
int prime[3000007];
int indx = 0;
void dabiao()
{
    prime[1] = 0;
    for(long i =2;i<=3000000;i++)
    {
        if(prime[i]==0)//只有prime为0 那么他才是一个素数
        {
            prime[i] = ++indx;
            for(long j = i+i ;j<=1000000;j+=i)//筛选素数的倍数
                prime[j] = prime[i];
        }
    }
}
int main()
{
    dabiao();
    long tt;
    while(~scanf("%ld",&tt))
    {
        printf("%ld\n",prime[tt]);
    }
    return 0;
}
/*一个数为素数那么他的倍数一定不是一个素数 即合数 2 是素数 
那么2的倍数都不是素数 3 是素数 6,9，。。。3*n 肯定也都不是素数了 
那么他的最大质因数就是3 的最大质因数*/