#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int number=0;
        int add,a;
        cin>>a;
        for(int j=0;j<a;j++){
            cin>>add;
            number=number+add;
        }
        cout<<number<<"\n";
        cout<<endl;
    }
    int m,b;
    cin>>m;
    int a=0;
    for(int k=0;k<m;k++){
        cin>>b;
        a=a+b;
    }
    cout<<a<<"\n";

    return 0;
}