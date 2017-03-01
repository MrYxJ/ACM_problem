#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        int D,I; scanf("%d %d",&D,&I);
        int ans=1;
        for(int i=1;i<D;i++){
           if(I%2) ans*=2;
           else ans=ans*2+1;
           I=(I+1)/2;
        }
        printf("%d\n",ans);
    }
}
