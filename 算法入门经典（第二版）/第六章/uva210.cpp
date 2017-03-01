#include<bits/stdc++.h>
using namespace std;
int t[7],var[26],p[1010];
deque<int>wait;
queue<int>block;
vector<string>op[1010];
bool Lock;
void run(int i)
{
   int rt=t[6];
   while(rt){
      string s=op[i][p[i]];
      if(s[2]=='='){
          rt-=t[1];
          var[s[0]-'a']=s[4]-'0';
          if(s.size()==6) var[s[0]-'a']=var[s[0]-'a']*10+s[5]-'0';
      }
      else if(s[0]=='p'){
           rt-=t[2];
           printf("%d: %d\n",i,var[s[6]-'a']);
      }
      else if(s[0]=='l'){
           rt-=t[3];
           if(Lock){
              block.push(i);
              return;
           }
           else Lock=true;
      }
      else if(s[0]=='u'){
           Lock=false;
           rt-=t[4];
           if(!block.empty()){
              int temp=block.front();
              block.pop();
              wait.push_front(temp);
           }
      }
      else return;
      p[i]++;
   }
   wait.push_back(i);
}

int main()
{
    int T;scanf("%d",&T);
    while(T--){
       int n;scanf("%d",&n);
       for(int i=1;i<=6;i++) scanf("%d",&t[i]);
       for(int i=1;i<=n;i++){
           op[i].clear();
           string s;
           while(getline(cin,s)){
              if(s=="") continue;
              op[i].push_back(s);
              if(s=="end") break;
           }
           wait.push_back(i);
       }
       memset(p,0,sizeof(p));
       memset(var,0,sizeof(var));
       Lock=false;
       while(!wait.empty()){
           int cur=wait.front();
           wait.pop_front();
           run(cur);
       }
       if(T) printf("\n");
    }
    return 0;
}
