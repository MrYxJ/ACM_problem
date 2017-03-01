#include<bits/stdc++.h>
using namespace std;
const int maxn=250;
int n;
char str[maxn][maxn];
void dfs(int r,int c)
{
    printf("%c(",str[r][c]);
    if(r+1<n&&str[r+1][c]=='|'){
        int i=c;
        while(str[r+2][i-1]=='-'&&i-1>=0) i--;
        while(str[r+2][i]=='-'&&str[r+3][i+1]!='\0'){
            if(str[r+3][i]!=' ') dfs(r+3,i);
            i++;
        }
    }
    printf(")");
}

void solve()
{
    n=0;
    for(;;){
       fgets(str[n],maxn,stdin);
       if(str[n][0]=='#') break;
       else n++;
    }
    printf("(");
    if(n){
        for(int i=0;i<strlen(str[0]);i++){
            if(str[0][i]!=' ') {dfs(0,i);break;}
        }
    }
    printf(")\n");
}

int main()
{
    int T;
    fgets(str[0],maxn,stdin);
    sscanf(str[0], "%d",&T);
    while(T--) solve();
}
