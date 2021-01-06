#include<iostream>
using namespace std;

int f[10000001],vis[10000001];
int n;
int ans=1;

int find(int x)       //查找x元素所在的集合,回溯时压缩路径
{
    if (x != f[x])
    {
        f[x] = find(f[x]);     //回溯时的压缩路径
    }         //从x结点搜索到祖先结点所经过的结点都指向该祖先结点
    return f[x];
}
void merge(int x,int y){
    int fx=find(x);
    int fy=find(y);
    if(fx==fy){
       return;
    }
    f[fx]=fy;
    vis[fy]+=vis[fx];
    if(vis[fy]>ans){
        ans=vis[fy];
    }

}

void init(){
    for(int i=0;i<10000001;i++){
        f[i]=i;
        vis[i]=1;
    }
}
int main(){
    while(~scanf("%d",&n)){
        ans=1;
        init();
        for(int j=0;j<n;j++){
            int xx,yy;
            scanf("%d %d",&xx,&yy);
            merge(xx,yy);
        }
        cout<<ans<<endl;
    }
}