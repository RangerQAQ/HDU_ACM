#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(int a,int b){
    return a>b;
}

int main(){
    int t[1001];
    int k[1001];
    int n;
    while(cin>>n && n!=0){
        for(int i=0;i<n;i++){
            cin>>t[i];
        }
        for(int j=0;j<n;j++){
            cin>>k[j];
        }
        sort(t,t+n,cmp);
        sort(k,k+n,cmp);

        int p=0,x=n-1,y=n-1,m=0,sum=0;
        int q=0;
        while(1){
            if(m==n){
                break;
            }
            if(t[p] > k[q]){
                p++;
                q++;
                m++;
                sum++;
            }
            else if(t[p] < k[q]){
                x--;
                q++;
                m++;
                sum--;
            }
            else if(t[p] == k[q]){
                if(t[x] > k[y]){
                    x--;
                    y--;
                    m++;
                    sum++;
                }
                else{
                    if(t[x]==k[q]){
                        x--;
                        q++;
                        m++;
                    }
                    else if(t[x]<k[q]){
                        x--;
                        q++;
                        m++;
                        sum--;
                    }
                } 
            }

        }
        cout<<200*sum<<endl;
    
    }
    return 0;
}
/*1.

如果田忌最快的马比齐王最快的马快，相比，田忌胜

如果田忌最快的马比齐王最快的马慢，用田忌最慢的马与齐王最快的马相比，齐王胜

2.如果田忌最快的马与齐王最快的马相等：

如果田忌最慢的马比齐王最慢的马快，相比，田忌胜

否则：

如果田忌最慢的马比齐王最快的马慢，相比，齐王胜

如果田忌最慢的马与齐王最快的马相等，相比，平
*/