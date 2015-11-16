/*
*http://codeforces.com/contest/598/problem/B
*/


#include<stdio.h>
#include<string.h>

int main(){

	int l,r,k,sz,n,range,i;

	char s[10005],ch[10005];

	scanf("%s",s+1);
	scanf("%d",&n);

	while(n--){

		scanf("%d%d%d",&l,&r,&k);
		
		
		range = r - l +1;
		k = k%range;
		

		for(i=r;i>r-k;i--)
			ch[r-i] = s[i];
		

		for(i=0;i<range - k;i++)
			s[r-i] = s[r-k-i];
		
		for(i=0;i<k;i++)
			s[l+i] = ch[k-i-1];
		
	}
	
	printf("%s\n",s+1);
	
	return 0;
}
