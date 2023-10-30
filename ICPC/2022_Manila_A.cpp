#include<stdio.h>
int a=-2,b=1,c=-14,d=17;
int x;
int main(){
    scanf("%d",&x);
    if(x<=-3){
        printf("%d",-(x+4)*(x+4)+8);
    }
    else if(x<=2){
        printf("%d",a*x+b);
    }
    else{
        printf("%d",x*x*x+c*x+d);
    }
    return 0;
}