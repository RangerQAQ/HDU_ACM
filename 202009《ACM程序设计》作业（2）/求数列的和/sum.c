#include<stdio.h>
#include<math.h>

int main(){
    double n;
    while(scanf("%lf",&n)!=EOF){
        int m;
        scanf("%d",&m);
        double num=n;
        double temp;
        for(int i=1;i<m;i++){
            temp=pow(n,0.50);
            num=num+temp;
            n=temp;

        }
        printf("%.2lf",num);
        printf("\n");
    }
    return 0;
}