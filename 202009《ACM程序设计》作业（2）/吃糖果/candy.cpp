#include<iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m;
        int f[m];
        int max=0;
        for(int j=0;j<m;j++){
            cin>>f[j];
            if(f[j]>max){
                max=f[j];
            }
        }
        long long sum=0;
        for(int k=0;k<m;k++){
            if(f[k]<max){
                sum=sum+f[k];
            }
        }
        if(max-sum>1)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;


    }
    return 0;
}