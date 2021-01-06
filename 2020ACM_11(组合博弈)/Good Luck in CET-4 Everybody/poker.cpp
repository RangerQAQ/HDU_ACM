#include <iostream>//必胜必败点判断,找规律
using namespace std;
 
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n%3==0) printf("Cici\n");
        else printf("Kiki\n");
    }
    return 0;
}