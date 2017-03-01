/*
#include<bits/stdc++.h>
using namespace std;
int M[30][30],ans[10],v[10],maxx,n,ah[30],a[10],node[10];
char str[230];
void dfs(int cur,int w)
{
   if(cur==n){
       int num=0;
       for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(M[a[i]][a[j]]&&abs(i-j)>num){
                num=abs(i-j);
            }
            if(num>=maxx) return;
        }
       }
       maxx=num;
       for(int i=0;i<n;i++) ans[i]=a[i];
       return;
   }
   for(int i=0;i<n;i++){
      if(!v[i]){
         a[cur]=node[i];
         v[i]=1;
         int tem=0;
         for(int j=0;j<cur;j++){
             if(M[a[j]][node[i]]&&abs(cur-j)>tem) { tem=cur-j;break;}
         }
         int wx=max(tem,w);
         if(wx<maxx)


         dfs(cur+1,w);
         v[i]=0;
      }
   }
}

int main()
{
   while(gets(str)){
     if(str[0]=='#') break;
     int len=strlen(str);
     bool flag=true;
     int t=0;
     n=0;
     memset(ah,0,sizeof(ah));
     memset(M,0,sizeof(M));
     memset(v,0,sizeof(v));
     for(int i=0;i<len;i++){
        if(str[i]>='A'&&str[i]<='Z'){
            ah[str[i]-'A']=1;
            if(flag) t=str[i]-'A';
            else M[t][str[i]-'A']=1,M[str[i]-'A'][t]=1;
        }
        else if(str[i]==':') flag=false;
        else if(str[i]==';') flag=true;
     }
     for(int i=0;i<30;i++) if(ah[i]) node[n++]=i;
     maxx=0;
     for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
          if(M[node[i]][node[j]]) maxx=max(abs(i-j),maxx);
       }
     }
     maxx+=1;
     dfs(0,0);
     for(int i=0;i<n;i++){
        printf("%c ",ans[i]+'A');
     }
     printf("-> %d\n",maxx);
   }
}
*/
#include<bits/stdc++.h>
using namespace std;
int M[30][30],ans[10],maxx,n,ah[30],a[10];
char str[110];
int main()
{
    while(gets(str)){
    if(str[0]=='#') break;
    int len=strlen(str);
    bool flag=true;
    int t=0;
    n=0;
    memset(ah,0,sizeof(ah));
    memset(M,0,sizeof(M));
    for(int i=0;i<len;i++){
       if(str[i]>='A'&&str[i]<='Z'){
            ah[str[i]-'A']=1;
            if(flag) t=str[i]-'A';
            else M[t][str[i]-'A']=1,M[str[i]-'A'][t]=1;
        }
        else if(str[i]==':') flag=false;
        else if(str[i]==';') flag=true;
    }
    for(int i=0;i<30;i++) if(ah[i]) a[n++]=i;
    maxx=110;
    do{
        int t=0;
        for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
              if(M[a[i]][a[j]]) t=max(abs(i-j),t);
           }
        }
        if(t<maxx){
            maxx=t;
            for(int i=0;i<n;i++) ans[i]=a[i];
        }
    }while(next_permutation(a,a+n));
    for(int i=0;i<n;i++){
        printf("%c ",ans[i]+'A');
    }
    printf(" -> %d\n",maxx);
    }
}

