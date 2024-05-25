#include <stdio.h>
#include <math.h>
int main()
{
    int x1,y1,r1,x2,y2,r2;
    while (scanf("%d%d%d%d%d%d",&x1,&y1,&r1,&x2,&y2,&r2)==6)
    {
        int delta1=(r2+r1)*(r2+r1);
        int delta2=(r2-r1)*(r2-r1);
        int delta3=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
        if (delta3>=delta1)
        {
            printf("%.10f\n",(sqrt(delta3*1.0)-r1-r2)/2.0);
        }
        else if (delta3<=delta2)
        {
            printf("%.10f\n",(fabs(r2*1.0-r1)-sqrt(delta3*1.0))/2.0);
        }
        else
            puts("0.00000000000");
    }
    return 0;
}
