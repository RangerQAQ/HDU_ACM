#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int number=0;
        int add,a;
        cin>>a;
        for(int j=0;j<a;j++){
            cin>>add;
            number=number+add;
        }
        cout<<number<<"\n";
    }
    return 0;
}