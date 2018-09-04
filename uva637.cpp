#include<stdio.h>
#include<stdlib.h>
int main (){
    int n,a,b,c,t;
    while(1){
        scanf("%d",&n);
        if(n == 0)break;
        printf("Printing order for %d pages:\n",n);
        if(n == 1){
            printf("Sheet 1, front: Blank, 1\n");
            continue;
        }
        a = ((n-1)/4+1)*4;
        b = 1;
        c = 1;
        while(c <= 2*((n-1)/4+1)){
            printf("Sheet %d, ",(c+1)/2);
            if(c %2 == 1)printf("front: ");
            else printf("back : ");
            if(a > n)printf("Blank,");
            else printf("%d,",a);
            if(b > n)printf(" Blank\n");
            else printf(" %d\n",b);
            if(a > b)a--,b++;
            else a++,b--;
            t = a;
            a = b;
            b = t;
            c++;
        }
    }
    return 0;
}
/*

Sheet 1, front: Blank, 1
Sheet 1, back : 2, Blank
Sheet 2, front: 14, 3
Sheet 2, back : 4, 13
Sheet 3, front: 12, 5
Sheet 3, back : 6, 11
Sheet 4, front: 10, 7
Sheet 4, back : 8, 9
*/
