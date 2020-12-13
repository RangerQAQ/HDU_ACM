#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

struct node{
    int x;
    int y;
    int steps;
}start,end;

string s1,s2;
int x11,x22,y11,y22;
int vis[10][10];
int go[8][2]= {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};

int judge(int x,int y){
    if(x>0&&y>0&&x<=8&&y<=8&&!vis[x][y]){
        return 1;
    }
    else{
        return 0;
    }
}

void bfs(){
    queue<node>qu;
    memset(vis,0,sizeof(vis));
    start.x=x11;
    start.y=y11;
    start.steps=0;
    qu.push(start);  
    vis[x11][y11]=1;
    while(!qu.empty()){
        node cin,nex;    
        cin=qu.front();
        qu.pop();
        if(cin.x==x22 && cin.y==y22){
            cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<cin.steps<<" knight moves."<<endl;
            return;
        }
        for(int i=0;i<8;i++){
            int xx=cin.x+go[i][0];
            int yy=cin.y+go[i][1];
            
            if(judge(xx,yy)){
                nex.x=xx;
                nex.y=yy;
                nex.steps=cin.steps+1;
                vis[xx][yy]=1;
                qu.push(nex);
            }
        }
    }
    return;
}

int main(){
    while(cin>>s1>>s2){
        x11=s1[0]-'a'+1;
        y11=s1[1]-'1'+1;
        x22=s2[0]-'a'+1;
        y22=s2[1]-'1'+1;
        bfs();
    }
    return 0;
}