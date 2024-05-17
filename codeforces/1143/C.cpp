// LUOGU_RID: 159214142
#include<bits/stdc++.h>
using namespace std;
struct treenode{
	int p;
	vector<int>child;
	int rsp;
};
vector<int>dlt;
int n;
treenode tree[100005];
void dfs(treenode*arr,int a)//根节点 --3
{
	//cout << "当前节点: " << a << " rsp: " << arr[a].rsp << " 孩子节点: ";
		bool is=true; //要删 
//		if(arr[a].rsp==1&&arr[a].child.size()==0)//叶子节点 
//		{
//			dlt.push_back(a);
//			cout<<endl;
//			for(int i=0;i<dlt.size();i++)
//			{
//				cout<<"dlt:"<<dlt[i]<<endl;
//			}
//			cout<<endl;
//			is=true;
//		}
		for(int i=0;i<arr[a].child.size();i++)//遍历当前节点3的孩子- 1,5 
		{
			//cout << arr[a].child[i] <<endl;
			if(arr[arr[a].child[i]].rsp==0)//并且他的孩子尊重他- 
			{
				is=false; 
			}
			dfs(arr,arr[a].child[i]);//递归调用所有子节点 
		}
		if(arr[a].rsp==1&&is==true)//不尊重他爸，并且他的所有孩子都不尊重他 
		{
			dlt.push_back(a);
//			cout<<endl;
//			for(int i=0;i<dlt.size();i++)
//			{
//				cout<<"dlt:"<<dlt[i]<<endl;
//			}
//			cout<<endl;
		}
}

int main()
{
	//cout<<"1"<<endl;
	cin>>n;
	int m;
	for(int i=1;i<=n;i++)
	{//第一个节点的父亲和第一个节点是否尊重父母 3,1不尊重，3的子孩子是1，要加入孩子数组 
		cin>>tree[i].p>>tree[i].rsp; 
		if(tree[i].p!=-1)// 
		{//通过访问父节点来访问子节点的信息 
			tree[tree[i].p].child.push_back(i);//比如3这个父节点的孩子是1加入数组 
		} 
		else
		{
			m=i ;
		}
	}
//	for (int i = 1; i <= n; i++)
//    {
//        cout << "节点" << i << " 的父节点和是否尊重父母: " << tree[i].p << " " << tree[i].rsp << endl;
//    }

	dfs(tree,m); 
	sort(dlt.begin(),dlt.end());
	if(dlt.empty())
	{
		cout<<"-1"<<endl;
	}
	else
	{
		for(int i=0;i<dlt.size();i++)
		{
			cout<<dlt[i]<<" ";
		}
		cout<<endl;
	}
} 