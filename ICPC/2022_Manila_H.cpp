#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <functional>
using namespace std;
int n;
long long x;
vector<long long> a,b;
vector<pair<long long,int> >aa,bb;
vector<int> ans;
priority_queue<pair<long long, pair<int, int> >, vector<pair<long long, pair<int, int> > >, greater<pair<long long, pair<int, int> > > > pq;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0);
    cin>>n>>x;
    a.resize(n),b.resize(n);
    aa.resize(n),bb.resize(n);
    ans.resize(n);
    for(int i=0;i<n;++i){
        cin>>aa[i].first;
        aa[i].second=i;
        a[i]=aa[i].first;
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> bb[i].first;
        bb[i].second=i;
        b[i]=bb[i].first;
    }
    sort(aa.begin(),aa.end());
    sort(bb.begin(),bb.end());
    int cntA=0,i;
    long long sum=0;
    for(i=0;i<aa.size();++i){
        if(sum+aa[i].first>x)break;
        sum+=aa[i].first;
        pq.push(make_pair(b[aa[i].second]-a[aa[i].second],make_pair(aa[i].second,aa[i].second)));
        ans[aa[i].second]=1;
    }
    long long valLeft = x-sum;
    int k=0,l=i-1;
    while (l >= 0 && k < n)
    {
        if (ans[aa[l].second] == 1 && ans[bb[k].second] == 0)
        {
            break;
        }
        if (ans[aa[l].second] != 1)
            --l;
        if (ans[bb[k].second] != 0)
            ++k;
    }
    if (l >= 0 && k < n)
    {
        pq.push(make_pair(bb[k].first - aa[l].first, make_pair(aa[l].second, bb[k].second)));
    }
    long long val;
    int oldPos,newPos;
    bool isOk;
    while(!pq.empty()){
        val = pq.top().first;
        oldPos=pq.top().second.first;
        newPos=pq.top().second.second;
        pq.pop();
        if(valLeft<val)break;
        if(oldPos!=newPos){
            if(ans[oldPos]==1&&ans[newPos]==0){
                valLeft -= val;
                ans[newPos] = 2;
                ans[oldPos] = 0;
            }
            while(l>=0&&k<n){
                if (ans[aa[l].second] == 1 && ans[bb[k].second] == 0 && aa[l].second != bb[k].second)
                {
                    break;
                }
                if (ans[aa[l].second] != 1)
                    --l;
                if (ans[bb[k].second] != 0)
                    ++k;
            }
            if(l>=0&&k<n){
                pq.push(make_pair(bb[k].first - aa[l].first, make_pair(aa[l].second, bb[k].second)));
            }
        }
        else{
            if(ans[oldPos]==1){
                valLeft-=val;
                ans[newPos]=2;
            }
        }
    }
    for(int i=0;i<n;++i){
        cout<<ans[i];
    }
}