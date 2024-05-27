#include<bits/stdc++.h>

using namespace std;

long double S;
long double a, b, c;

int main() {
	scanf("%Lf%Lf%Lf%Lf", &S, &a, &b, &c);
	if (a + b + c == 0) printf("%.08Lf 0 0\n", S);
	else printf("%.15Lf %.15Lf %.15Lf", S * a / (a + b + c), S * b / (a + b + c), S * c / (a + b + c));

	return 0;
}