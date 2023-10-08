#include<stdio.h>
#include<vector>
using namespace std;
int n;
vector<long long> s;
long long l=0,r=1e17;
bool canUseThisSize(long long m){
    long long lastSize=-1,cnt=0;
    for(int i=0;i<n;++i){
        if(s[i]>m){
            if(cnt==0){lastSize=s[i];cnt=1;}
            else if(lastSize!=s[i])return false;
            else cnt=0;
        }
    }
    return true;
}
int main(){
    long long m;
    scanf("%d",&n);
    s.resize(n);
    for(int i=0;i<n;++i){
        scanf("%lld",&s[i]);
    }
    while(l<r){
        m=(l+r)/2;
        if(canUseThisSize(m))r=m;
        else l=m+1;
    }
    printf("%lld",l);
}
