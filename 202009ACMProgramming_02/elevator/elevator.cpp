#include<iostream>
using namespace std;

int main(){
    int n;
    while(cin>>n && n!=0){
        int a,b;
        cin>>a;
        int num=6*a+5;
        for(int i=1;i<n;i++){
            cin>>b;
            if(b>a){
                num=num+6*(b-a)+5;
                a=b;
            }
            else{
                num=num+4*(a-b)+5;
                a=b;
            }

        }
        cout<<num<<endl;
    }
    return 0;
}