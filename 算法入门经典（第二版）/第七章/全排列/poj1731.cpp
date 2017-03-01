/*
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <ctime>
#include <assert.h>
using namespace std;
char str[220],a[220];
int v[220],n;
void dfs(int cur)
{
   if(cur==n){
      printf("%s\n",a);
      return;
   }
   int last=0;
   for(int i=0;i<n;i++){
      if(!v[i]&&last!=str[i]){
          a[cur]=str[i];
          last=str[i];
          v[i]=1;
          dfs(cur+1);
          v[i]=0;
      }
   }
}

int main()
{
   while(~scanf("%s",str)){
       n=strlen(str);
       memset(v,0,sizeof(v));
       sort(str,str+n);
       a[n]='\0';
       dfs(0);
   }
}
*/

#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    char str[220];
    while(~scanf("%s",str)){
        int len=strlen(str);
        sort(str,str+len);
        do{
            printf("%s\n",str);
        }while(next_permutation(str,str+len ));
    }
}
