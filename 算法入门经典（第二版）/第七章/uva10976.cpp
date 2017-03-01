/*
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >ans;

int main()
{
    int n;
    while(~scanf("%d",&n)){
        ans.clear();
        for(int i=n+1;i<=n*2;i++){
            int a=n*i,b=i-n;
            if(a%b==0){
                ans.push_back(make_pair(a/b,i));
            }
        }
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++){
            printf("1/%d = 1/%d + 1/%d\n",n,ans[i].first,ans[i].second);
        }
    }
}
*/
#include<bits/stdc++.h>
using namespace std;
int v[1010],a[1010],b[1010];
void print1(int n,int *A,int *B,int cur)
{
   if(cur==n){
      for(int i=0;i<n;i++) printf("%d ",B[i]);
      printf("\n");
      return;
   }
   int last=0;
   for(int i=0;i<n;i++){
      if(v[i]==0&&A[i]>last){
         B[cur]=A[i];
         last=A[i];
         v[i]=1;
         print1(n,A,B,cur+1);
         v[i]=0;
      }
   }
}


int main()
{
    int n;
    memset(v,0,sizeof(v));
    while(scanf("%d",&n)&&n){
        memset(v,0,sizeof(v));
        memset(b,0,sizeof(b));
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        sort(a,a+n);
        print1(n,a,b,0);
    }
}
