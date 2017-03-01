/*
#include<cstring>
#include<cstdio>
#include<string>
#include<set>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
set<string> dict;
string s;
int ok,v[110];
char ans[110];
void dfs(int cur)
{
    if(cur==s.size()){
        string t=ans;
        if(dict.count(t)){
            ok=1;
            printf("%s\n",ans);
            return;
        }
    }
    int last=0;
    for(int i=0;i<s.size();i++){
       if(!v[i]&&s[i]>last){
           ans[cur]=s[i];
           v[i]=1;
           last=s[i];
           dfs(cur+1);
           v[i]=0;
       }
    }
}

int main()
{
    dict.clear();
    while(cin>>s){
        if(s=="XXXXXX") break;
        dict.insert(s);
    }
    while(cin>>s){
        if(s=="XXXXXX") break;
        ok=0;
        memset(v,0,sizeof(v));
        ans[s.size()]='\0';
        sort(s.begin(),s.end());
        dfs(0);
        if(!ok) printf("NOT A VALID WORD\n");
        printf("******\n");
    }
}
*/
#include<cstdio>
#include<cstring>
#include<string>
#include<set>
#include<iostream>
#include<algorithm>
using namespace std;
set<string>dict;

int main()
{
   string s;
   while(cin>>s){
      if(s=="XXXXXX") break;
      dict.insert(s);
   }
   while(cin>>s){
      int ok=0;
      if(s=="XXXXXX") break;
      sort(s.begin(),s.end());
      do{
        if(dict.count(s)){
            ok=1;
            cout<<s<<endl;
        }
      }while(next_permutation(s.begin(),s.end()));
      if(!ok) printf("NOT A VALID WORD\n");
      printf("******\n");
   }
}
