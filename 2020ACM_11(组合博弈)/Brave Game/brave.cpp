#include<iostream>
using namespace std;

void judge(int n,int m){
    int num=n%(m+1);
    if(num==0){
        cout<<"second"<<endl;
    }
    else{
        cout<<"first"<<endl;
    }
}
int main(){
    int c;
    cin>>c;
    while(c--){
        int n,m;
        cin>>n>>m;
        judge(n,m);
    }
    return 0;
}