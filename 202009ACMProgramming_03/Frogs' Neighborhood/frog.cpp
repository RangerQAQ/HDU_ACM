#include<iostream>
#include<algorithm>
using namespace std;

struct Node
{
    int degree;//度数
    int index;//序号
};

bool cmp(Node a,Node b){
    return a.degree>b.degree;
}
int main(){
    int i,n,m;
    cin>>n;
    while(n--){
        cin>>m;
        Node f[m];
        int k[m][m];
        for(i=0;i<m;i++){
            for(int q=0;q<m;q++){
                k[i][q]=0;
            }
        }
        for(i=0;i<m;i++){
            cin>>f[i].degree;
            f[i].index=i;
        }
        sort(f,f+m,cmp);

        int tag=1;
        int num=0;
        while(tag==1 && num<m){
            int a=f[num].degree;
            for(i=0;i<a;i++){                
                if(f[num+1+i].degree>=1){
                    k[f[num].index][f[num+1+i].index]=1;
                    k[f[num+1+i].index][f[num].index]=1;
                }
                f[num+1+i].degree--;
            }
            f[num].degree=0;
            num++;
            sort(f+num,f+m,cmp);
            for(int j=0;j<m+2;j++){
                if(f[j].degree<0){
                    tag=0;
                }
            }
        }

        if(tag==0){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            for(i=0;i<m;i++){
                for(int s=0;s<m;s++){
                    cout<<k[i][s]<<" ";                
                }
                cout<<endl;
            }
            
        }
        if(n>0){
            cout<<endl;
        }
    }
    return 0;
}