#include<iostream>
using namespace std;

int main(){
    int m,n;
    int k=1;
    while(scanf("%d %d",&m,&n) && (m+n)>=0){
        int i=0;//节点数
        int j=0;//边数
        int tag=0;
        int f[100000]={0};
        while((n+m)!=0){
            if(f[n]==2){//n已经做过子节点
               tag=1;
            }
            if(f[n]==0)
               i++;
            if(f[m]==0)
               i++;
            f[n]=2;
            f[m]=1;
            j++;
            scanf("%d %d",&m,&n);
        }
        if(tag==0 && i==j+1)
            cout<<"Case "<<k<<" is a tree."<<endl;
		else
            cout<<"Case "<<k<<" is not a tree."<<endl;
		
        k++;
    }
}