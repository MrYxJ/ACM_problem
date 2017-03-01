/*
#include<bits/stdc++.h>
using namespace std;
string c[10]={"ZERO","ONE", "TWO", "THREE", "FOUR",
"FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

vector<int>d[10];
int v[30];


vector<int>ans;
void solve(){
   for(int i=0;i<10;i++){
     for(int j=0;j<c[i].size();j++){
        int x=c[i][j]-'A';
        d[i].push_back(x);
     }
   }
}

bool check(int x){
   int ok=-1;
   for(int i=0;i<d[x].size();i++){
      if(v[d[x][i]]>0) v[d[x][i]]--;
      else{
        ok=i;
        break;
      }
   }
   if(ok!=-1){
     for(int i=0;i<ok;i++){
         v[d[x][i]]++;
     }
     return false;
   }
   return true;
}

int main(){
   solve();
   int T;scanf("%d",&T);
   while(T--){
       ans.clear();
       memset(v,0,sizeof(v));
       string s;cin>>s;
       for(int i=0;i<s.size();i++) v[s[i]-'A']++;

       for(int i=0;i<10;i++){
          while(check(i)){
                int x=i;
                if(x>=8) x-=8;
                else x+=2;
                ans.push_back(x);
          }
       }
       sort(ans.begin(),ans.end());
       for(int i=0;i<ans.size();i++) printf("%d",ans[i]);
       printf("\n");
   }
}

#include<bits/stdc++.h>
using namespace std;
int main(){
   int n;
   while(cin>>n){
     if(n==1){
         int x;cin>>x;
         if(x==15) cout<<"DOWN"<<endl;
         else if(x==0) cout<<"UP"<<endl;
         else cout<<"-1"<<endl;
     }
     else{
        int a,b;cin>>b;
        for(int i=1;i<n;i++){
             a=b;
             cin>>b;
        }
        if((a>b&&b!=0)||b==15) cout<<"DOWN"<<endl;
        else cout<<"UP"<<endl;
     }
   }
}


#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
   int n;
   while(cin>>n){
      cin>>s;
      int ans=0,t,t1=0,t2=0;
      for(int i=0;i<n;i++) if(s[i]=='r') t1++;
      for(int i=0;i<n;i++){
         if(i%2==1){
            if(s[i]!='b') t2++;
         }
         else if(s[i]!='r') t2++;
      }
      t=(t2+abs((n+1)/2-t1))/2;
      ans=t;
      //cout<<t1<<" "<<t2<<endl;
      t1=0;t2=0;
      for(int i=0;i<n;i++) if(s[i]=='b') t1++;
      for(int i=0;i<n;i++){
         if(i%2==1){
            if(s[i]!='r') t2++;
         }
         else if(s[i]!='b') t2++;
      }
      t=(t2+abs((n+1)/2-t1))/2;
      //cout<<t1<<" "<<t2<<endl;
      ans=min(ans,t);
      printf("%d\n",ans);
   }
}
*/
#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    int n,t;
    while(cin>>n>>t){
        cin>>s;
        int ok=0;
        for(int i=s.size()-1;i>=0&&s.size()-i<=t;i--){
            if(s[i]=='.') break;
            if(s[i]>='5'){
                ok=1;break;
            }
        }
        if(ok==0) cout<<s<<endl;
        else{
           string ans="";ok=0;
           int j=0,dian=0;
           for(int i=s.size()-1;i>=0;i--){
               if(s[i]=='.'||s.size()-i>t){
                   if(s[i]=='.') dian=1;
                   ok=i;break;
               }
               if(s[i]>='5'||j&&s[i]=='4'){
                   j=1;
               }
               else{
                  if(j==1){
                     //cout<<"ok"<<endl;
                     j=0;
                     ans="";
                     int x=s[i]-'0';
                     if(x==9) j=1;
                     else x++,ans+=(x+'0');
                  }
                  else ans+=s[i];
               }
           }
           cout<<"j="<<j<<endl;
           cout<<ans<<" ok"<<ok<<endl;
           for(int i=ok;i>=0;i--){
                if(j){
                   if(s[i]=='.') ans="",dian=1;
                   else if(!dian){
                     j=0;
                     ans="";
                     int x=s[i]-'0';
                     if(x==9) j=1;
                     else x++,ans+=(x+'0');
                   }
                   else{
                     int x=s[i]-'0';
                     if(x==9) j=1,x=0;
                     else x++;
                     ans+=(x+'0');
                   }
                }
                else ans+=s[i];
           }
           if(j==1) printf("1");
           for(int i=0;i<ans.size();i++) cout<<ans[ans.size()-1-i];
           cout<<endl;
        }
    }
}
