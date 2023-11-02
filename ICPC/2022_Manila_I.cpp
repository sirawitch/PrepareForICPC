#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iterator>
int n,m,a;
using namespace std;
vector<int>c,raw;
vector<vector<int> >p;
vector<vector<int> >matUse;
vector<bool> use;
vector<bool> legen;
int best=0;
int maxNum=1e8+1;
int isOk(){
    int cnt=0;
    vector<int>sum(raw.size());
    for(int i=1;i<=n;++i){
        if (use[i] == 1 && legen[i])
        {   ++cnt;
            for (int j=0;j<raw.size();++j)
            {
                    sum[j] += matUse[i][j];
                    if (sum[j] > p[raw[j]][0])
                        return 0;
            }
        }
    }
    return cnt;
}
void permu(int i){
    int sum=isOk();
    if(sum>best)best=sum;
    if (i > n)
        return;
    use[i]=0;
    permu(i+1);
    use[i]=1;
    permu(i+1);
    use[i]=0;
}
int main(){
    scanf("%d%d",&n,&m);
    c.resize(m+1);
    p.resize(m+1);
    matUse.resize(m+1);
    use.resize(n+1);
    legen.resize(n+1);
    for(int i=1;i<=m;++i){
        scanf("%d",&c[i]);
        if(c[i]==0){
            scanf("%d",&a);
            p[i].push_back(a);
            raw.push_back(i);
        }
        else{
            if(i<=n)legen[i]=true;
            for(int j=0;j<c[i];++j){
                scanf("%d",&a);
                p[i].push_back(a);
            }
        }
    }
    for(int i=m;i>=1;--i){
        matUse[i].resize(raw.size());
        if(c[i]==0)continue;
        for(auto item:p[i]){
            if(c[item]==0){
                int idx = lower_bound(raw.begin(),raw.end(),item)-raw.begin();
                ++matUse[i][idx];
            }
            else{
                for(int j=0;j<raw.size();++j){
                    matUse[i][j]+=matUse[item][j];
                    if (matUse[i][j] >=maxNum)matUse[i][j]=maxNum;
                }
            }
        }
    }
    permu(1);
    printf("%d",best);
}