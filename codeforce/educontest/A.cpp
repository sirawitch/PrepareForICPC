#include<stdio.h>
#include<vector>
using namespace std;
int main(){
    int t,n,x,y,z;
    scanf("%d",&t);
    for(int i=0;i<t;++i){
        scanf("%d",&n);
        x=1;
        y=(n-1)/2;
        z=n-x-y;
        if(y%3 != 0 && z%3 != 0){
            if(y==z){
                y+=3;z-=3;
            }
            if (x == y || x == z || y <= 0 || z <= 0)
            {
                printf("NO\n");
                continue;
            }
            printf("YES\n%d %d %d\n",x,y,z);
        }
        else if(y%3==0 && z%3==0){
            y++;
            z--;
            if (y == z)
            {
                y += 3;
                z -= 3;
            }
            if (x == y || x == z ||y<=0||z<=0)
            {
                printf("NO\n");
                continue;
            }
            printf("YES\n%d %d %d\n",x,y,z);
        }
        else if(y%3==0){
            if(z%3==1){
                ++z;
                --y;
            }
            else{
                --y;
                ++x;
            }
            if (y == z)
            {
                y += 3;
                z -= 3;
            }
            if(x==y || x==z||y<=0||z<=0){
                printf("NO\n");continue;
            }
            printf("YES\n%d %d %d\n", x, y, z);
        }
        else if(z%3==0){
            if (y % 3 == 1)
            {
                ++y;
                --z;
            }
            else
            {
                ++z;
                --y;
            }
            if (y == z)
            {
                y += 3;
                z -= 3;
            }
            if (x == y || x == z || y <= 0 || z <= 0)
            {
                printf("NO\n");
                continue;
            }
            printf("YES\n%d %d %d\n", x, y, z);
        }
        else{
            printf("NO\n");
        }
    }
}