#include<bits/stdc++.h>
using namespace std;
int dpmin[1010],dpmax[1010],a[1010],min_coin[1010],max_coin[1010],n;
const int inf=0x7ffffff;

void print_ans(int *d,int s){
   while(s){
       printf("%d ",d[s]);
       s-=a[d[s]];
   }
}

int main(){
    int s;
    while(~scanf("%d%d",&n,&s)){
         for(int i=0;i<n;i++) scanf("%d",&a[i]);
         for(int i=0;i<=s;i++){
            dpmin[i]=inf;
            dpmax[i]=-inf;
         }
         dpmin[0]=0;dpmax[0]=0;
         for(int i=1;i<=s;i++){
           for(int j=0;j<n;j++){
              if(dpmin[i]>dpmin[i-a[j]]+1){
                dpmin[i]=dpmin[i-a[j]]+1;
                min_coin[i]=j;
              }
              if(dpmax[i]<dpmax[i-a[j]]+1){
                dpmax[i]=dpmax[i-a[j]]+1;
                max_coin[i]=j;
              }
           }
         }
         printf("%d %d\n",dpmax[s],dpmin[s]);
         print_ans(max_coin,s);
         cout<<endl;
         print_ans(min_coin,s);
    }
}
