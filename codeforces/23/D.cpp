#include <iostream>
#include <complex>
#include <cmath>
#include <iomanip>

using namespace std;

const long double th = 1e-7;

long double cross_product(complex<long double> a, complex<long double> b)
{
    return imag(a * conj(b));
}

bool solve(complex<long double> K, complex<long double> L, complex<long double> M)
{
    complex<long double> Md = L + L - M;
    complex<long double> Z1 = L - K;
    complex<long double> Z2 = Md - K;
    
    complex<long double> B = K + (Z1 * conj(Z1) * Z2 - Z2 * conj(Z2) * Z1) / (conj(Z1) * Z2 - Z1 * conj(Z2));
    complex<long double> A = K + K - B;
    complex<long double> C = L + L - B;
    complex<long double> D = M + M - C;
    
    // cout << real(A) << " " << imag(A) << " ";
    // cout << real(B) << " " << imag(B) << " ";
    // cout << real(C) << " " << imag(C) << " ";
    // cout << real(D) << " " << imag(D) << endl;
    
    // cout << cross_product(B - A, C - B) << endl;
    // cout << cross_product(C - B, D - C) << endl;
    // cout << cross_product(D - C, A - D) << endl;
    // cout << cross_product(A - D, B - A) << endl << endl;
    
    
    if (cross_product(B - A, C - B) < th || cross_product(C - B, D - C) < th || cross_product(D - C, A - D) < th || cross_product(A - D, B - A) < th)
        return true;
    
    cout << "YES\n";
    cout << real(A) << " " << imag(A) << " ";
    cout << real(B) << " " << imag(B) << " ";
    cout << real(C) << " " << imag(C) << " ";
    cout << real(D) << " " << imag(D) << endl;
    
    return false;
}

int main()
{
    cout << fixed;
    cout << setprecision(9);
    
    int T;
    cin >> T;
    
    while (T--)
	{
	    int x1, y1, x2, y2, x3, y3;
	    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    	complex<long double> a(x1, y1);
    	complex<long double> b(x2, y2);
    	complex<long double> c(x3, y3);
    	
    	if (abs(cross_product(a - b, c - b)) < th || (solve(a, b, c) && solve(c, b, a) && solve(b, c, a) && solve(a, c, b) && solve(c, a, b) && solve(b, a, c))) cout << "NO\n\n";
	}
	
	return 0;
}