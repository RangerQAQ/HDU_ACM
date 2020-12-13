#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

struct node{
    int x;
    int y;
    int z;
    int t;
}start;

int a,b,c,t;
int f[55][55][55];
int vis[55][55][55];
int go[6][3]= {{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};

int judge(int x,int y,int z){
    if(x>=0 && y>=0 && z>=0 && x<a && y<b && z<c && !vis[x][y][z] && f[x][y][z]==0){
        return 1;
    }
    else{
        return 0;
    }
}

void bfs(){
    queue<node>qu;
    memset(vis,0,sizeof(vis));
    start.x=0;
    start.y=0;
    start.z=0;
    start.t=0;
    qu.push(start);  
    vis[0][0][0]=1;
    while(!qu.empty()){
        node cin,nex;    
        cin=qu.front();
        qu.pop();
        if(cin.x==(a-1) && cin.y==(b-1) && cin.z==(c-1)){
            if(cin.t<=t){
                cout<<cin.t<<endl;
                return;
            }
            else{
                cout<<-1<<endl;
                return;
            }
            
        }
        for(int i=0;i<6;i++){
            int xx=cin.x+go[i][0];
            int yy=cin.y+go[i][1];
            int zz=cin.z+go[i][2];
            
            if(judge(xx,yy,zz)){
                nex.x=xx;
                nex.y=yy;
                nex.z=zz;
                nex.t=cin.t+1;
                vis[xx][yy][zz]=1;
                qu.push(nex);
            }
        }
    }
    cout << -1 << endl;
}

int main(){
    int n;
    cin>>n;
    while(n--){
        scanf("%d %d %d %d",&a,&b,&c,&t);
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                for(int k=0;k<c;k++){
                    scanf("%d",&f[i][j][k]);
                }
            }
        }
        bfs();
    }
    return 0;
}