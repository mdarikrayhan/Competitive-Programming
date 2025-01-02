#include <bits/stdc++.h>

using namespace std;

typedef long long lo;

#define fi first
#define se second
#define endl "\n"
//~ #define int long long
#define pb push_back
#define fio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR for(int i=1;i<=n;i++)
#define mid ((start+end)/2)
#define ort ((bas+son)/2)
#define _ << " " <<

const lo inf = 1000000000;
const lo li = 500005;
const lo mod = 1000000007;

int n,m,a[li],k,flag,t;
lo cev;
string s;

struct Node{
	Node* left;
	Node* right;
	int val;
	Node(){
		left=NULL;
		right=NULL;
		val=0;
	}
	Node(Node* x){
		val=x->val;
		left=x->left;
		right=x->right;
	}
};

vector<Node*> v;

inline void update(Node* node,int start,int end,int l,int r){
	if(start>end || start>r || end<l)return ;
	if(start>=l && end<=r){node->val+=1;return ;}
	if(node->left==NULL)node->left=new Node();
	else node->left=new Node(node->left);
	if(node->right==NULL)node->right=new Node();
	else node->right=new Node(node->right);
	update(node->left,start,mid,l,r),update(node->right,mid+1,end,l,r);
	node->val=node->left->val+node->right->val;
}

inline int query(Node* node,int start,int end,int l,int r){
	if(node==NULL || start>r || end<l)return 0;
	if(start>=l && end<=r)return node->val;
	return query(node->left,start,mid,l,r)+query(node->right,mid+1,end,l,r);
}

inline lo f(int x){
	return ((lo)x)*(x-1)/2;
}

int main(){
	fio();
	cin>>n>>t;
	Node* head=new Node();
	v.pb(head);
	FOR{
		cin>>a[i];
		Node* tmp=new Node(v[i-1]);
		update(tmp,1,n,a[i],a[i]);
		v.pb(tmp);
	}
	while(t--){
		int l,d,r,u;
		cin>>l>>d>>r>>u;
		cev=f(n)-(f(l-1)+f(d-1)+f(n-r)+f(n-u));
		if(l!=1){
			int at=query(v[l-1],1,n,u+1,n);
			cev+=f(at);
			at=query(v[l-1],1,n,1,d-1);
			cev+=f(at);
		}
		if(r!=n){
			int at=(query(v[n],1,n,1,d-1)-query(v[r],1,n,1,d-1));
			cev+=f(at);
			at=(query(v[n],1,n,u+1,n)-query(v[r],1,n,u+1,n));
			cev+=f(at);
		}
		cout<<cev<<endl;
	}
	return 0;
}
//
