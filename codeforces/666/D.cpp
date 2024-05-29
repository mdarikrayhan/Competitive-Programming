// LUOGU_RID: 159660957
#include <bits/stdc++.h>
using namespace std;
int x[4], y[4], id[4], resx[4], resy[4], px[4], py[4], curdis;
int xl[4], xr[4], yl[4], yr[4], vxl[2], vxr[2], vyl[2], vyr[2], disxr, disxl, disyr, disyl, len, xpos, ypos;
inline bool checkx() {
    for (int i = 0; i < 4; i++) id[i] = i;
    do {
        vxl[0] = max(xl[id[0]], xl[id[1]]), vxr[0] = min(xr[id[0]], xr[id[1]]);
        vxl[1] = max(xl[id[2]], xl[id[3]]), vxr[1] = min(xr[id[2]], xr[id[3]]);

        vyl[0] = max(yl[id[1]], yl[id[2]]), vyr[0] = min(yr[id[1]], yr[id[2]]);
        vyl[1] = max(yl[id[0]], yl[id[3]]), vyr[1] = min(yr[id[0]], yr[id[3]]);
        if (vxl[0] > vxr[0]) continue;
        if (vxl[1] > vxr[1]) continue;
        if (vyl[0] > vyr[0]) continue;
        if (vyl[1] > vyr[1]) continue;
        if (vxr[1] < vxl[0]) continue;
        if (vyr[1] < vyl[0]) continue;
        disxr = vxr[1] - vxl[0], disxl = vxl[1] - vxr[0];
        disyr = vyr[1] - vyl[0], disyl = vyl[1] - vyr[0];
        disxl = max(disxl, 0), disyl = max(disyl, 0);
        if (min(disxr, disyr) >= max(disxl, disyl)) len = min(disxr, disyr);
        else continue;
        if (len == 0) return 0;
        if (vxr[0] + len <= vxr[1]) xpos = vxr[0];
        else xpos = vxr[1] - len;
        if (vyr[0] + len <= vyr[1]) ypos = vyr[0];
        else ypos = vyr[1] - len;
        resx[id[0]] = resx[id[1]] = xpos, resx[id[2]] = resx[id[3]] = xpos + len;
        resy[id[1]] = resy[id[2]] = ypos, resy[id[3]] = resy[id[0]] = ypos + len;
        return 1;
    } while (next_permutation(id, id + 4)); 
    return 0;
}
bool dfs(int u) {
    if (u == 4) return checkx();
    xl[u] = x[u], xr[u] = x[u], yl[u] = y[u] - curdis, yr[u] = y[u] + curdis;
    if (dfs(u + 1)) return 1;
    xl[u] = x[u] - curdis, xr[u] = x[u] + curdis, yl[u] = y[u], yr[u] = y[u];
    return dfs(u + 1);
}
inline bool check(int x) { return curdis = x, dfs(0); }
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2] >> x[3] >> y[3];
        int l = 0, r = 2e8, mid, ans = -1;
        while (l <= r) {
            mid = l + r >> 1;
            if (check(mid)) memcpy(px, resx, sizeof(int) * 4), ans = mid, memcpy(py, resy, sizeof(int) * 4), r = mid - 1;
            else l = mid + 1;
        }
        if (ans == -1) {
            cout << ans << endl;
            continue;
        }
        cout << ans << endl;
        cout << px[0] << ' ' << py[0] << endl;
        cout << px[1] << ' ' << py[1] << endl;
        cout << px[2] << ' ' << py[2] << endl;
        cout << px[3] << ' ' << py[3] << endl;
    }
    return 0;
}