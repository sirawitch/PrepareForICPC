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
void create_path_1(pair<int,int> u, pair<int,int>v){
    if(u.first==v.first&&u.second==v.second)return;
    if(u.first<v.first && path[u.first+1][u.second]==rnd){
        path[u.first + 1][u.second]=rnd+1;
        create_path_1(make_pair(u.first + 1, u.second), v);
    }
    else if (u.first > v.first && path[u.first - 1][u.second] == rnd)
    {
        path[u.first - 1][u.second]=rnd+1;
        create_path_1(make_pair(u.first - 1, u.second), v);
    }
    if (u.second < v.second && path[u.first][u.second+1] == rnd)
    {
        path[u.first][u.second+1]=rnd+1;
        create_path_1(make_pair(u.first, u.second+1), v);
    }
    else if (u.second > v.second && path[u.first][u.second-1] == rnd)
    {
        path[u.first][u.second-1]=rnd+1;
        create_path_1(make_pair(u.first, u.second-1), v);
    }
}
void createSol(pair<int,int>u,pair<int,int>v){
    if(u.first==v.first&&u.second==v.second)return;
    if(u.first>v.first){
        s[u.first-1][u.second]='#';
        createSol(make_pair(u.first-1,u.second),v);
    }
    else if (u.first < v.first)
    {
        s[u.first + 1][u.second] = '#';
        createSol(make_pair(u.first + 1, u.second), v);
    }
    else if (u.second > v.second)
    {
        s[u.first][u.second-1] = '#';
        createSol(make_pair(u.first, u.second-1), v);
    }
    else if (u.second < v.second)
    {
        s[u.first][u.second+1] = '#';
        createSol(make_pair(u.first, u.second+1), v);
    }
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
    int sumDis[3];
    sumDis[0]=distance(p[0],p[1])+distance(p[0],p[2]);
    sumDis[1] = distance(p[1], p[0]) + distance(p[1], p[2]);
    sumDis[2] = distance(p[2], p[0]) + distance(p[2], p[1]);
    pair<int,int> temp;
    //Want p[0] is middle point for go to p[1] and p[2]
    if(sumDis[0]<=sumDis[1]&&sumDis[0]<=sumDis[2]);//don't change because p[0] is min
    else if(sumDis[1]<=sumDis[0]&&sumDis[1]<=sumDis[2]){//swap p[0],p[1]
        temp=p[0];
        p[0]=p[1];
        p[1]=temp;
    }
    else
    { // swap p[0],p[2]
        temp = p[0];
        p[0] = p[2];
        p[2] = temp;
    }
    rnd=0;
    create_path_1(p[0],p[1]);
    rnd=1;
    create_path_1(p[0], p[2]);
    pair<int,int> bestforp1=p[0],bestforp2=p[0];
    int bestdisp1=1e9,bestdisp2=1e9;
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            if(path[i][j]==2){
                s[i][j]='#';
                if(bestdisp1>distance(make_pair(i,j),p[1])){
                    bestdisp1 = distance(make_pair(i, j), p[1]);
                    bestforp1=make_pair(i,j);
                }
                if (bestdisp2 > distance(make_pair(i, j), p[2]))
                {
                    bestdisp2 = distance(make_pair(i, j), p[2]);
                    bestforp2 = make_pair(i, j);
                }
            }
        }
    }
    createSol(p[1],bestforp1);
    createSol(p[2],bestforp2);
    for (int i = 0; i < r; ++i)
    {
            printf("%s\n",s[i]);
    }
}
