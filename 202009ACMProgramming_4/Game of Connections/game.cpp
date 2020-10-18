//卡特兰数，需要做大数处理 
//https://blog.csdn.net/zuzhiang/article/details/77920115?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-2.edu_weight&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-2.edu_weight
#include<stdio.h>
#include<string.h>
typedef long long LL;
 
LL mod=1e9;    //mod用于计算本位存储9位的结果和计算进位 
LL a[101][10]; //a[i][j]用于保存N=i的时候第j位的结果 
 
void init()
{ //初始化函数打表 
	int i,j,x,y,c;
	//注意sum数组的大小应该是a[i]的2倍 
	LL sum[20]; //sum为临时数组，先将结果保存到sum再转存回a[i] 
	memset(a,0,sizeof(a));
	a[1][0]=1; //初始化N=1,N=2,N=3时候的结果 
	a[2][0]=2;
	a[3][0]=5;
	for(i=4;i<101;i++)
	{ //计算N从1~100的结果 
		memset(sum,0,sizeof(sum));
		for(j=0;j<10;j++)
		{ //这里是计算当连线将剩余点分成1组时候的结果 
			sum[j]+=(2*a[i-1][j]);  //本位值 
			sum[j+1]+=sum[j]/mod;   //本位对更高位的进位 
			sum[j]%=mod;			//本位%1e9,保证个变量保存9位数值 
		}
		for(j=1;j<i-1;j++) //j是分成2组的时候，两边剩余点对应的N的值 
			for(x=0;x<10;x++) //x是a[j]指向大数的第x位 
				for(y=0;y<10;y++) //y是a[i-1-j]指向大数的第y位
				{
					sum[x+y]+=a[j][x]*a[i-1-j][y]; //本位是两个分组的种类相乘 
					sum[x+y+1]+=sum[x+y]/mod;      //对更高位的影响 
					sum[x+y]%=mod;                 //本位%1e9,保证个变量保存9位数值 
				}
		for(j=0;j<10;j++) a[i][j]=sum[j];     //转存回a[i] 
	} 
}
 
int main()
{
	int i,n;	
	init(); //先打表 
	while(~scanf("%d",&n) && n!=-1)
	{
		i=9;
		while(a[n][i]==0) i--; //从最高位开始寻找第一个不为0的数，则i就是结果的最高位 
		printf("%lld",a[n][i]); //输出最高位 
		i--;
		while(i>=0)
		{
			printf("%0.9lld",a[n][i]); //注意是%0.9lld，如果本位不足9位则前面补0 
			i--;
		}
		printf("\n");
	}
	return 0;
}