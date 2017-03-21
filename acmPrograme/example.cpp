#include <stdio.h>

int A[1005],B[1005],C[1005],N,P,H,d;
int panduan(int m)
{
	int j;
    for ( j=1;j<=d;j++)
        if ((m%B[C[j]]==0))
            return 1;
    return 0;
}
int main(void)
{
    scanf("%d",&N);
    while (N!=0){
        int j;
        double ave=0;
        
        for (j=1;j<N;j++){
            scanf("%d %d",A+j,B+j);
            ave+=A[j]*1.0/B[j];     
        }
        scanf("%d %d",&P,&H);
        d=0;
        for (j=1;j<N;j++)
            if (A[j]>P){
                d++;
                C[d]=j;
        }
        int g=0,h=0;
        g=(int)(H/ave);
        h=(int)((H-P)/ave);
        int l=0;
        for (j=1;j<N;j++) l=l+g/B[j]*A[j];
        while (l<H){
            g++;
            l=0;
            for (j=1;j<N;j++) l=l+g/B[j]*A[j];
        }
        while (panduan(g)&&(g>=h)) g--;
        l=0;
        for (j=1;j<N;j++) l=l+h/B[j]*A[j];
        while (l<H-P){
            h++;
            l=0;
            for (j=1;j<N;j++) l=l+h/B[j]*A[j];
        }
        while (panduan(h)&&(h<=g)) h++;
        if (h>g) printf("Impossible\n");else printf("%d %d\n",h,g);
        scanf("%d",&N);
    }
    return 0;
}