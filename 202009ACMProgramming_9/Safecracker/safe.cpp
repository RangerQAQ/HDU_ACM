#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

bool cmp(char a,char b){
    return a>b;
}

int cal(int v,int w,int x,int y,int z){
    return v-w*w+x*x*x-y*y*y*y+z*z*z*z*z;
}
int target;

bool judge(int v,int w,int x,int y,int z){
    return cal(v,w,x,y,z)==target;
}

bool vis[15];
char ans[15],str[15],handle[15];
bool dfs(int num){
   if(num == 5){
       handle[5]='\0';//结束,可输出五个字符
       if(judge(handle[0]-'A'+1,handle[1]-'A'+1,handle[2]-'A'+1,handle[3]-'A'+1,handle[4]-'A'+1)){
           strcpy(ans,handle);
           return true;
       }
       else{
           return false;
       }
   }
   else{
       int len=strlen(str);
       for(int i=0;i<len;i++){
           if(!vis[i]){
               handle[num]=str[i];
               vis[i]=true;
               if(dfs(num+1)){
                   return true;
               }
               vis[i]=false;//回溯
           }
       }
   }
   return false;
}

int main(){
   while(~scanf("%d %s",&target,&str)){//~是按位取反 scanf的返回值是输入值的个数 如果没有输入值则返回-1 对于-1按位求反得到0 所以如果没有输入则退出循环  
      if(target == 0 && strcmp("END",str)==0)
      {
        break;
      }
      int len=strlen(str);
      sort(str,str+len,cmp);
      memset(vis,0,sizeof(vis));
      //剪枝(最大减最小)
      if(cal(str[0]-'A'+1,str[len-1]-'A'+1,str[0]-'A'+1,str[len-1]-'A'+1,str[0]-'A'+1) < target){
        printf("no solution\n");
        continue;//推出这次循环
      }
      if(dfs(0)){
        printf("%s\n",ans);
      }
      else{
        printf("no solution\n");  
      }
   } 
   return 0;
}