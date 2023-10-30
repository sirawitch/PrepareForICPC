#include<stdio.h>
#include<map>
#include<vector>
using namespace std;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    vector<int> a(n),copy(n);
    map<int,int> m;
    bool isChange=true;
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
        ++m[a[i]];
    }
    for(int j=1;j<=k&&isChange;++j){
        isChange=false;
        for(int i=0;i<n;++i){
            if(m[a[i]] != a[i]){
                isChange=true;
                break;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            copy[i] = m[a[i]];
        }
        for (int i = 0; i < n; ++i)
        {
            m.erase(a[i]);
        }
        for (int i = 0; i < n; ++i)
        {
            a[i]=copy[i];
            m[a[i]]++;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", a[i]);
    }
}