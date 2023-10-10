#include <stdio.h>
#include<math.h>
#include <vector>
using namespace std;
double distance(pair<double,double> p1,pair<double,double> p2){
    double dis;
    dis = (p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second);
    dis = sqrt(dis);
    return dis;
}
int main(){
    int t;
    double px,py,ax,ay,bx,by;
    scanf("%d",&t);
    while(t--){
        scanf("%lf%lf",&px,&py);
        scanf("%lf%lf", &ax, &ay);
        scanf("%lf%lf", &bx, &by);
        double disAP=distance(make_pair(ax,ay),make_pair(px,py));
        double disBP = distance(make_pair(bx, by), make_pair(px, py));
        double disAO = distance(make_pair(ax, ay), make_pair(0.0, 0.0));
        double disBO = distance(make_pair(bx, by), make_pair(0.0, 0.0));
        double disAB = distance(make_pair(bx, by), make_pair(ax, ay))/2;
        if(disAP<=disBP && disAO<=disBO){
            printf("%lf\n",max(disAP,disAO));
        }
        else if (disAP >= disBP && disAO >= disBO)
        {
            printf("%lf\n", max(disBP, disBO));
        }
        else if(disAB>=disAO && disAB>=disBP){
            printf("%lf\n",disAB);
        }
        else if (disAB >= disBO && disAB >= disBP)
        {
            printf("%lf\n", disAB);
        }
        else{
            printf("%lf\n",max(disAB,max(min(disAO,disBO),min(disAP,disBP))));
        }
    }
}