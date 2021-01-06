#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

struct node{
    int a;//a是容量大的杯子
    int b;
    int s;
    int t;//次数
}start;

int a,b,s;
int vis[105][105];//用vis[a][b]记录状态,因为s可用a,b表示

int bfs(){
    queue<node>qu;
    memset(vis,0,sizeof(vis));
    start.s=s;
    start.a=0;
    start.b=0;
    start.t=0;
    qu.push(start);
    vis[a][b]=1;
    while(!qu.empty()){
        node cin,nex;
        cin=qu.front();
        qu.pop();
        if(cin.a==s/2 && cin.s==s/2){
            return cin.t;
        }
        if(cin.s && cin.a!=a){//s->a
            int c=a-cin.a;
            if(cin.s>=c){
                nex.a=a;
                nex.s=cin.s-c;
            }
            else{
               nex.s=0;
               nex.a=cin.a+cin.s; 
            }
            nex.b=cin.b;
            nex.t=cin.t+1;
            if(!vis[nex.a][nex.b]){
                qu.push(nex);
                vis[nex.a][nex.b]=1;
            }
        }
        if(cin.s && cin.b!=b){//s->b
            int c=b-cin.b;
            if(cin.s>=c){
                nex.b=b;
                nex.s=cin.s-c;
            }
            else{
               nex.s=0;
               nex.b=cin.b+cin.s; 
            }
            nex.a=cin.a;
            nex.t=cin.t+1;
            if(!vis[nex.a][nex.b]){
                qu.push(nex);
                vis[nex.a][nex.b]=1;
            }
        }
        if(cin.a && cin.s!=s){//a->s
            int c=s-cin.s;
            if(cin.a>=c){
                nex.s=s;
                nex.a=cin.a-c;
            }
            else{
               nex.a=0;
               nex.s=cin.a+cin.s; 
            }
            nex.b=cin.b;
            nex.t=cin.t+1;
            if(!vis[nex.a][nex.b]){
                qu.push(nex);
                vis[nex.a][nex.b]=1;
            }
        }
        if(cin.b && cin.s!=s){//b->s
            int c=s-cin.s;
            if(cin.b>=c){
                nex.s=s;
                nex.b=cin.b-c;
            }
            else{
               nex.b=0;
               nex.s=cin.b+cin.s; 
            }
            nex.a=cin.a;
            nex.t=cin.t+1;
            if(!vis[nex.a][nex.b]){
                qu.push(nex);
                vis[nex.a][nex.b]=1;
            }
        }
        if(cin.a && cin.b!=b){//a->b
            int c=b-cin.b;
            if(cin.a>=c){
                nex.b=b;
                nex.a=cin.a-c;
            }
            else{
               nex.a=0;
               nex.b=cin.a+cin.b; 
            }
            nex.s=cin.s;
            nex.t=cin.t+1;
            if(!vis[nex.a][nex.b]){
                qu.push(nex);
                vis[nex.a][nex.b]=1;
            }
        }
        if(cin.b && cin.a!=a){//b->a
            int c=a-cin.a;
            if(cin.b>=c){
                nex.a=a;
                nex.b=cin.b-c;
            }
            else{
               nex.b=0;
               nex.a=cin.a+cin.b; 
            }
            nex.s=cin.s;
            nex.t=cin.t+1;
            if(!vis[nex.a][nex.b]){
                qu.push(nex);
                vis[nex.a][nex.b]=1;
            }
        }

    }
    return 0;//都不能平分
}
int main(){
    while(scanf("%d%d%d",&s,&a,&b),s||a||b){
        if(s%2){
            cout<<"NO"<<endl;
            continue;
        }
        if(a<b)
           swap(a,b);
        int ans=bfs();
        if(ans)
           cout<<ans<<endl;
        else
           cout<<"NO"<<endl;
    }
    return 0;
}