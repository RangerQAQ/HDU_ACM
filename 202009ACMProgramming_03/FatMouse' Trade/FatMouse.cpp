#include<iostream>
#include<algorithm>
using namespace std;


int main(){
    int m,n;
    double j[1000]={0};
    double f[1000]={0};
    double temp,sum;
    while(cin>>m>>n && (m+n)!=-2){
        
        double sum = 0.0;
        for(int i=0;i<n;i++){
            cin>>j[i]>>f[i];
        }
        for(int k=0;k<n-1;k++){
           for(int t=k;t<n-1;t++){
              if((j[k]/f[k])<(j[t+1]/f[t+1])){
                  temp=j[t+1];
                  j[t+1]=j[k];
                  j[k]=temp;
                  temp=f[t+1];
                  f[t+1]=f[k];
                  f[k]=temp;
               }
            }
        }
        for(int p=0;p<n;p++){
            if(m==0){
              break;
            }
            if(f[p]<=m){
               sum+=j[p];
               m-=f[p];
            }
            else if(m>0 && m<f[p]){
               sum+=m/f[p]*j[p];
               m=0;

            }
        }
        printf("%0.3f\n",sum);
    }
    return 0;
    
}