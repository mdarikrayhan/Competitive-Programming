#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 4;
typedef long long ll;
const double eps = 1e-9;
struct quat {
	double s, x, y, z;
	quat(double _s = 0, double _x = 0, double _y = 0, double _z = 0) : s(_s), x(_x), y(_y), z(_z) {}
	quat operator + (quat  rhs) { return quat(s + rhs.s, x + rhs.x, y + rhs.y, z + rhs.z);}
	quat operator - (quat  rhs) { return quat(s - rhs.s, x - rhs.x, y - rhs.y, z - rhs.z);}
	quat operator * (quat  rhs) { 
		return quat(
			s * rhs.s - x * rhs.x - y * rhs.y - z * rhs.z,
			s * rhs.x + x * rhs.s + y * rhs.z - z * rhs.y,
			s * rhs.y - x * rhs.z + y * rhs.s + z * rhs.x,
			s * rhs.z + x * rhs.y - y * rhs.x + z * rhs.s
		);	
	}
	//quat operator / (const double  rhs) const { return quat(s / rhs, x / rhs, y / rhs, z / rhs);}
	quat operator * (double rhs) { return quat(s * rhs, x * rhs, y * rhs, z * rhs);}
	double norm() { return s * s + x * x + y * y + z * z;}
	quat conj() { return quat(s, -x, -y, -z);}
	quat inv() { return conj() * quat(1.0 / norm());}
	quat qround() const {
		quat q1 = quat(round(s), round(x), round(y), round(z));
		quat q2 = quat(round(s - 0.5) + 0.5, round(x - 0.5) + 0.5, round(y - 0.5) + 0.5, round(z - 0.5) + 0.5);
		return (q1 - *this).norm() < (q2 - *this).norm() ? q1 : q2;
	}
	quat operator / (quat rhs)  {	return rhs.inv() * *this;}
	quat operator % (quat rhs)  {	return (*this) - rhs * ((*this) / rhs).qround();}
	void print() {
		printf("%lld %lld %lld\n", (ll)round(x), (ll)round(y), (ll)round(z));
	}
} a[MAXN];
quat gcd(quat x, quat y) { return y.norm() < eps ? x : gcd(y, x % y);}
int n;
vector<ll> d;
int main() {
	scanf("%d", &n);
	quat g = quat(0);
	ll G = 0;
	for(int i = 1; i <= n ;i++) {
		ll x, y, z;
		scanf("%lld%lld%lld", &x, &y, &z);
		a[i] = quat(0, (double)x, (double)y, (double)z);
		g = gcd(g, a[i]);
		G = __gcd(G, (ll)a[i].norm());
	}
	for(ll i = 1; i * i <= G; i++) {
		if(G % (i * i) == 0) {
			d.push_back(i);
		}
	}
	sort(d.rbegin(), d.rend());
	for(ll v : d) {
		quat q = gcd(g, quat(v));
		bool flag = false;
		ll r = q.norm();
		if(r != v) continue;
		for(int i = 1; i <= n; i++) {
			quat tmp = (q.conj() * (1.0 / r)) * a[i] * (q * (1.0 / r));
			if(abs(tmp.s - round(tmp.s)) > eps || abs(tmp.x - round(tmp.x)) > eps || abs(tmp.y - round(tmp.y)) > eps || abs(tmp.z - round(tmp.z)) > eps ){
				flag = true; break;
			}
		}
		if(flag) continue;
		printf("%lld\n", r * r);
		(q * quat(0, 1, 0, 0) * q.conj()).print();
		(q * quat(0, 0, 1, 0) * q.conj()).print();
		(q * quat(0, 0, 0, 1) * q.conj()).print();
		break;
	}
	return 0;
}