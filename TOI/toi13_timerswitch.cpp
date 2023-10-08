#include<stdio.h>
#include<vector>
using namespace std;
long long hash_tester=0,hash_current=0;
long long p=98765431;
vector<long long> v;
int main(){
    int n;
    char s[5000001];
    scanf("%d",&n);
    scanf("%s",s);
    v.resize(n);
    for(int i=n-1;i>=0;--i){
        if(i==n-1)v[i]=1;
        else v[i]=v[i+1]*p;
        hash_tester += (s[i]=='1')?v[i]:0;
    }
    hash_current = hash_tester;
    for(int i=0;i<n;++i){
        if(s[i]=='0'){
            hash_current*=p;
        }
        else{
            hash_current-=v[0];
            hash_current*=p;
            hash_current++;
        }
        if(hash_current==hash_tester){
            printf("%d",i+1);
            return 0;
        }
    }
}