#include<stdio.h>
#include<vector>
#include <cstdlib>
using namespace std;
int r, c;
char s[101][101];
int path[101][101];
int rnd=0;
int distance(pair<int,int> a,pair<int,int>b){
    return abs(a.first-b.first)+abs(a.second-b.second);
}
int main(){
    pair<int,int> p[3];
    scanf("%d%d",&r,&c);
    for(int i=0;i<r;++i){
        scanf("%s",s[i]);
    }
    int k=0;
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            if(s[i][j]=='#')p[k++]=make_pair(i,j);
        }
    }
    pair<int,int> middle=p[2];
    if ((p[0].second <= p[1].second && p[1].second <= p[2].second) || (p[2].second <= p[1].second && p[1].second <= p[0].second))
    {
        middle = p[1];
    }
    else if ((p[1].second <= p[0].second && p[0].second <= p[2].second) || (p[2].second <= p[0].second && p[0].second <= p[1].second))
    {
        middle = p[0];
    }
    //make line x
    for(int i=p[0].first;i<=p[2].first;++i){
        s[i][middle.second]='#';
    }
    //make line y
    for(int i=0;i<3;++i){
        for(int j=p[i].second;j<=middle.second;++j){
            s[p[i].first][j]='#';
        }
        for (int j = p[i].second; j >= middle.second; --j)
        {
            s[p[i].first][j] = '#';
        }
    }
    for (int i = 0; i < r; ++i)
    {
        printf("%s\n",s[i]);
    }
}
