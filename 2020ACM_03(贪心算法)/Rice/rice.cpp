#include<iostream>
#include<algorithm>
using namespace std;



int main(){
    int n;
    
    cin>>n;
    while(n--){
        double sum=0.00;
        int m,p,temp;
        cin>>m>>p;
        double g[1001],j[1001];
        for(int s=0;s<p;s++){
            scanf("%lf %lf",&j[s],&g[s]);
        }
        for(int k=0;k<p-1;k++){
           for(int t=k;t<p-1;t++){
              if(j[k]>j[t+1]){
                  temp=j[t+1];
                  j[t+1]=j[k];
                  j[k]=temp;
                  temp=g[t+1];
                  g[t+1]=g[k];
                  g[k]=temp;
               }
            }
        }
        for(int q=0;q<p;q++){
            if(m-(j[q]*g[q])>=0){
                m=m-j[q]*g[q];
                sum=sum+g[q];
            }
            else{
                
                sum=sum+m/j[q];
                break;
            }

        }
        printf("%0.2lf\n",sum);
    }
    return 0;
}
