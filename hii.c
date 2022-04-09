#include<stdio.h>
void find_diff(int h1,int m1,int s1,int h2,int m2,int s2,int *h3,int *m3,int *s3){
    while(s2>s1){
        --m1;
        s1+=60;
    }
    *s3=s1-s2;
    while(m2>m1){
        --h1;
        m1+=60;
    }
    *m3=m1-m2;
    *h3=h1-h2;
}
int main(){
    int h1,m1,s1,h2,m2,s2,h3,m3,s3;
    scanf("%d %d %d",&h1,&m1,&s1);
    scanf("%d %d %d",&h2,&m2,&s2);
    find_diff(h1,m1,s1,h2,m2,s2,&h3,&m3,&s3);
    printf("%.2d %.2d %.2d",h3,m3,s3);
    return 0;

}