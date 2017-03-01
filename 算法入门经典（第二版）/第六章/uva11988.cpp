/*
#include<bits/stdc++.h>
using namespace std;
struct node
{
    char c;
    struct node*next;
};
node *head,*tail,*now;
const int maxn=1000000+10;
char str[maxn];

int main()
{
    while(~scanf("%s",str)){
        head=new node;
        head->next=NULL;
        tail=head;
        now=tail;
        int len=strlen(str);
        int flag=0;
        for(int i=0;i<len;i++){
            if(str[i]=='[')  now=head;
            else if(str[i]==']') now=tail;
            else{
               node *a=new node;
               a->c=str[i];a->next=now->next;
               now->next=a;
               now=now->next;
            }
            while(tail->next!=NULL) tail=tail->next;
        }
        node *p=head->next;
        while(p){
           printf("%c",p->c);
           p=p->next;
        }
        printf("\n");
    }
}
*/

#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10;
int nxt[maxn];
char str[maxn];
int main()
{
    while(~scanf("%s",str+1)){
        int cur=0,last=0,len=strlen(str+1);
        memset(nxt,0,sizeof(nxt));
        for(int i=1;i<=len;i++){
            if(str[i]=='[') cur=0;
            else if(str[i]==']') cur=last;
            else{
                nxt[i]=nxt[cur];
                nxt[cur]=i;
                if(cur==last) last=i;
                cur=i;
            }
        }
        for(int i=nxt[0];i!=0;i=nxt[i]) printf("%c",str[i]);
        printf("\n");
    }
}

