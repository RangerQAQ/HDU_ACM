#include<iostream>
using namespace std;

int main(){
    int n,temp;
    
    
    cin>>n;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        int max=0;
        int p[203]={0};
        for(int j=0;j<m;j++){
            int a,b;
            cin>>a>>b;
            if(a>b){
                temp=a;
                a=b;
                b=temp; 
            }
            for(int k=(a+1)/2;k<=(b+1)/2;k++){  //因为房间在两侧,所以例如3到1和4到6中3和4同时的话会堵住
                p[k]++;
            }
        }
        for(int s=0;s<203;s++){
            if(p[s]>max){
                max=p[s];
            }
        }
        cout<<10*max<<endl;
    }
    return 0;
}