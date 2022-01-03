
  #include<algorithm>
  #include<iostream>
  #include<cstring>
  #include<cstdio>
  #include<cmath>
  #include<vector>
  using namespace std;
  const int mod=1e9+7;
 const int mxn=500010;
 int read(){
     int x=0,f=1;char ch=getchar();
     while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
     while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
     return x*f;
 }
 int n,m,K,T;
 int f[751][751];
 int s[mxn];
 int a[751][751];
 int vis[mxn];
 void solve(int l,int r){
     if(l==r)return;
     int mid=(l+r)>>1;
     solve(l,mid);
     int sum=0;
     T++;
     for(int i=2;i<=n;i++){
         for(int j=l;j<=mid;j++){
             if(vis[a[i-1][j]]!=T){
                 vis[a[i-1][j]]=T;
                 s[a[i-1][j]]=0;
             }
             sum=(sum+f[i-1][j])%mod;
             (s[a[i-1][j]]+=f[i-1][j])%=mod;
         }
         for(int j=mid+1;j<=r;j++){
             if(vis[a[i][j]]!=T){
                 vis[a[i][j]]=T;
                 s[a[i][j]]=0;
             }
             f[i][j]=((f[i][j]+sum-s[a[i][j]])%mod+mod)%mod;
         }
     }
     solve(mid+1,r);
     return;
 }
 int main(){
    int i,j;
     n=read();m=read();K=read();
     for(i=1;i<=n;i++)
         for(j=1;j<=m;j++)
             a[i][j]=read();
     f[1][1]=1;
     solve(1,m);
     printf("%d\n",f[n][m]);
     return 0;
	  }
