#include<iostream>
#include<algorithm>
#include <cmath>
using namespace std;

const int N = 100010;
const int inf =10e8;


struct point{
    double x;
    double y;
}f[N];

int tmp[N];

bool cmpx(point a,point b){
	return a.x < b.x;
}
bool cmpy(int a,int b){
//对存有结构体下标的数组进行排序，这样就可以不改变结构体的情况下使其有序 
	return f[a].y < f[b].y;
}

double dis(point a,point b){   
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

double closest_pair(int l,int r){
	if(l == r)	return inf;//返回无穷大 
	if(l + 1 == r)	return dis(f[l],f[r]);//仅有俩个点，故此区间最短距离为 
	int mid = l+(r-l)/2;
	double d = min(closest_pair(l,mid),closest_pair(mid+1,r));
	int cnt = 0;
	for(int i = l;i <= r;i++)
		if(fabs(f[i].x-f[mid].x) <= d)	tmp[cnt++] = i;
	sort(tmp,tmp+cnt,cmpy);
	for(int i = 0;i < cnt;i++){
		for(int j = i+1;j < cnt && f[tmp[j]].y - f[tmp[i]].y < d;j++){
			double d2 = dis(f[tmp[i]],f[tmp[j]]);
			if(d2 < d){
				d = d2;
				break;
			} 
		}
    }
	return d;
}


int main(){
    int n,i;
    while(scanf("%d",&n) && n){
        
        for(i=0;i<n;i++){
            scanf("%lf%lf",&f[i].x,&f[i].y);
        }
        sort(f,f+n,cmpx);
        printf("%.2lf\n",closest_pair(0,n-1)/2);
    }
    return 0;
}