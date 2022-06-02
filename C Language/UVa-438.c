#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI acos(-1)
double Pythagorean(double x0,double x1,double y0,double y1){
    double size=sqrt(pow((x0-x1),2)+pow((y0-y1),2));
    return size;
}
double radian_to_degree(double rad)
{
    return acos(rad) * 180.0 / PI;
}
//data[0][1][2]
//     C  A  B
int main(){
    double list[6]={0};
    while(scanf("%lf%lf%lf%lf%lf%lf",&list[0],&list[3],&list[1],&list[4],&list[2],&list[5])!=EOF){
        double data[3]={0};
        for(int x=0,a=3;x<3;x++){
            if(x==2){
                data[x]=Pythagorean(list[x],list[0],list[x+a],list[3]);
            }
            else{
                data[x]=Pythagorean(list[x],list[x+1],list[x+a],list[x+a+1]);
            }
        }
        double cosA=(pow(data[2],2)+pow(data[0],2)-pow(data[1],2))/(2*data[2]*data[0]);
        double A_theta=radian_to_degree(cosA);
        double A_degree=A_theta* PI/ 180.0 ;
        double sin_A=sin(A_degree);
        double R=data[1]/(2*sin_A);
        double circumference=2*PI*R;
        printf("%f\n",circumference);
    }

    return 0;
}

