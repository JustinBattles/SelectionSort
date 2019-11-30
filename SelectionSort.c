#include<stdio.h>
#include<time.h>
#define SZ 300000

long a[SZ];

//return the index of the largest value in the array
//between index 0 and index (n-1)
int indxLargest(int n) {
  int indx = 0;
  int i;
  for(i=1; i<n; i++)
    if (a[i]>a[indx])
       indx = i;
  return indx;
}

int main() {
  //read in the numbers
  FILE *fp = fopen("num2", "r");
  int n=0;
  while( fscanf(fp, "%ld", a+n)==1)
    n++;
  printf("%d\n", n);  
  int n0=n;
  //sort the numbers
  long t0 = time(0);
  printf("%ld\n", t0);
  while (n>0)   {
      int indx = indxLargest(n);
      //swap a[indx] with a[n-1]
      n--;
      long tmp = a[indx];
      a[indx]=a[n];
      a[n] = tmp;
  }
  printf("%ld\n", time(0)-t0);
  //
  //check
  int i;
  for(i=1; i<n; i++)
    if (a[i]<a[i-1]) printf("Not sorted");
}
