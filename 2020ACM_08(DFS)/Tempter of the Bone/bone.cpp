#include<iostream>
#include <stdlib.h>
using namespace std;

char Map[9][9];
int n,m,t,di,dj;
bool escape;
int dir[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};

void dfs(int si,int sj,int cnt);

int main(){
    int i,j,si,sj,temp;
    while(cin>>n>>m>>t){
      if(n==0 && m==0 && t==0)
        break;
      int wall=0;//障碍物数
      for(i=1;i<=n;i++){//i从1开始,这样一开始往左走-1为0,虽不合规但仍在数组Map内
        for(j=1;j<=m;j++){
              cin>>Map[i][j];
              if(Map[i][j]=='S'){
                si=i;
                sj=j;
              }
              else if(Map[i][j]=='D'){
                di=i;
                dj=j;
              }
              else if(Map[i][j]=='X'){
                wall++;
              }
        }
      }
      if(n*m-wall<=t){//人停留一秒后格子消失
        cout<<"NO"<<endl;
        continue;//结束本次循环
      }
      temp=t-abs(si-di)-abs(sj-dj);
      if(temp%2 == 1 || temp < 0){//t和两点坐标差一定要满足奇-奇或偶-偶的关系
        cout<<"NO"<<endl;
        continue;//结束本次循环
      }
      escape=0;
      Map[si][sj] = 'X';
      dfs(si,sj,0);
      if(escape){
        cout<<"YES"<<endl;
      }
      else{
        cout<<"NO"<<endl;
      }
    }
    return 0;
}

void dfs(int si,int sj,int cnt){
  int i;
  if(si>n || sj>m || si<=0 || sj<=0){
    return;
  }
  if(cnt==t && si==di && sj==dj){
    escape=1;
  }
  if(escape){
    return;
  }
  for(i=0;i<4;i++){
    if(Map[si+dir[i][0]][sj+dir[i][1]]!='X'){
      Map[si+dir[i][0]][sj+dir[i][1]]='X';
      dfs(si+dir[i][0],sj+dir[i][1],cnt+1); 
      Map[si+dir[i][0]][sj+dir[i][1]]='.'; //回溯
    }
  }
  return;
}