using System;
using System.Collections.Generic;

class SegmentTree {
    const int N = 200001;
    const int M = 4000001;
    int[] l = new int[N];
    int[] r = new int[N];
    int[] x = new int[N << 2];
    int m;
    int[] v = new int[M];
    bool[] lf = new bool[M];
    bool[] rf = new bool[M];

    static void Main() {
        SegmentTree tree = new SegmentTree();
        tree.Solve();
    }

    void Solve() {
        int n = ReadInt();
        for (int i = 1; i <= n; ++i) {
            x[++m] = l[i] = ReadInt();
            x[++m] = r[i] = ReadInt();
            x[++m] = --r[i];
        }
        Array.Sort(x, 1, m + 1);
        m = Unique(x, 1, m + 1) - 1;
        for (int i = 1; i <= n; ++i) {
            l[i] = Array.BinarySearch(x, 1, m + 1, l[i]);
            r[i] = Array.BinarySearch(x, 1, m + 1, r[i]);
            Update(1, 1, m, l[i], r[i]);
            Console.Write(v[1] + " ");
        }
    }

    void Update(int x, int l, int r, int L, int R) {
        if (lf[x] && rf[x] && v[x] == 1) return;
        if (L <= l && r <= R) {
            v[x] = 1;
            lf[x] = true;
            rf[x] = true;
            return;
        }
        int p = (l + r) >> 1;
        if (L <= p) Update(x << 1, l, p, L, R);
        if (p < R) Update((x << 1) | 1, p + 1, r, L, R);
        lf[x] = lf[x << 1];
        rf[x] = rf[(x << 1) | 1];
        v[x] = v[x << 1] + v[(x << 1) | 1] - (rf[x << 1] && lf[(x << 1) | 1] ? 1 : 0);
    }

    int ReadInt() {
        int result = 0;
        int c;
        do {
            c = Console.Read();
        } while (c > '9' || c < '0');
        while (c >= '0' && c <= '9') {
            result = result * 10 + c - '0';
            c = Console.Read();
        }
        return result;
    }

    int Unique(int[] arr, int start, int end) {
        if (start == end) return start;
        int uniqueIndex = start;
        for (int i = start + 1; i < end; ++i) {
            if (arr[i] != arr[uniqueIndex]) {
                arr[++uniqueIndex] = arr[i];
            }
        }
        return uniqueIndex + 1;
    }
}
