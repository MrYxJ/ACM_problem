#include<bits/stdc++.h>
using namespace std;
void print_subset1(int n,int *A,int cur)
{
    for(int i=0;i<cur;i++){

    }
}
void print_subset2(int n,int *A,int *B,int cur)
{
    if(cur==n){
        for(int i=0;i<cur;i++){
            if(B[i]) printf("%d ",A[i]);
        }
        printf("\n");
        return;
    }
    B[cur]=1;
    print_subset2(n,A,B,cur+1);
    B[cur]=0;
    print_subset2(n,A,B,cur+1);
}

void print_subset3(int n,int s){
  for(int i=0;i<n;i++){
    if(s&(1<<i)) printf("%d ",i);
  }
  printf("\n");
}

int main()
{

    int n,j;
    while(~scanf("%d",&n)){
        /*
        int b[n+1];
        for(int i=0;i<n;i++) scanf("%d",&b[i]);
        int a[n+1];
        print_subset2(n,b,a,0);
        */
        //for(int i=0;i<(1<<n);i++) print_subset3(n,i);
        for(int i=0;i<(1<<n);i++){
            for(j=0;j<n;j++){
                if(i>>j&1) printf("%d ",j);
            }
            printf("\n");
        }
    }
}
