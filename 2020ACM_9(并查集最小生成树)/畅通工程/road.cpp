#include<iostream>
using namespace std;

int bin[1001];
int findx(int x){
    int r=x;
    while(bin[r]!=r){
        r=bin[r];
    }
    return r;
}
void merge(int x,int y){
    int fx,fy;
    fx=findx(x);
    fy=findx(y);
    if(fx!=fy){
        bin[fx]=fy;
    }
}
int main(){
    int n,m,i,x,y,count;
    while(scanf("%d",&n)&& n){
        for(i=1;i<=n;i++){
            bin[i]=i;
        }
        scanf("%d",&m);
        while(m--){
            scanf("%d %d",&x,&y);
            merge(x,y);
        }
        count=0;
        for(i=1;i<=n;i++){
            if(bin[i]==i){
                count++;
            }
        }
        cout<<count-1<<endl;
    }
    return 0;
}