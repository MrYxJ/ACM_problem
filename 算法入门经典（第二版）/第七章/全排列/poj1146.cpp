#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
int ok,t,v[80];
char str[80],ans[80];
int main()
{
    while(scanf("%s",str)&&str[0]!='#'){
        int len=strlen(str),ok=0;
        for(int i=len-1;i>0;i--){
            if(str[i]>str[i-1]){
                ok=i;
                break;
            }
        }
        if(!ok) printf("No Successor\n");
        else{
            int index=ok;
            for(int i=index;i<len;i++){
               if(str[i]>str[ok-1]&&str[i]<str[index]) index=i;
            }
            swap(str[ok-1],str[index]);
            sort(str+ok,str+len);
            for(int i=0;i<len;i++) printf("%c",str[i]);
            printf("\n");
        }
    }
}
