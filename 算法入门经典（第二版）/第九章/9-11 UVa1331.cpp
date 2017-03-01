#include<cstdio>
#include<cstring>
#include<algorithm>
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
using namespace std;
int n;
const double inf=0x3f3f3f3f3f3f;
double dp[60][60];
struct point{
  double x,y;
}a[60];

double xmult(point p1,point p2,point p0){//向量叉积的求法
   return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

double area(point a,point b,point c){//三角形的面积
  double  s=xmult(b,c,a)*0.5;
  if(s<0) return -s;
  else return s;
}

int judge(int a1,int a2,int a3){//判断三点共线以及三角形内不能有点
  for(int i=1;i<=n;i++){
    if(i==a1||i==a2||i==a3) continue;
    double d=area(a[a1],a[a2],a[i])+area(a[a1],a[a3],a[i])+area(a[a2],a[a3],a[i])-area(a[a1],a[a2],a[a3]);
    if(zero(d)) return false;
  }
  return true;
}

int main(){
   int T;scanf("%d",&T);
   while(T--){
     scanf("%d",&n);
     for(int i=1;i<=n;i++) scanf("%lf %lf",&a[i].x,&a[i].y);
     for(int i=n;i>=1;i--){
        dp[i][i+1]=0.0;
        for(int j=i+2;j<=n;j++){
          dp[i][j]=inf;
          for(int k=i+1;k<j;k++){
            if(judge(i,k,j)) dp[i][j]=min(dp[i][j],max(max(dp[i][k],dp[k][j]),area(a[i],a[k],a[j])));
          }
        }
     }
     printf("%.1f\n",dp[1][n]);
   }
}
