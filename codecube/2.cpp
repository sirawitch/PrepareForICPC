#include <stdio.h>
#include<algorithm>
using namespace std;
long long gcd(long long a, long long b){
    if(a==0)return b;
    else if(b==0)return a;
    else if(a<b)return gcd(a,b%a);
    return gcd(a%b,b);
}
int main(){
    long long a,b;
    scanf("%lld%lld",&a,&b);
    printf("%lld",gcd(a,b));
}