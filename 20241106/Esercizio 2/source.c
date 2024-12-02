#include<stdio.h>

int max(int n, int m);

int main(){
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
	printf("%d\n", max(n,m));
	return 0;
}

int max(int n, int m){
	return n>m?n:m;
}
