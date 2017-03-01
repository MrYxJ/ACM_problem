#include<bits/stdc++.h>
using namespace std;
bool check(int a,int b)
{
    int v[10]={0};
    if(a>98765) return false;
    if(b<10000) v[0]=1;
    while(a){
        v[a%10]=1;
        a/=10;
    }
    while(b){
        v[b%10]=1;
        b/=10;
    }
    int num=0;
    for(int i=0;i<10;i++) num+=v[i];
    return num==10;
}

int main()
{
    int n,cnt=0;
    while(scanf("%d",&n)&&n){
       int t=0;
       if(cnt++) printf("\n");
       bool ok=false;
       for(int i=1234;i<=98765;i++){
          if(check(i*n,i)){
             ok=true;
             t++;
             printf("%05d / %05d = %d\n",i*n,i,n);
          }
       }
       printf("%d\n",t);
       if(!ok) printf("There are no solutions for %d.\n",n);
    }
}
