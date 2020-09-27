#include<iostream>
using namespace std;

int main(){
    
    int n;
    while(cin>>n && n!=0){
        int number=0;
        int add;
        for(int i=0;i<n;i++){
        cin>>add;
        number=number+add;
        }
     
        cout<<number<<"\n";
    }
    
    return 0;
}