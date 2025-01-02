#include <bits/stdc++.h>
int T,a,b,c,d,e,f,n[8],as[8];
signed main(void) {
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d %d",&a,&b,&c);
        scanf("%d %d %d",&d,&e,&f);
        for(int i=1;i<=7;i++) scanf("%d",&n[i]);
        d=n[1]+n[2]+n[3]+n[4]-d;
        e=n[1]+n[2]+n[5]+n[6]-e;
        f=n[1]+n[3]+n[5]+n[7]-f;
        std::swap(a,d);
        std::swap(b,e);
        std::swap(c,f);
        bool ff=0;
        for(int i=0;i<=n[1]+n[2];i++) {
            int lp=b-i,rp=e-i;
            if(lp<0) lp=0;
            int lm=a-i,rm=d-i;
            if(lm<0) lm=0;
            rm=std::min(rm,n[3]+n[4]);
            rp=std::min(rp,n[5]+n[6]);
            if(lp>rp||lm>rm) continue;
            int l=0,r=n[7];
            l+=std::max(0,lp-n[6]);
            l+=std::max(0,lm-n[4]);
            l+=std::max(0,i-n[2]);
            r+=std::min(n[5],rp);
            r+=std::min(n[1],i);
            r+=std::min(n[3],rm);
            if(c<=r&&l<=f&&l<=r&&c<=f) {
                int tp,ans=std::max(c,l)-l;
                as[1]=std::max(0,i-n[2]);
                tp=std::min(n[1],i)-std::max(0,i-n[2]);
                tp=std::min(tp,ans);
                as[1]+=tp;ans-=tp;
                as[3]=std::max(0,lm-n[4]);
                tp=std::min(n[3],rm)-std::max(0,lm-n[4]);
                tp=std::min(tp,ans);
                as[3]+=tp;ans-=tp;
                as[5]=std::max(0,lp-n[6]);
                tp=std::min(n[5],rp)-std::max(0,lp-n[6]);
                tp=std::min(tp,ans);
                as[5]+=tp;ans-=tp;
                tp=std::min(ans,n[7]);
                as[7]=tp;ans-=tp;
                assert(ans==0);
                as[2]=i-as[1];
                as[4]=std::max(lm-as[3],0);
                as[6]=std::max(lp-as[5],0);
                for(int i=1;i<=7;i++) printf("%d ",as[i]);
                ff=1;break;
            }
        }
        if(!ff) printf("-1");printf("\n");
    }
}