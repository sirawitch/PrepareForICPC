#include<stdio.h>
#include<queue>
#define mp make_pair
char s[2001][2001];
int m,n;
using namespace std;
void bfs(int x,int y){
    queue<pair<int,int> >q;
    q.push(mp(x,y));
    s[x][y]='0';
    while(!q.empty()){
        x=q.front().first;
        y=q.front().second;
        q.pop();
        if(x > 0 )
        {
            if(s[x - 1][y]=='1')
            {
                q.push(mp(x-1,y));
                s[x-1][y]='0';
            }
            
            if (y > 0 && s[x - 1][y - 1] == '1')
            {
                q.push(mp(x-1, y - 1));
                s[x-1][y - 1] = '0';
            }
            if (y < n - 1 && s[x-1][y + 1] == '1')
            {
                q.push(mp(x-1, y + 1));
                s[x-1][y + 1] = '0';
            }
        }
        if (y > 0 && s[x][y-1] == '1')
        {
            q.push(mp(x, y-1));
            s[x][y-1] = '0';
        }
        if (x < m-1)
        {
            if (s[x + 1][y] == '1')
            {
                q.push(mp(x+1, y));
                s[x+1][y] = '0';
            }
            
            if (y > 0 && s[x + 1][y - 1] == '1')
            {
                q.push(mp(x + 1, y - 1));
                s[x + 1][y - 1] = '0';
            }
            if (y < n - 1 && s[x + 1][y + 1] == '1')
            {
                q.push(mp(x + 1, y + 1));
                s[x + 1][y + 1] = '0';
            }
        }
        if (y < n-1 && s[x][y + 1] == '1')
        {
            q.push(mp(x, y + 1));
            s[x][y + 1] = '0';
        }
    }
}
int main(){
    int ans=0;
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;++i){
        scanf("%s",s[i]);
    }
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(s[i][j]=='1'){
                ++ans;
                bfs(i,j);
            }
        }
    }
    printf("%d",ans);
}