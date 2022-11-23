#include <stdio.h>

int main(){
	int t; scanf("%d", &t);
	while (t--){
		int n; scanf("%d", &n);
		int a[10]={1000,500,200,100,50,20,10,5,2,1};
		int ans=0;
		int i=0;
		while (n>0){
			int tmp=n/a[i];
			ans+=tmp;
			n-=tmp*a[i];
			++i;
		}
		printf("%d\n", ans);
	}
	return 0;
}
