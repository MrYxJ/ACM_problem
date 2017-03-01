#include<bits/stdc++.h>
using namespace std;
struct Martrix
{
    int a,b;
    Martrix(int a=0,int b=0): a(a),b(b) {}
}m[30];
stack<Martrix>sta;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char c[2];
        scanf("%s",c);
        scanf("%d %d",&m[c[0]-'A'].a,&m[c[0]-'A'].b);
    }
    char s[550];
    while(~scanf("%s",s)){
        int ok=1,ans=0;
        while(!sta.empty()) sta.pop();
        int len=strlen(s);
        for(int i=0;i<len;i++){
            if(s[i]>='A'&&s[i]<='Z') sta.push(m[s[i]-'A']);
            else if(s[i]==')'){
                Martrix B=sta.top();sta.pop();
                Martrix A=sta.top();sta.pop();
                if(A.b!=B.a) {ok=0;break;}
                ans+=A.a*A.b*B.b;
                sta.push(Martrix(A.a,B.b));
            }
        }
        if(!ok) printf("error\n");
        else printf("%d\n",ans);
    }
}
