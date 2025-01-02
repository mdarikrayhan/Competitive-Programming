#include <stdio.h>

#define N	150000
#define A	26

int max(int a, int b) { return a > b ? a : b; }

int ej[N][2], eo[N];
int pp[N], aa[N], jj[N], ll[N], ww[N][A], xx[N][A], ss[N], kbad;

void update(int i, int a, int w) {
	int o;

	ww[i][a] += w;
	while ((i = pp[i]) != -1) {
		if (ss[i] > ll[i])
			kbad--;
		ss[i] -= xx[i][a];
		xx[i][a] = 0;
		for (o = eo[i]; o--; ) {
			int j = ej[i][o];

			xx[i][a] = max(xx[i][a], xx[j][a] + ww[j][a]);
		}
		ss[i] += xx[i][a];
		if (ss[i] > ll[i])
			kbad++;
	}
}

int main() {
	static char s[2];
	int n, q, i, j, a, o, ans;

	scanf("%d%d", &n, &q);
	pp[0] = -1;
	for (j = 1; j < n; j++) {
		scanf("%d%s", &i, s), i--;
		pp[j] = i, aa[j] = s[0] != '?' ? s[0] - 'a' : -1;
		ej[i][eo[i]++] = j;
		if (aa[j] != -1)
			ww[j][aa[j]]++;
	}
	for (j = n - 1; j > 0; j--) {
		i = pp[j];
		if (ll[i] == 0)
			ll[i] = ll[j] + 1;
		else if (ll[i] != ll[j] + 1) {
			while (q--)
				printf("Fou\n");
			return 0;
		}
	}
	kbad = 0;
	for (j = n - 1; j > 0; j--)
		if (eo[j] != 1) {
			jj[j] = j;
			i = pp[j];
			while (i != 0 && eo[i] == 1) {
				jj[i] = j;
				for (a = 0; a < A; a++)
					ww[j][a] += ww[i][a];
				i = pp[i];
			}
			pp[j] = i;
			for (a = 0; a < A; a++)
				xx[i][a] = max(xx[i][a], xx[j][a] + ww[j][a]);
			ss[i] = 0;
			for (a = 0; a < A; a++)
				ss[i] += xx[i][a];
			if (ss[i] > ll[i])
				kbad++;
		}
	for (i = 0; i < n; i++)
		for (o = eo[i]; o--; ) {
			j = ej[i][o];
			ej[i][o] = jj[j];
		}
	while (q--) {
		scanf("%d%s", &i, s), i--;
		if (aa[i] != -1)
			update(jj[i], aa[i], -1);
		aa[i] = s[0] != '?' ? s[0] - 'a' : -1;
		if (aa[i] != -1)
			update(jj[i], aa[i], 1);
		if (kbad > 0)
			printf("Fou\n");
		else {
			ans = 0;
			for (a = 0; a < A; a++)
				ans += (ll[0] - (ss[0] - xx[0][a])) * (a + 1);
			printf("Shi %d\n", ans);
		}
	}
	return 0;
}
