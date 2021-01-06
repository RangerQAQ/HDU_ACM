#include<iostream>
using namespace std;
int N ;
int num[110] ;
int main(){
	while(scanf("%d",&N) && N){
		int sum = 0 ;
		for(int i=1;i<=N;i++){
			scanf("%d",&num[i]);
			sum = (sum ^ num[i]) ;
		}
		int ans = 0 ;
		for(int i=1;i<=N;i++){
			int s = sum ^ num[i] ;
			if(s < num[i])
				ans ++ ;
		}
		printf("%d\n",ans);
	}	
	return 0 ;
}