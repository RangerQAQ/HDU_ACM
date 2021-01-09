#include<iostream>
using namespace std;

long long f[30][30][30]={0};
int dfs(int a,int b,int c){
    if(a<=0 || b<=0 || c<=0){
        return 1;
    }
    else if(a>20 || b>20 || c>20){
        return dfs(20,20,20);
    }
    else if(f[a][b][c]!=0){//已有数组记录
        return f[a][b][c]; 
    }
    else if(a<b && b<c){
        f[a][b][c]=dfs(a,b,c-1)+dfs(a,b-1,c-1)-dfs(a,b-1,c);
    }
    else{
        f[a][b][c]=dfs(a-1, b, c)+dfs(a-1, b-1, c)+dfs(a-1, b, c-1)-dfs(a-1, b-1, c-1);
    }
    return f[a][b][c]; 
}

int main(){
    int a,b,c;
    while(scanf("%d %d %d",&a,&b,&c)!=EOF){
        printf("%d\n",dfs(a,b,c));
    }
    return 0;
}