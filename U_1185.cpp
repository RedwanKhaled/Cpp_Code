

/*
  Link: https://uva.onlinejudge.org/external/11/1185.html
  Date: Sept. 5,2015
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


#define MAX 10000005
int ar[MAX];

void gen(){
  double value = 0;
int i;
  for(i=1;i<MAX;i++){
    value += log10(i);
    ar[i] = (int)value + 1;
  }


}

int main(){

  int N,x;

  gen();

  scanf("%d",&N);

  while(N--){
    scanf("%d",&x);
    printf("%d\n",ar[x]);

  }

}
