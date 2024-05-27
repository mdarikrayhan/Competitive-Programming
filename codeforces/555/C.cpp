// LUOGU_RID: 157198773
#include <bits/stdc++.h>
using namespace std;

struct node{
	int l, r, x, y;
	bool operator < (const node & y) const{
		if (l != y.l)return l < y.l;
		return r < y.r;
	}
};
signed main() {
	int n, m;
	cin >> n >> m;
	set <node> st;
    st.insert((node){0, 0, 1, 1});
    st.insert((node){1, n, 1, 1});
    while (m--) {
    	char ch;
    	int x, y;
        scanf("%d%d %c", &x, &y, &ch);
        node it = *--st.lower_bound((node){x, n + 1, 1, 1});
        if (it.l <= x && x <= it.r) {
            st.erase(it);
            if (ch == 'L') {
                printf("%d\n", x - it.x + 1);
                st.insert((node){it.l, x - 1, it.x, y + 1});
                st.insert((node){x + 1, it.r, it.x, it.y});
            }else {
                printf("%d\n", y - it.y + 1);
				st.insert((node){x + 1, it.r, x + 1, it.y});
                st.insert((node){it.l, x - 1, it.x, it.y});
            }
        }else {
			printf("0\n");
		}
    }
    return 0;
}