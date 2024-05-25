#include<iostream>
#include<algorithm> 
using namespace std;

const int N = 3e3+5;

int n;

struct Point
{
	int x, y;
};

Point p[N];

bool cmp(Point A, Point B)
{
	if(A.x==B.x)
		return A.y<B.y;
	else
		return A.x<B.x;	
}

int main()
{
	cin>>n;
	
	for(int i=0;i<n;i++)
		cin>>p[i].x>>p[i].y;
	
	sort(p, p+n, cmp);
	
	int cnt = 0;
	
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if((p[i].x+p[j].x)%2==0&&(p[i].y+p[j].y)%2==0)
			{
				Point temp;
				temp.x = (p[i].x+p[j].x)/2;
				temp.y = (p[i].y+p[j].y)/2;
				
				int id = lower_bound(p, p+n, temp, cmp) - p;
				//lower_bound返回一个指针 需要减去p的指针位置得到索引 
				if(p[id].x==temp.x&&p[id].y==temp.y)
					cnt++;
			}
	
	cout<<cnt<<endl;	
	return 0;
} 
 	  		 	 		 	   		 			    	