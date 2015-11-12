/*
*	http://www.spoj.com/problems/PRIME1/
*	11/11/2015 09:43:28 PM 
*
*/



#include<stdio.h>
#include<string.h>

#define MAX 15000
int prime[MAX],np;


int gen(){				//Sieve of Eratosthenes

	int a[32005];
	memset(a,0,sizeof(a));
	int i,j;
	np = 0;
	prime[np++] = 2;
	
	for(i=3;i<32000;i+=2){
	
		if(!a[i]){
			prime[np++] = i;
			
			for(j=i*i;j<32000;j+=i) a[j]=1;
		}
	}

}


void solve(int lo,int hi){

	
	if(lo<=2 || lo==2) puts("2");	//Special case for 2
	if(lo%2==0) lo++;
	
	int a[hi-lo+5],i,j;

	memset(a,0,sizeof(a));			//Sets the first num bytes of the block of memory pointed by ptr to the specified value



	int value = lo;
	for(;lo<=hi;lo+=2)
		if(!a[lo-value]){
		
			if(lo<=2) continue;
			int found=0;
			
			for(i = 0;i<np;i++){
				
				if(lo%prime[i]==0){
					if(lo==prime[i]) printf("%d\n",lo);

					for(j=2*prime[i];j+lo<=hi;j+=prime[i])
						a[lo+j - value]=1;
					
					found = 1;
					break;
				}
			}
			if(!found) printf("%d\n",lo);
		}

}
int main(){

	gen();				// generating prime
	
	int t,lo,hi;
	scanf("%d\n",&t);
	
	while(t--){
	
		scanf("%d%d",&lo,&hi);
		solve(lo,hi);
		puts("");
	}
	return 0;
}
