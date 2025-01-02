#include <bits/stdc++.h>
using namespace std;
const int MX=4000100,STEP=40;
int n,m,i,j,l,r,pos,cnt[2],a[MX],b[MX];
char s[MX];
bool bad;
void msort(int l, int r) {
if (r-l<=1) return;
int mid=(l+r)/2;
msort(l,mid); if (bad) return;
msort(mid,r); if (bad) return;
int i=l,j=mid,k=l;
while (i<mid && j<r) {
if (pos>=n) { bad=true; return; }
if (s[pos++]=='0') b[k++]=a[i++]; else b[k++]=a[j++];
}
while (i<mid) b[k++]=a[i++];
while (j<r) b[k++]=a[j++];
for (int p=l; p<r; p++) a[p]=b[p];
}
int main() {
scanf("%s",s);
n=strlen(s);
l=1; r=100000;
while (l<r-STEP) {
m=(l+r)/2;
pos=0;
bad=false;
msort(0,m);
if (!bad && pos==n) break;
if (pos<n) l=m+1; else r=m;
}
m=(l+r)/2;
for (i=max(1,m-STEP); i<=min(100000,m+STEP); i++) {
for (pos=j=0; j<i; j++) a[j]=j;
bad=false;
msort(0,i);
if (!bad && pos==n) {
printf("%d\n",i);
for (j=0; j<i; j++) b[a[j]]=j;
for (j=0; j<i; j++) printf("%d ",b[j]+1);
break;
}
}
return 0;
}