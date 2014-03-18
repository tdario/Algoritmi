#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int ric_b(int *,int,int,int);

int main(void)
{
    
  LARGE_INTEGER a, b, oh, freq;
  double tempo;      
  int *v,n,i,num;
  
  n=10000;
  
  v=malloc(n*sizeof(int)); //allocazione memoria vettore
  for(i=0; i<n; i++)  //assegnazione valore
  {
    v[i]=i;
  }
  for(i=0; i<n; i++)  //stampa
  {
    printf("%d\n",v[i]);         
  }
  
  printf("\n%d elementi\n",n);
  num=2468;
  printf("\nelemento da ricercare %d\n",num);
  
  QueryPerformanceFrequency(&freq);
  QueryPerformanceCounter(&a);
  QueryPerformanceCounter(&b);
  oh.QuadPart = b.QuadPart - a.QuadPart;
  QueryPerformanceCounter(&a);
  
  if(ric_b(v,num,0,n-1)!=-1)  printf("l'elemento si trova al %d^ posto\n",ric_b(v,num,0,n-1));
  else printf("elemento non trovato\n");
  
  QueryPerformanceCounter(&b);
  tempo = (double)(b.QuadPart - a.QuadPart - oh.QuadPart)/freq.QuadPart;  
  printf("\ntempo: %f\n",tempo);  
  
  free(v);  //deallocazione memoria
  system("PAUSE");	
  return 0;
}

int ric_b(int *vett,int ele,int i,int f)
{
  int m;
  if(i>f) return -1;
  else 
  {
    m=(i+f)/2;
    if(vett[m]==ele)  return m+1;
    else
      if(ele<vett[m]) return(ric_b(vett,ele,i,m-1));
      else return(ric_b(vett,ele,m+1,f));
  }
}
