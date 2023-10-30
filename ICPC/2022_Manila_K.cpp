#include<stdio.h>
#include <string.h>
#include<vector>
using namespace std;
char s1[11],s2[10],s3[8];
char qwer[] = "QWERTYUIOP";
char asdf[] = "ASDFGHJKL";
char zxcv[] = "ZXCVBNM";
char s[40];
vector<char> key;
vector<bool> useKey;
int main(){
    scanf("%s", s1);
    scanf("%s", s2);
    scanf("%s", s3);
    for(int i=0;i<10;++i){
        if(s1[i]=='*'){
            key.push_back(qwer[i]);
        }
    }
    for (int i = 0; i < 9; ++i)
    {
        if (s2[i] == '*')
        {
            key.push_back(asdf[i]);
        }
    }
    for (int i = 0; i < 7; ++i)
    {
        if (s3[i] == '*')
        {
            key.push_back(zxcv[i]);
        }
    }
    useKey.resize(key.size());
    int q,size,j,i;
    bool ok=true,ok2;
    scanf("%d",&q);
    while(q--){
        scanf("%s",s);
        size=strlen(s);
        for (j = 0; j < useKey.size(); ++j){
            useKey[j]=false;
        }
        for(i=0;i<size;++i){
            ok=false;
            for(j=0;j<key.size();++j){
                if(s[i]==key[j]){
                    useKey[j]=true;
                    ok=true;
                    break;
                }
            }
            if(!ok){
                break;
            }
        }
        ok2=true;
        for(int j=0;j<useKey.size();++j){
            if(!useKey[j]){
                ok2=false;
                break;
            }
        }
        if(i==size&&ok2){
            printf("POSSIBLE\n");
        }
        else printf("IMPOSSIBLE\n");
    }
}