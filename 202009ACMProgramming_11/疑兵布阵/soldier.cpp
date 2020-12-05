#include<iostream>
#include<cstring>
using namespace std;

int a[50001],c[50001];
int n;
int lowbit(int x){//求二进制数从右往左数第一个1
    return x & -x;
}

int sum(int i){//求前缀和
    int ret=0;
    while(i>0){
        ret+=c[i];
        i-=lowbit(i);
    }
    return ret;
}

void update(int i,int val){
    while(i<=n){
        c[i]+=val;
        i+=lowbit(i);
    }
}

int main(){
    int t;
    cin>>t;
    int k=1;
    while(t--){
        cout<<"Case "<<k<<":"<<endl;
        k++;
        cin>>n;
        memset(a,0,sizeof(a));
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            update(i,a[i]);
        }
        string s;
        int g,h;
        while(cin>>s && s[0]!='E'){
            cin>>g>>h;
            if(s[0]=='A'){
                update(g,h);
            }
            else if(s[0]=='S'){
                update(g,-h);
            }
            else if(s[0]=='Q'){
                cout<<sum(h)-sum(g-1)<<endl;
            }
        }
    }
    return 0;
}