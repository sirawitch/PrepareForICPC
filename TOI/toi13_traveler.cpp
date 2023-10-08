#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int n,m;
int x,y,z,u,v,d;
vector<vector<pair<int,int> > >G;
priority_queue<pair<long long,int> >pq;
vector<bool> visited;
vector<long long> dis;
int main(){
    scanf("%d%d",&n,&m);
    G.resize(n);
    dis.resize(n);
    visited.resize(n);
    scanf("%d%d%d",&x,&y,&z);
    for(int i=0;i<m;++i){
        scanf("%d%d%d",&u,&v,&d);
        G[u].push_back(make_pair(v,d));
        G[v].push_back(make_pair(u, d));
    }
    for(int i=0;i<n;++i)dis[i]=1e18;
    pq.push(make_pair(0,x));
    dis[x]=0;
    while(!pq.empty()){
        u = pq.top().second;
        pq.pop();
        if(visited[u])continue;
        visited[u]=true;
        for(auto it:G[u]){
            if(!visited[it.first]&&dis[it.first]>dis[u]+(long long)(it.second)){
                dis[it.first]= dis[u] + (long long)(it.second);
                pq.push(make_pair(-dis[it.first],it.first));
            }
        }
    }
    if(dis[y]<=z){
        printf("%d %lld 0",y,dis[y]);
        return 0;
    }
    vector<long long> dis2;
    dis2.resize(n);
    for (int i = 0; i < n; ++i){
        dis2[i] = 1e18;
        visited[i]=false;
    }
    pq.push(make_pair(0, y));
    dis2[y] = 0;
    while (!pq.empty())
    {
        u = pq.top().second;
        pq.pop();
        if (visited[u])
            continue;
        visited[u] = true;
        for (auto it : G[u])
        {
            if (!visited[it.first] && dis2[it.first] > dis2[u] + (long long)(it.second))
            {
                dis2[it.first] = dis2[u] + (long long)(it.second);
                pq.push(make_pair(-dis2[it.first], it.first));
            }
        }
    }
    int ans_city=-1;
    long long ans_dis=1e18;
    for(int i=0;i<n;++i){
        if(dis[i]<=z){
            if(dis2[i]<ans_dis){
                ans_dis=dis2[i];
                ans_city=i;
            }
        }
    }
    printf("%d %lld %lld",ans_city,dis[ans_city],dis2[ans_city]);
}