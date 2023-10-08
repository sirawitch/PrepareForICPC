#include<stdio.h>
char s[260];
bool visited[256][256][3];
bool dp[256][256][3];
int n;
void resetval(){
    for(int i=0;i<256;++i){
        for(int j=0;j<256;++j){
            visited[i][j][0]=false;
            dp[i][j][0]=false;
            visited[i][j][1]= false;
            dp[i][j][1] = false;
            visited[i][j][2] = false;
            dp[i][j][2] = false;
        }
    }
}
bool solve(int l,int r,char val){
    if(l==r){
        if(s[l]==val)return true;
        return false;
    }
    if(visited[l][r][val-'0']){
        return dp[l][r][val-'0'];
    }
    visited[l][r][val-'0']=true;
    char first,second;
    for(int i=l;i<r;++i){
        if(val=='0'){
            if(solve(l,i,'0')&&solve(i+1,r,'2')){
                dp[l][r][val-'0']=true;
                return true;
            }
        }
        else if(val=='1'){
            if (solve(l, i, '1') && solve(i + 1, r, '1'))
            {
                dp[l][r][val - '0'] = true;
                return true;
            }
            if (solve(l, i, '0') && solve(i + 1, r, '1'))
            {
                dp[l][r][val - '0'] = true;
                return true;
            }
            if (solve(l, i, '1') && solve(i + 1, r, '2'))
            {
                dp[l][r][val - '0'] = true;
                return true;
            }
            if (solve(l, i, '2') && solve(i + 1, r, '0'))
            {
                dp[l][r][val - '0'] = true;
                return true;
            }
            if (solve(l, i, '2') && solve(i + 1, r, '2'))
            {
                dp[l][r][val - '0'] = true;
                return true;
            }
        }
        else{
            if (solve(l, i, '0') && solve(i + 1, r, '0'))
            {
                dp[l][r][val - '0'] = true;
                return true;
            }
            if (solve(l, i, '1') && solve(i + 1, r, '0'))
            {
                dp[l][r][val - '0'] = true;
                return true;
            }
            if (solve(l, i, '2') && solve(i + 1, r, '1'))
            {
                dp[l][r][val - '0'] = true;
                return true;
            }
        }
    }
    return false;
}
int main(){
    for(int i=0;i<20;++i){
        scanf("%d",&n);
        scanf("%s",s);
        resetval();
        if(solve(0,n-1,'0'))printf("yes\n");
        else printf("no\n");
    }
}