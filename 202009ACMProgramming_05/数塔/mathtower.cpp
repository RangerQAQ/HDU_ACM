#include<iostream>
using namespace std;

int p[101][101]={0};

int compare(int a,int b){
    if(p[a+1][b]>p[a+1][b+1])
       return p[a][b]+p[a+1][b];
    else
       return p[a][b]+p[a+1][b+1];
}
int main(){
    int m;
    cin>>m;
    while(m--){
        int num,i,j;
        cin>>num;
        
        for(i=0;i<num;i++){
            for(j=0;j<=i;j++){
                cin>>p[i][j];
            }
        }
        for(i=num-2;i>=0;i--){
            for(j=0;j<=i;j++){
                p[i][j]=compare(i,j);
            }
        }
        cout<<p[0][0]<<endl;
    }
    return 0;
}