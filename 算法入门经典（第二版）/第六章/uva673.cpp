#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  stack<char>sta;
  int T;scanf("%d",&T);
  getchar();
  while(T--){
     getline(cin,s);
     while(!sta.empty()) sta.pop();
     bool ok=true;
     for(int i=0;i<s.size();i++){
        if(s[i]=='('||s[i]=='[') sta.push(s[i]);
        else if(s[i]==')'){
            if(!sta.empty()&&sta.top()=='(') sta.pop();
            else ok=false;
        }
        else if(s[i]==']'){
            if(!sta.empty()&&sta.top()=='[') sta.pop();
            else ok=false;
        }
     }
     if(!sta.empty()) ok=false;
     printf("%s\n",ok==true ? "Yes" : "No" );
  }
}
