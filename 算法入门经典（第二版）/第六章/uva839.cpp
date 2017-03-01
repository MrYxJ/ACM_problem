#include<bits/stdc++.h>
using namespace std;
bool solve(int& W)
{
    int W1,D1,W2,D2;
    bool b1=true,b2=true;
    scanf("%d %d %d %d",&W1,&D1,&W2,&D2);
    if(!W1) b1=solve(W1);
    if(!W2) b2=solve(W2);
    W=W1+W2;
    return b1&&b2&&(W1*D1==W2*D2);
}

int main()
{
   int T;scanf("%d",&T);
   while(T--){
      int W;
      if(solve(W)) printf("YES\n");
      else printf("NO\n");
      if(T) printf("\n");
   }
}
