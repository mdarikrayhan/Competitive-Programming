#include <stdio.h>
#include <stdlib.h>

int main()
{
    int w;
    scanf("%d",&w);
    if(w==2){
        printf("NO");
    }
    else if(w >=1){
            if(w<=100){
    int m;
    m=(w%2);
    if(m==0){
        printf("YES");
    }
    else{
        printf("NO");
    }

            }
    else {
    printf("NO");
    }
    }
    else{
    printf("NO");
    }
    return 0;
}
