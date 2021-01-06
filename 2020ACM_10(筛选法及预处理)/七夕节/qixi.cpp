#include <iostream>
#include <cstring>
 
using namespace std;
 
const int MAXN = 500000;
 
int sum[MAXN+1];
 
void maketable(int n)
{
    memset(sum, 0, sizeof(sum));
    sum[1] = 0;
 
    int i=2, j;
    while(i<=n) {
        sum[i]++;
        j = i + i;      /* j=ki, k>1 */
        while(j <= n) {
            sum[j] += i;
            j += i;
        }
        i++;
    }
}
 
int main()
{
    int t, n;
 
    maketable(MAXN);
 
    while(cin >> t) {
        while(t--) {
            cin >> n;
 
            cout << sum[n] << endl;
        }
    }
 
    return 0;
}

