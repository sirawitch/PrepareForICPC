#include<stdio.h>
long long dp[51][51];
int main(){
    int m,n,x,y;
    scanf("%d%d",&m,&n);
    int o;
    scanf("%d",&o);
    for(int i=0;i<o;++i){
        scanf("%d%d",&x,&y);
        dp[x][y]=-1;
    }
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            if(dp[i][j]==-1)dp[i][j]=0;
            else if(i==1&&j==1)dp[1][1]=1;
            else if(i==1)dp[1][j]=dp[1][j-1];
            else if(j==1)dp[i][1]=dp[i-1][1];
            else dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    printf("%lld",dp[m][n]);
}