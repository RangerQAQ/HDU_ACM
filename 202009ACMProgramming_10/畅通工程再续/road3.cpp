#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int bin[101];
struct node{
    int x;
    int y;
}a[101];
int findx(int x)
{
    return bin[x]==x ? x : findx(bin[x]);  //查询操作：返回的是x的根结点
}

struct Edge{
    int a,b;
    double cost;
}edge[5000];

bool cmp(Edge x,Edge y){
    return x.cost<y.cost; 
}

int main(){
    int n,i,m,j;
    scanf("%d",&n);
    while(n--){
        double count=0.0;
        int num=1;
        scanf("%d",&m);
        for(i=1;i<=m;i++){
            scanf("%d %d",&a[i].x,&a[i].y);
            bin[i]=i;
        }
        int N=m*(m-1)/2;
        for(i=1;i<=m;i++){
            for(j=i+1;j<=m;j++){
                edge[num].a=i;
                edge[num].b=j;
                int t=(a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y);       
                if(t>=100 && t<=1000000){
                    edge[num].cost=1.0*100*sqrt(t);
                }
                else{
                    edge[num].cost=999999;
                }
                num++;               
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
        int h=0;
        for(i=1;i<=m;i++){
            if(bin[i]==i){
                h++;
            }
        }
        if(h==1){
            printf("%.1f\n",count);
        }
        else{
            cout<<"oh!"<<endl;
        }
    }
    return 0;
}