#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 101;
int map[N][N];
int mark[N];
int n,q,i,j;

int Prim()
{
    int sum = 0;
    int t = n;
    int min,k;
    memset(mark,0,sizeof(mark));
    while(--t)
    {
        min = 10000;
        for (i = 2; i <= n; i++)
        {
            if(mark[i]!=1 && map[1][i] < min)
            {
                min = map[1][i];
                k = i;
            }
        }
        mark[k] = 1;
        sum += min;
        for (j = 2; j <= n; j++)
        {
            if(mark[j]!=1 && map[k][j] < map[1][j])
            {
                map[1][j] = map[k][j];
            }
        }
    }
    return sum;
}


int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                scanf("%d",&map[i][j]);
            }
        }
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d%d",&i,&j);
            map[i][j] = 0;
            map[j][i] = 0;
        }

        printf("%d\n",Prim());
    }
    
    return 0;
}