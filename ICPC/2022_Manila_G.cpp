#include <stdio.h>
#include <vector>
#include <algorithm>
#include<map>
using namespace std;
int main(){
    int n,k,ans=0,l,r,sum=0,mx=0;
    map<int,int> m;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i){
        scanf("%d%d", &l, &r);
        if(r-l+1>=k)ans++;
        else if(l%k<(r+1)%k) m[l%k]++,m[(r+1)%k]--;
        else m[0]++,m[(r+1)%k]--,m[l%k]++;
    }
    for(map<int,int>::iterator it=m.begin();it!=m.end();++it){
        sum+=it->second;
        mx=max(mx,sum);
    }
    printf("%d",mx+ans);
}