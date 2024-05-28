// LUOGU_RID: 154597405
#include <bits/stdc++.h>//4 iuvw 57t o43uflidy 78toulgeslkitgeso85h
using namespace std;//hgliu5 ygoi42 v7 giu4o ilu4 tguerbv.lkrhbn hf
long long a,b,x,y,xx,yy;//tyoiueyte8743cv tgb3 7645hgiu4eor ghbwrli
bool check(long long xxx,long long yyy){//3d986bvc kgac4v8743 tou4h
	xxx-=xx,yyy-=yy;//2tbc 3gfwrakgvirea543 97uy8hep9 u89epty4 utg4
	if(a==0&&b==0){//3297tc7yg3iqfugebwt5v8i t48953 7r89qr74rq t976
		if(xxx==0&&yyy==0)return 1;//4398tbyfeygbkvwg4 owqt7f84wtyy
		else return 0;//4987oqgybajfwahte yt3itr657439 trfgdxkjgvig
	}//439tghbkdzbgviwoat5 873q o3qytg3ow5b o8tgby42k5h43kj yb6i y8
	if((a*xxx+b*yyy)%(a*a+b*b)==0&&(a*yyy-b*xxx)%(a*a+b*b)==0)return 1;
	return 0;//guera ogfiwoy rf7u4ip3 8y0w yt5ygbgk4 3wtoyjuhgb3ilg
}//t5j3i vb gjtkgtuyw iuy4 loi4w t7yo5ghoiedty t7f4wigjraekrlhgverb
int main(){//t4iultuyg7i5gy8os7y87yh9thgoiu5htlug5h43uitgoyr7oygutj
	cin>>x>>y>>xx>>yy>>a>>b;//4i275tr843765tylk6hyutohgbt8xye9goy7w
	bool flag=0;//43qiuto7435o8tgfyrglhfzlboitery8957ygiuytyusgysjt
	if(check(x,y)==1||check(-x,-y)==1||check(y,-x)==1||check(-y,x)==1)cout<<"YES";
	else cout<<"NO";//8749q675tgiyakwhfjfwg68rgy2u4v5gkjygfoieugfyf
	return 0;//yrdjuew45y613y537uy6du5w3y32q6ti0432qkihrwzshgyrguer
}//54732587436t876y57tgyhubv57635uhjytdjt7kiyrijsrieyserirsy7i6uij6