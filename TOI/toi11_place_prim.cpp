#include <queue>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define mp make_pair
using namespace std;
vector< vector<pair<int,int> > > E;
vector<bool> visited;
vector<int> val; // collect max value connect with that node
main(){
    int n, m, s, d, l;
    long long sum = 0;
    scanf("%d%d", &n, &m);
    E.resize(n+1);
    visited.resize(n+1);
    val.resize(n+1);
    priority_queue<pair<int,int> >pq;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d%d", &s, &d, &l);
        E[s].push_back({d,l-1});
        E[d].push_back({s,l-1});
    }
    pq.push({0,1});
    while(!pq.empty()){
        int dis=pq.top().first;
        int y=pq.top().second;
        pq.pop();
        if(visited[y])continue;
        visited[y]=true;
        sum+=dis;
        for(auto it:E[y]){
            if(!visited[it.first]&&val[it.first]<it.second){
                val[it.first]=it.second;
                pq.push({it.second,it.first});
            }
        }
    }
    printf("%lld",sum);
}