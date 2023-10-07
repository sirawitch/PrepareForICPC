#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n;
    vector<long long>t,h,sum;
    long long val;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&val);
        t.push_back(val);
    }
    sort(t.begin(),t.end());
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &val);
        h.push_back(val);
    }
    sort(h.begin(), h.end(),greater<int>());
    for(int i=0;i<n;++i){
        sum.push_back(h[i]+t[i]);
    }
    sort(sum.begin(), sum.end());
    printf("%lld",sum.back()-sum[0]);
}