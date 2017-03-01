#include<bits/stdc++.h>
using namespace std;
struct Node
{
    bool have_value;
    int value;
    Node *lchild,*rchild;
    Node():have_value(false),lchild(NULL),rchild(NULL){}
};
Node *root;
char s[200];
vector<int>ans;
bool failed;
Node *newnode() {return new Node();}
void addnode(int v,char *s)
{
    int len=strlen(s);
    Node *p=root;
    for(int i=0;i<len;i++){
        if(s[i]=='L'){
            if(p->lchild==NULL) p->lchild=newnode();
            p=p->lchild;
        }
        else if(s[i]=='R'){
            if(p->rchild==NULL) p->rchild=newnode();
            p=p->rchild;
        }
    }
    if(p->have_value==true) failed=true;
    p->value=v;
    p->have_value=true;
}

bool read()
{
   failed=false;
   root=newnode();
   for(;;){
      if(scanf("%s",s)!=1) return false;
      if(!strcmp(s,"()")) break;
      int v;
      sscanf(&s[1],"%d",&v);
      addnode(v,strchr(s,',')+1);//strchr()函数返回一个字字符串第一次出现' '的地址。
   }
   return true;
}

bool bfs()
{
    ans.clear();
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node *now=q.front();q.pop();
        if(now->have_value==false) return false;
        ans.push_back(now->value);
        if(now->lchild!=NULL) q.push(now->lchild);
        if(now->rchild!=NULL) q.push(now->rchild);
    }
    return true;
}

void del(Node *root)
{
   if(root==NULL) return;
   del(root->lchild);
   del(root->rchild);
   delete root;
}

int main()
{
    ans.clear();
    while(read()){
       if(bfs()&&!failed){
           for(int i=0;i<ans.size()-1;i++) printf("%d ",ans[i]);
           printf("%d\n",ans[ans.size()-1]);
       }
       else printf("not complete\n");
       del(root);
    }
}
