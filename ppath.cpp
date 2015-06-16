#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>

using namespace std;

#define MAX 10005

int a[MAX];

int prime[2005],np,path[2000];

struct point{

  int value,pos;
};

void gen(){

  memset(a,0,sizeof(a));

  for(int i=3;i<MAX;i+=2){

    if(a[i]==0){
      if(i>1000 && i<10000) prime[np++]=i;

      for(int j=i*i;j<MAX;j+=i) a[j] = 1;
    }
  }
  
}

int digit_distance(int d1,int d2){

  int add=0;
  while(d1 && d2){
    if(d1%10 != d2%10) add++;
    d1/=10;
    d2/=10;
  }

  return add;
}

int solve(int src,int dst){
  
  int i,dd;
  queue<point> Q;

  while(!Q.empty()) Q.pop();
  
  int pos_src,pos_dst;
 
  for(i=0;i<np;i++){
    if(prime[i] == src) pos_src = i;
    if(prime[i] == dst) pos_dst = i;
  }
  for(i=0;i<np;i++) path[i] = -1;

  path[pos_src] = 0;

  point x,y;
  x.value = src;
  x.pos = pos_src;

  Q.push(x);

  while(!Q.empty()){
    x = Q.front();
    Q.pop();
    if(x.value == dst) return path[x.pos];

    for(i=0;i<np;i++){
      if(path[i]==-1){
	dd = digit_distance(x.value,prime[i]);
	if(dd==1){
	  y.value = prime[i];
	  y.pos = i;
	  path[y.pos] = path[x.pos] + 1;
	  if(y.value == dst) return path[y.pos];
	  Q.push(y);
	}
      }
    }
  }
  return -1;
}

int main(){

  int T,i,src,dst;
  np=0;

  gen();

  // printf("%d\n",np);
  //for(i=0;i<10;i++) printf("%d ",prime[i]);
  //puts("");

  scanf("%d",&T);

  while(T--){
    scanf("%d%d",&src,&dst);

    int sol = solve(src,dst);
    if(sol!=-1)printf("%d\n",sol);
    else puts("Impossible");
  }
  return 0;
}
