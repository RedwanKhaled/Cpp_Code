/*
*http://codeforces.com/contest/598/problem/A
*/

#include<stdio.h>

int main(){

	int n,i,j,m;	
	long long a[35],value=0,sum,index[35];
	
	index[0]=0;a[0]=1;value = 1;
	
	for(i=1;i<32;i++){	
			value *= 2; 
			a[i] = value +a[i-1]; 
			index[i] = value;
	} 
		
	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%d",&m);
		sum = m;
		sum *=(m+1);
		
		sum /=2;
				
		for(j=0;j<32;j++) if(m<index[j]) break;
		
		sum-=2*a[j-1];

		printf("%lld\n",sum);
	}
	return 0;
}
