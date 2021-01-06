#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(int a,int b){
    return a>b;
}

int main(){
    int n;
    cin>>n;
    for(int k=0;k<n;k++){
        int m;
        cin>>m;
        int f[1001]={0};
        for(int t=0;t<m;t++){
            cin>>f[t];
        }
        sort(f,f+m,cmp);

        int tag=1;
        int num=0;
        while(tag==1 && num<m){
            int a=f[num];
            for(int i=0;i<a;i++){
                f[num+1+i]--;
            }
            f[num]=0;
            num++;
            sort(f+num,f+m,cmp);
            for(int j=0;j<m+2;j++){
                if(f[j]<0){
                    tag=0;
                }
            }
        }
        if(tag==0){
            cout<<"no"<<endl;
        }
        else{
            cout<<"yes"<<endl;
        }

    }
    return 0;
}