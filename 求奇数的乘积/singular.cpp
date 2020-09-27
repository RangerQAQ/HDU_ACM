#include<iostream>
using namespace std;

int main(){
    int n,a;
    while(cin>>n){ 
        int number=1;
        for(int i=0;i<n;i++){
        cin>>a;
        if(a%2==1){
            number=number*a;
        }
        }
        cout<<number<<"\n";
    }
    return 0;
}