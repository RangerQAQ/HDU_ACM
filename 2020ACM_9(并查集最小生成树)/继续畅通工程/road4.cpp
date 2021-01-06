#include<iostream>
#include<algorithm>
using namespace std;
int bin[101];
int findx(int x)
{
    return bin[x]==x ? x : findx(bin[x]);  //查询操作：返回的是x的根结点
}

struct Edge{
    int a,b;
    int cost;
    int flag;
}edge[5000];//100个镇,两两相连,共4950条

bool cmp(Edge x,Edge y){
    return x.cost<y.cost; 
}

int main(){
    int n,i;
    while(scanf("%d",&n)&& n){
        int count=0;
        int N=n*(n-1)/2;
        for(i=1;i<=n;i++){
            bin[i]=i;
        }
        for(i=1;i<=N;i++){
            scanf("%d %d %d %d",&edge[i].a,&edge[i].b,&edge[i].cost,&edge[i].flag);
        }
        for(i=1;i<=N;i++){
            if(edge[i].flag==1){
                edge[i].cost=0;
            }
        }
        sort(edge+1,edge+1+N,cmp);       
        for(i=1;i<=N;i++){
            int p=findx(edge[i].a);
            int q=findx(edge[i].b);
            if(p==q){
               continue; 
            }
            bin[p]=q;
            count+=edge[i].cost;
        }
        cout<<count<<endl;
    }
    return 0;
}