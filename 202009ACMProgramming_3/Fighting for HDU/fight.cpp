#include <iostream>
#include <algorithm>
using namespace std;

int data1[101];
int data2[101];
int main()
{
    int m;
    while(cin>>m,m)
    {
        int sum1=0,sum2=0;
        for(int i=0; i<m; i++)
            cin>>data1[i];
        for(int i=0; i<m; i++)
            cin>>data2[i];
        sort(data1,data1+m);
        sort(data2,data2+m);
        for(int i=0; i<m; i++)
        {
            if(data1[i] == data2[i])
            {
                sum1+=1;
                sum2+=1;
            }
            else  if(data1[i]>data2[i])
                sum1+=2;
            else
                sum2+=2;
        }
        printf("%d vs %d\n",sum1,sum2);
    }
    return 0;
}