// LUOGU_RID: 159194378
#include <bits/stdc++.h>
int N,k,k2,md,l[2009],r[2009],y[2009];
long double L1[2009],R1[2009],L2[2009],R2[2009];
struct n_t{
    long double l,r;
} op[2000009],st[2000009];
bool cmp(n_t x,n_t y) {
    return x.l<y.l;
}
bool vl(long double X,long double Y) {
    if(Y<op[1].l||op[k2].r<X) return 0;
    int l=1,r=k2;
    while(l<r) {
        md=(l+r+1)>>1;
        if(op[md].l<=Y) l=md;else r=md-1;
    }
    return (op[l].r>=X);
}
long double fmi(long double X,long double Y) {
    int l=1,r=k2;
    while(l<r) {
        md=(l+r)>>1;
        if(op[md].r>=X) r=md;else l=md+1;
    }
    return std::max(X,op[l].l);
}
long double fma(long double X,long double Y) {
    int l=1,r=k2;
    while(l<r) {
        md=(l+r+1)>>1;
        if(op[md].l<=Y) l=md;else r=md-1;
    }
    return std::min(Y,op[l].r);
}
signed main(void) {
    scanf("%d",&N);
    for(int i=1;i<=N;i++) {
        scanf("%d %d %d",&l[i],&r[i],&y[i]);
    }
    for(int i=1;i<=N;i++) {
        for(int j=i+1;j<=N;j++) {
            int m=y[i]-y[j],n=l[j]-r[i];
            long double ll=-1000000000000000000,rr=1000000000000000000;
            if(y[i]==y[j]) continue;
            if(m>0) rr=(long double)n/m;else if(m<0) ll=(long double)n/m;
            m=y[j]-y[i];n=l[i]-r[j];
            if(m>0) rr=(long double)n/m;else if(m<0) ll=(long double)n/m;
            st[++k]=(n_t){rr,ll};
//            printf("%.12Lf %.12Lf\n",ll,rr);
        }
        L1[i]=-1000000000000000000,R1[i]=1000000000000000000;
        for(int j=1;j<=N;j++) {
            if(i==j) continue;
            int m=y[i]-y[j],n=l[j]-r[i];
            if(m==0) {
                if(n<0) L1[i]=1000000000000000000,R1[i]=-1000000000000000000;
            } else if(m>0) {
                R1[i]=std::min(R1[i],(long double)n/m);
            } else {
                L1[i]=std::max(L1[i],(long double)n/m);    
            }
        }
        L2[i]=-1000000000000000000,R2[i]=1000000000000000000;
        for(int j=1;j<=N;j++) {
            if(i==j) continue;
            int m=y[j]-y[i],n=l[i]-r[j];
            if(m==0) {
                if(n<0) L2[i]=1000000000000000000,R2[i]=-1000000000000000000;
            } else if(m>0) {
                R2[i]=std::min(R2[i],(long double)n/m);
            } else {
                L2[i]=std::max(L2[i],(long double)n/m);    
            }
        }
    }
    std::sort(st+1,st+k+1,cmp);
    st[k+1].l=1000000000000000000;
    st[0].r=-1000000000000000000;
    st[0].l=-1000000000000000000;
    long double s1=-1000000000000000000;
    for(int i=0;i<=k;i++) {
        s1=std::max(s1,st[i].r);
        long double l=st[i].l,r=st[i+1].l;
        l=std::max(l,s1);
        if(l<=r) {
            op[++k2]=(n_t){l,r};
         //   printf("%.12Lf %.12Lf\n",l,r);
        }
    }
    long double as=1000000000000000000;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            long double X=std::max(L1[i],L2[j]);
            long double Y=std::min(R1[i],R2[j]);
            if(X-Y>0.0000001) continue;
            if(!vl(X,Y)) continue;
            if(y[j]>y[i]) {
                as=std::min(as,fmi(X,Y)*(y[j]-y[i])+r[j]-l[i]);
            } else {
                as=std::min(as,fma(X,Y)*(y[j]-y[i])+r[j]-l[i]);    
            }
        }
    }
    printf("%.12Lf",as);
}