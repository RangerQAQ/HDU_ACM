#include<iostream>
#include<string.h>
using namespace std;

int vexs[100005][11]={0};

int DP(int x, int y, int z)
{
    x = x > y ? x : y;
    x = x > z ? x : z;
 
    return x;
}
 
int main()
{
    int n;
    int x, T;
    int i;
    int max_t ;
 
    while(scanf("%d", &n), n)
    {
        memset(vexs, 0, sizeof(vexs));
 
        max_t = 0;
 
        for (i = 0; i < n; i++)
        {
            scanf("%d%d", &x, &T);
            vexs[T][x]++;
 
            max_t = T > max_t ? T : max_t;
        }
 
        for (T = max_t - 1; T >= 0; T--)
        {
            vexs[T][0] += DP(0, vexs[T+1][0], vexs[T+1][1]);
            vexs[T][10] += DP(vexs[T+1][9], vexs[T+1][10], 0);
 
            for (x = 1; x < 10; x++)
            {
                vexs[T][x] += DP(vexs[T+1][x-1], vexs[T+1][x], vexs[T+1][x+1]);
            }
        }
 
        printf("%d\n", vexs[0][5]);
    }
 
    return 0;
}