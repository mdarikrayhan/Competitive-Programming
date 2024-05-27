// LUOGU_RID: 158447471
#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x = 0,f = 0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
const int N = 2100100;
char A[N],B[N],heap[N];
int sumA[30],sumB[30],n,top;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%s%s",A+1,B+1);
	n = strlen(A+1);
	for(int i = 1;i <= n;i++)
	{
		sumA[A[i]-'A'+1]++;
		sumB[B[i]-'A'+1]++;
	}
	for(int i = 26;i >= 1;i--)
	{
		for(int j = sumA[i];j <= sumB[i]-1;j++)
		{
			heap[++top] = char(i-1)+'A';
		}
	}
	printf("%d\n",top);
	for(int i = 1;i <= n;i++)
	{
		int ch = A[i] - 'A' + 1;
		if(sumA[ch] > sumB[ch] && (heap[top] < A[i] || !sumB[ch]))
		{
			cout<<heap[top];
			//putchar(heap[top]),
			--sumA[ch],--sumB[heap[top--]-'A'+1];
		 } 
		
		else 
		{
			cout<<A[i];
			//putchar(A[i]);
			--sumA[ch],--sumB[ch];
		}
	}
	cout<<'\n';
}