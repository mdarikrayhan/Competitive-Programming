#include <bits/stdc++.h>
 
using namespace std;
 
int k, n, tmp[200000], cnt = 0;
 
double X[4010], Y[4010], avg1[10010], avg2[10010], Ansx[200000], Ansy[1200000], qwq[200000];
 
double sqr(double x) {return x * x;}
 
double dis(int a, int b, int c, int d) {return sqrt(sqr(c - a) + sqr(d - b));}
 
vector <double> V;
 
void Do(double x, double y, double o) {
    V.clear();
	for(int s = 1; s <= k * n; s++)
		V.push_back(pow(dis(x, y, X[s], Y[s]), o));
	sort(V.begin(), V.end());
	for(int i = 0; i < V.size(); i++) avg1[i] = V[i], avg2[i] = V[i] * V[i];
	for(int i = 1; i < V.size(); i++) avg1[i] += avg1[i - 1], avg2[i] += avg2[i - 1];
}
 
double getval(double x, double y) {
    Do(x, y, 2);
	double magic = 1e100;
	int n = ::n - 2;
	for(int i = n; i < V.size(); i++) magic = min(magic, avg2[i] - avg2[i - n] - sqr(avg1[i] - avg1[i - n]) / n);
	return magic;
}
 
double getr(double x, double y) {
	Do(x, y, 1);
	double magic = 1e100;
	int v, n = ::n - 2;
	for(int i = n; i < V.size(); i++) {
		double s = avg2[i] - avg2[i - n] - sqr(avg1[i] - avg1[i - n]) / n;
		if(s < magic) magic = s, v = i;
	}
	return (avg1[v] - avg1[v - n]) / n;
}
 
bool cmp(int x, int y) {return qwq[x] < qwq[y];}
 
int main() {
	scanf("%d%d", &k, &n);
	for(int i = 1; i <= k * n; i++) scanf("%lf%lf", &X[i], &Y[i]);
	for(int i = -50; i <= 50; i++)
		for(int j = -50; j <= 50; j++) if(dis(0, 0, i * 20000, j * 20000) <= 1e6)
			Ansx[++cnt] = i * 20000, Ansy[cnt] = j * 20000, qwq[cnt] = getval(i * 20000, j * 20000);
	for(int i = 1; i <= k; i++) {
		for(int i = 1; i <= cnt; i++) tmp[i] = i;
		sort(tmp + 1, tmp + cnt + 1, cmp);
		printf("%.12lf %.12lf %.12lf\n", Ansx[tmp[1]], Ansy[tmp[1]], getr(Ansx[tmp[1]], Ansy[tmp[1]]));
		double x = Ansx[tmp[1]], y = Ansy[tmp[1]];
		for(int i = 1; i <= cnt; i++) if(dis(Ansx[i], Ansy[i], x, y) <= 4e5) qwq[i] = 1e100;
	}
	return 0;
}