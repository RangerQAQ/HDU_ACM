#include<iostream>
using namespace std;

int main(){
    int n,m;
    while(cin>>n>>m &&(n+m)){
        if(n%2 && m%2){
            cout<<"What a pity!"<<endl;
        }
        else{
            cout<<"Wonderful!"<<endl;
        }
    }
    return 0;
}