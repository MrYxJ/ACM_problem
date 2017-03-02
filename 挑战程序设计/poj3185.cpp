#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dir[25],f[25];

int main(){
    while(~scanf("%d",&dir[0])){
       int tmp=0,ans=20;
       memset(f,0,sizeof(f));
       for(int i=1;i<20;i++) scanf("%d",&dir[i]);
       f[0]=1;tmp++;
       for(int i=1;i<20;i++){
          if(f[i]=(f[i-2]^f[i-1]^dir[i-1])) tmp++;
       }
       if((f[18]^f[19]^dir[19])==0&&tmp<ans) ans=tmp;
       tmp=0;f[0]=0;
       for(int i=1;i<20;i++){
          if(f[i]=(f[i-2]^f[i-1]^dir[i-1])) tmp++;
       }
       if(f[18]^f[19]^dir[19]==0&&tmp<ans) ans=tmp;
       printf("%d\n",ans);
    }
}
