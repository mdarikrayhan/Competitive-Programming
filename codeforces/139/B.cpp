// LUOGU_RID: 155081305
#include <bits/stdc++.h>
using namespace std;

#define reg register

template <typename T>
inline void read(T &x){
    char c;
    do
        c = getchar();
    while(c == ' ' || c == '\n');
    x = 0;
    int w = 1;
    if(c == '-'){
        w = -1;
        c = getchar();
    }
    do{
        x = (x << 1) + (x << 3) + c - '0';
        c = getchar();
    }while (c != ' ' && c != '\n');
    x *= w;
}
template <typename T>
inline void write(T arg){
	T x = arg;
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}

const int MAX = 501;
int n,m,l,w,p,h[MAX],sum[MAX],mn[MAX],ans = 0;

signed main()
{
    reg int i,j;
    read(n);
    for(i = 0;i < n;++i)
    {
        read(l);
        read(w);
        read(h[i]);
        sum[i] = l + w << 1;
        mn[i] = INT_MAX;
    }
    read(m);
    for(i = 0;i < m;++i)
    {
		read(l);
        read(w);
        read(p);
		for(j = 0;j < n;++j)
			if(l >= h[j])
                mn[j] = min(mn[j],(((sum[j] - 1) / w) / (l / h[j]) + 1) * p);
	}
    for(i = 0;i < n;++i)
        ans += mn[i];
    write(ans);
    return 0;
}