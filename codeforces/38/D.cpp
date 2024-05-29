#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
double n,x[105],y[105],x2[105],y2[105],w,xw,yw;
bool check()
{
	return xw < x[1] || xw > x2[1] || yw < y[1] || yw > y2[1];
}
double p(double x)
{
	return x * x * x;
}
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> x[i] >> y[i] >> x2[i] >> y2[i];
		if(x[i] > x2[i])	swap(x[i],x2[i]);
        if(y[i] > y2[i])	swap(y[i],y2[i]);
    }
	for(int ed=2;ed<=n;ed++)
	{
		for(int st=2;st<=ed;st++)
		{
            w = 0,xw = 0,yw = 0;
            for(int i=st;i<=ed;i++)
            {
                xw += p(x2[i] - x[i]) * (x[i] + x2[i]) / 2.0;
                yw += p(y2[i] - y[i]) * (y[i] + y2[i]) / 2.0;
            	w += p(x2[i] - x[i]);
            }
            xw /= w;
            yw /= w;
			if(xw < x[st-1] || xw > x2[st-1] || yw < y[st-1] || yw > y2[st-1])
			{
				cout << ed - 1;
				return 0;			
			}
		}
	}
	cout << n;
	return 0;
}