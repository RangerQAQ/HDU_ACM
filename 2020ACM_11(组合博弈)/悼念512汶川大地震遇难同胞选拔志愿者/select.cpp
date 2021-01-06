#include<iostream>
using namespace std;

int main(){
    int c;
    cin>>c;
    while(c--){
        int n,m;
        cin>>n>>m;
        if(n<=m){
            cout<<"Grass"<<endl;
        }
        else{
            if(n % (m+1)==0){
                cout<<"Rabbit"<<endl;
            }
            else{
                cout<<"Grass"<<endl;
            }
        }
    }
    return 0;
}