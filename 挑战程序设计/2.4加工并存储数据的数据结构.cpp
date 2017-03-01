/*#include<bits/stdc++.h>
using namespace std;
const int inf=0x7fffffff;

using namespace std;
int tree[1010],size;
void swap(int a,int b)
{
    int t=tree[a];
    tree[a]=tree[b];
    tree[b]=t;
}

void push(int x)
{
    tree[size]=x;
    int t=size++;
    while(t>1){
        if(tree[t]>=tree[t/2]) break;
        swap(t,t/2);
        t/=2;
    }
}

void pop()
{
    tree[1]=tree[size-1];
    size--;
    int t=1;
    while(t*2<size){
       int l=t*2,r=t*2+1;
       if(r<size&&tree[l]>tree[r]) l=r;
       if(tree[t]<tree[l]) break;
       swap(t,l);
       t=l;
    }
}

int top()
{
     return tree[1];
}

int main()
{
   size=1;
    int n;
   while(cin>>n){
    for(int i=0;i<n;i++){
        int a;cin>>a;
        push(a);

    }
    cout<<"size="<<size-1<<endl;

    for(int i=0;i<n;i++){
        cout<<top()<<" ";
        pop();
    }
   }
}

struct node
{
    int val;
    node *r,*l;
};

node *insert(node *p,int x)
{
    if(p==NULL){
        node *q=new node;
        q->val=x;
        q->l=q->r=NULL;
        return q;
    }
    else if(x<p->val) p->l=insert(p->l,x);
    else  p->r=insert(p->r,x);
    return p;
}

bool find(node *p,int x)
{
    if(p==NULL) return false;
    else if(x<p->val) return find(p->l,x);
    else if(x>->val) return find(p->r,x);
    else return true;
}

node *remove(node *p,int x)
{
    if(p==NULL) return NULL;
    else if(x<p->val) return remove(p->l,x);
    else if(x>p->val) return remove(p->r,x);
    else if(p->l==NULL){
        node *q=p->r;
        delete p;
        return q;
    }
    else if(p->l->r==NULL){
        node *q=p->l;
        delete p;
        return q;
    }
    else{
        node q=p->l;
        while(q->r->r)  q=q->r;
        node *r=q->r;
        q->r=NULL;
        p->l=r;
        delete p;
        return r;
    }
}

#include<cstdio>
#include<set>
#include<map>
using namespace std;
int main()
{
    map<int,char*>m;
    m.insert(make_pair(1,"one"));
    m.insert(make_pair(2,"two"));
    m

}
*/
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int v[20],a[20];
bool ok()
{
    if(v[0]>0) return false;
    for(int i=1;i<=9;i++) if(v[i]>=2) return false;
    return true;
}
const int b[36][3]={1,2,3,3,2,1,1,4,7,7,4,1,7,8,9,9,8,7,3,6,9,9,6,3,2,5,8,8,5,2,4,5,6,6,5,4,3,5,7,7,5,3,1,5,9,9,5,1};
int main()
{
    int T;scanf("%d",&T);
    while(T--){
        int flag=0;
        memset(v,0,sizeof(v));
         int k;scanf("%d",&k); scanf("%d",&a[0]);
         if(k<=3) flag=1;
         if(a[0]<=9) v[a[0]]++; else flag=1;
          for(int i=0;i<k-1;i++){
              int j=i+1; scanf("%d",&a[j]);
              if(a[j]<=9) v[a[j]]++; else flag=1;
              for(int k=0;k<16;k++){
                if(a[i]==b[k][0]&&a[j]==b[k][2]&&!v[b[k][1]]) {flag=1;}
              }
          }
          if(flag||!ok()) printf("invalid\n");
          else printf("valid\n");
        }
}
