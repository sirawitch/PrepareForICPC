#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
long long gcd(long long a, long long b)
{
    if (a == 0)
        return b;
    else if (b == 0)
        return a;
    else if (a < b)
        return gcd(a, b % a);
    return gcd(a % b, b);
}
int main()
{
    long long a;
    long long GCD=0;
    long long ans=0;
    //vector<long long>v;
    long long v[1000000];
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    for(int i=0;i<n;++i){
        GCD=gcd(GCD,v[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        ans+=v[i]/GCD;
    }
    cout<<ans;
    return 0;
}