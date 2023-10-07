#include<queue>
#include<stdio.h>
#include<vector>
#include<algorithm>
#define mp make_pair
using namespace std;
vector<int>p;
int unionset(int a){
    if(p[a]==a)return a;
    return p[a]=unionset(p[a]);
}
int main(){
    int n,m,s,d,l;
    long long sum=0;
    vector<pair<long long,pair<int,int> > >E;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        scanf("%d%d%d",&s,&d,&l);
        E.push_back(mp(l-1,mp(s,d)));
    }
    sort(E.begin(), E.end(), greater< pair<long long, pair<int, int> > >());
    p.resize(n+1);
    for(int i=0;i<=n;++i){
        p[i]=i;
    }
    for(auto it:E){
        int x=unionset(it.second.first);
        int y=unionset(it.second.second);
        if(x!=y ){
            sum+=it.first;
            p[x]=y;
        }
    }
    printf("%lld",sum);
}