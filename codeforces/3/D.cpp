#include<cstdio>
#include<queue>
using namespace std;
struct Data {        //优先队列的元素
    int delta;        //这是-b+a
    char *p;        //这是?的位置
    bool operator <(const Data &b)const {    //重定义比较运算符进行降序排列
        return delta>b.delta;
    }
}t;
priority_queue<Data> q;        //优先队列
char s[50002];
int main() {
    int mark=0;            //计数器
    long long ans=0;
    scanf("%s",s);
    for(int i=0,a,b;s[i]&&ans!=-1;++i) {
        if(s[i]=='(')    //计数器加1
            ++mark;
        else {
            --mark;        //计数器减1，'?'也一样，因为开始时设想所有的'?'都是')'
            if(s[i]=='?') {
                scanf("%d%d",&a,&b);
                t.delta=a-b;
                t.p=s+i;    //给指针赋值
                q.push(t);    //入队
                s[i]=')';
                ans+=b;
            }
        }
        if(mark<0) {        //此时要到前面去找'?'
            if(q.empty())
                ans=-1;        //如果队列为空，那么字符串不合法
            if(ans!=-1) {
                mark+=2;
                t=q.top();    //取队尾元素并替换
                q.pop();
                *t.p='(';
                ans+=t.delta;
            }
        }
    }
    if(mark)    //判断计数器是否为0，否则字符串不合法
        ans=-1;
    printf("%I64d",ans);    //用%I64d
    if(ans!=-1)
        printf("\n%s",s);
    return 0;
}
 			  		    			    	  				 	 	