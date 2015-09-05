

/**
  Name: Bear and Elections
  Link: http://codeforces.com/contest/574/problem/A
  Div2 A(Easy)
*/

#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){

  int a,b,ar[105],mx=0,index,n,i,add=0;

  scanf("%d",&n);

  for(i=0;i<n;i++) scanf("%d",ar+i);

  while(1){
    sort(ar+1,ar+n);
    if(ar[0]>ar[n-1]) break;
    else{

      ar[0]++;
      ar[n-1]--;
      add++;
    }
  }

  printf("%d\n",add);

  return 0;
}
