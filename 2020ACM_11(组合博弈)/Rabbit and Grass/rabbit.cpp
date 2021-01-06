#include<iostream>

using namespace std;
int m,a;
int main(){
    while(scanf("%d",&m)&&m){
        int ans = 0;
        for(int i=0;i<m;i++){
            scanf("%d",&a);
            ans ^= a;//只要最后ans==0 ,就叫奇异局势，谁面对奇异局势都将失败
        }
        if(ans!=0) printf("Rabbit Win!\n");
        else printf("Grass Win!\n");
    }
    return 0;
}