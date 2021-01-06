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
    int t,n,m,i,x,y,count;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++){
            bin[i]=i;
        }
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
        cout<<count<<endl;
    }
    return 0;
}