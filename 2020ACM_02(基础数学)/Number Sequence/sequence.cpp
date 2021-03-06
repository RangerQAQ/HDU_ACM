#include<iostream>
using namespace std;

/* 这个确实要用到循环节，公式为f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7
由前两项推出第三项，所以如果出现连续两项相同，后面的也完全相同，对7取余，结果为0~6，
一项有7种可能，将连续两项(2n+1,2n+2)看做一个循环节，则循环节共有7*7=49种可能，
所以根据抽屉原理，前50个循环节内，必然存在两个一样的循环节，第一个循环节后的序列为周期序列，
整个序列不一定是周期序列。例如序列:3、4项分别和13、14项相同，则从第3项开始，
这个序列才是周期序列，整个序列不一定是周期序列。所以算出前100项，
找出两个相同循环节(位置分别为a,b)，周期t=b-a，则从a开始，
这个序列为周期序列，n<=a，则直接输出，n>a，则输出第(n-a)%t+a项
*/

int main(){
    int a,b;
    int n;
    while(cin>>a>>b>>n && (a+b+n)!=0){
        int f[101];
        f[1]=1;
        f[2]=1;
        int tag1;
        int tag2;
        int t=-1;
        for(int i=3;i<=100;i++){
            f[i]=(a*f[i-1]+b*f[i-2])%7;
        }
        for(int j=1;j<100;j++){
            if(t != -1){
                break;
            }
            for(int k=j+1;k<100;k++){
                if((f[j]==f[k]) && (f[j+1]==f[k+1])){
                    tag1=j;
                    tag2=k;
                    t=k-j;
                    break;
                }

            }
        }
        if(n<=tag1)
		cout<<f[n]<<endl;
		else
		cout<<f[(n-tag1)%t+tag1]<<endl;
      

    }
    return 0;
}

