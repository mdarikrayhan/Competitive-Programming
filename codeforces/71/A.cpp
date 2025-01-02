#import<regex>
char p[101];main(int n){for(scanf("%d",&n);n--;strlen(p)>10?printf("%c%d%c\n",*p,strlen(p)-2,p[strlen(p)-1]):puts(p))scanf("%s",p);}