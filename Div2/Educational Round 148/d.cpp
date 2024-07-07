// LUOGU_RID: 110352149
// Author:dd
//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("avx2")
// #define NDBEUG
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <map>
#include <cmath>
#include <string>
#include <vector>
#include <cstring>
#include <bitset>
#include <numeric>
#include <string.h>
#include <random>
#include <cassert>
#include <iomanip>
#include <ios>
#include <map>
#include <climits>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pil pair<int,long long>
#define fer(i,a,n) for (int i=(a);i<=(n);++i)
#define rep(i,n,a) for (int i=(n);i>=(a);--i)
#define ferl(i,a,n) for (long long i=(a);i<=(n);++i)
#define repl(i,n,a) for (long long i=(n);i>=(a);--i)
#define fi first
#define se second
#define elif else if
#define no cout<<"NO\n";
#define yes cout<<"YES\n";
#define none cout<<"-1\n";
#define mul_t int _t;cin>>_t;while(_t--)
#define FASTIO ios::sync_with_stdio(false);cin.tie(0);
#define Hash gp_hash_table
#define notall(x) x.begin()+1,x.end()
#define all(x) x.begin(),x.end()

template<class T>
void print(const T& t) {
	cout << t;
}
template<class T, class...args>
void print(const T& t, const args&...rest) {
	cout << t << ' ';
	print(rest...);
}

typedef long long ll;

const int int_inf= 0x3f3f3f3f;
const ll ll_inf=1000000000000000100;

//get a pow with mod in O(logn)
ll qpow(ll a,ll k,ll mod) {
	ll res=1;
	a%=mod;
	while(k) {
		if(k&1)res=res*a%mod;
		a=a*a%mod;
		k>>=1;
	}
	return res;
}

//some modular operation
template<class T1,class T2>
void mul(T1&x,T2 y,ll mod) {
	x=(x+mod)%mod,y=(y+mod)%mod,x=(x*y)%mod;
}
template<class T1,class T2>
void dif(T1&x,T2 y,ll mod) {
	x=(x+mod)%mod,y=qpow(y,mod-2,mod),x=(x*y)%mod;
}
template<class T1,class T2>
void add(T1&x,T2 y,ll mod) {
	x=(x+mod)%mod,y=(y+mod)%mod,x=(x+y)%mod;
}
template<class T1,class T2>
void dec(T1&x,T2 y,ll mod) {
	x=(x+mod)%mod,y=(y+mod)%mod,x=(x-y+mod)%mod;
}

//great commone division
template<class T>
T gcd(T a,T b) {
	return b?gcd(b,a%b):a;
}
template<class T>
T exgcd(T a,T b,T &x,T &y) {
	T d=a;
	if(b==0)x=1,y=0; else {
		d=exgcd(b,a%b,y,x),y-=a/b*x;
	}
	return d;
}

//get primes smaller than n in O(n)
vector<bool>isnotprime;
vector<int>primes;
void getprime(int n) {
	isnotprime.resize(n+1,0);
	isnotprime[1]=1;
	for (int i=2;i<=n;i++) {
		if(isnotprime[i]==0)primes.push_back(i);
		for (size_t j=0;j<primes.size()&&i*primes[j]<=n;j++) {
			isnotprime[i*primes[j]]=1;
			if(i%primes[j]==0)break;
		}
	}
}

//get euler function smaller than n in O(n)
vector<ll>phi;
void getphi(int n) {
	isnotprime.resize(n+1,0);
	phi.resize(n+1,0);
	phi[1]=1,isnotprime[1]=1;
	for (int i=2;i<=n;i++) {
		if(isnotprime[i]==0) {
			primes.push_back(i);
			phi[i]=i-1;
		}
		for (size_t j=0;j<primes.size()&&i*primes[j]<=n;j++) {
			isnotprime[i*primes[j]]=1;
			if(i%primes[j]==0) {
				phi[i*primes[j]]=phi[i]*primes[j];
				break;
			}
			phi[i*primes[j]]=phi[i]*(primes[j]-1);
		}
	}
}

//get mobius function smaller than n in O(n)
vector<ll>mu;
void getmu(int n)
{
	isnotprime.resize(n+1,0);
	mu.resize(n+1,0);
	mu[1]=1,isnotprime[1]=1;
	for(int i=2;i<=n;i++) {
		if(isnotprime[i]==0) {
			primes.push_back(i);
			mu[i]=-1;
		}
		for (size_t j=0;j<primes.size()&&i*primes[j]<=n;j++) {
			isnotprime[i*primes[j]]=1;
			if(i%primes[j]==0) {
				mu[i*primes[j]]=0;
				break;
			}
			mu[i*primes[j]]=-mu[i];
		}
	}
}

//combinations
struct combination {
	combination(int n,ll mo) {
		siz=n,mod=mo;
		inv.resize(n+1,1),preinv.resize(n+1,1),fac.resize(n+1,1);
		for (int i=2;i<=n;i++)inv[i]=(mod-mod/i)*inv[mod%i]%mod,preinv[i]=preinv[i-1]*inv[i]%mod;
		for (long long i=2;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	}
	ll C(int n,int m) {
		if(n==0&&m==0)return 1;
		if(n<m||m<0||n<0)return 0;
		return fac[n]*preinv[m]%mod*preinv[n-m]%mod;
	}
	ll A(int n,int m) {
		if(n==0&&m==0)return 1;
		if(n<m||m<0||n<0)return 0;
		return fac[n]*preinv[n-m]%mod;
	}
	vector<ll>inv;
	vector<ll>preinv;
	vector<ll>fac;
	private:int siz;
	ll mod;
};

//DSU
struct dsu {
	vector<int>fa,siz;
	dsu(int n) {
		fa.resize(n+1),siz.resize(n+1);
		for (int i=1;i<=n;i++)fa[i]=i,siz[i]=1;
	}
	int ffind(int x) {
		return x==fa[x]?x:fa[x]=ffind(fa[x]);
	}
	bool uuion(int x,int y) {
		x=ffind(x),y=ffind(y);
		if(x==y)return false;
		fa[y]=x,siz[x]+=siz[y],siz[y]=0;
		return true;
	}
	bool check(int x,int y) {
		return ffind(x)==ffind(y);
	}
	void init() {
		for (size_t i=1;i<=fa.size()-1;i++)fa[i]=i,siz[i]=1;
	}
	int getsize(int x) {
		return siz[x];
	}
};

//operations with bit
struct Bitcounter {
	template<class T>T reversebit(T x) {
		int f=1;
		if(x<0)x=-x,f=-1;
		vector<int>v;
		while(x) {
			v.push_back(x&1);
			x>>=1;
		}
		reverse(v.begin(),v.end());
		T now=1,ans=0;
		for (auto&x:v)ans+=x*now,now<<=1;
		return ans*f;
	}
	template<class T>T lowbit(T x) {
		return x&-x;
	}
	template<class T>int countbit(T x) {
		int sum=0;
		while(x)sum+=x&1,x>>=1;
		return sum;
	}
	template<class T>T nextknum(T x,int n) {
		if(!x||lowbit(x)>=(T)1<<(n-countbit(x)))return 0;
		T a=lowbit(x),b=x+a,c=b^x,m=(c>>2)/a;
		return b|m;
	}
};

//reverse a number in decimal
template<class T>
T reverseD(T x) {
	int f=1;
	if(x<0)x=-x,f=-1;
	vector<int>v;
	while(x) {
		v.push_back(x%10);
		x/=10;
	}
	reverse(v.begin(),v.end());
	T now=1,ans=0;
	for (auto&x:v)ans+=x*now,now*=10;
	return ans*f;
}

template<class T1,class T2>
T1 updiv(T1 a,T2 b) {
	if(a<0)return a/b;
	return a/b+(a%b!=0);
}
template<class T1,class T2>
T1 downdiv(T1 a,T2 b) {
	if(a>0)return a/b;
	return a/b-(a%b!=0);
}

void strerase(string&s,char c) {
	string t;
	for (auto&ch:s) {
		if(ch==c)continue;
		t+=ch;
	}
	s=t;
}

template<class T1,class T2>
void cmin(T1&a,T2 b) {
	a=min<T1>(a,b);
}
template<class T1,class T2>
void cmax(T1&a,T2 b) {
	a=max<T1>(a,b);
}

//-------------------------------------------
void solve() 
{
	ll n,q;
	cin>>n>>q;
	vector<ll>a(n+1);
	fer(i,1,n)cin>>a[i];
	sort(notall(a));
	auto mn=a;
	fer(i,1,n)mn[i]-=(i-1);
	auto pre=mn;
	mn[0]=1145141919180;
	fer(i,1,n)pre[i]+=pre[i-1],mn[i]=min(mn[i],mn[i-1]);
	a[0]=-1145141919180,pre[0]=1145141919180;
	fer(_,1,q)
	{
		ll x;
		cin>>x;
		if(n==1)
		{
			if(x&1)cout<<a[1]+x/2+1<<' ';
			else cout<<a[1]-x/2<<' ';
			continue;
		}
		auto check=[&](ll k)
		{
			auto pos=lower_bound(notall(a),k)-a.begin();//pos~n is ok
			if(pos==1)return true;
			if(pos-1>x)return false;
			if(pos==n+1&&(x<n||(x-n)%2==1))return false;
			if(x+mn[pos-1]<k)return false;
			
			//pos-1 个数字需要操作，只考虑这些数字
			ll remain=x-(pos-1)-2*((x-k)*(pos-1)+pre[pos-1]);
			if(remain<=0)return true;
			if(pos==n+1&&remain>0)return false;
			if(remain%2==1)return true;
			if(n-pos+1>=2)return true;
			if(a[n]-remain/2>=k)return true;
			return false;
		};
		
		ll l=-1e10,r=1e10,ans=-1;
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			if(check(mid))ans=mid,l=mid+1;
			else r=mid-1;
		}
		cout<<ans<<' ';
	}
}
signed main() {
	FASTIO
#define	OJ
#ifndef OJ
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
//#define MUL_CASE
#ifdef MUL_CASE
	mul_t solve();
#else 
	solve();
#endif
}
/*
  1.深呼吸，不要紧张，慢慢读题，读明白题，题目往往比你想的简单。
  2.暴力枚举:枚举什么，是否可以使用一些技巧加快枚举速度（预处理、前缀和、数据结构、数论分块）。
  3.贪心:需要排序或使用数据结构（pq）吗，这么贪心一定最优吗。
  4.二分：满足单调性吗，怎么二分，如何确定二分函数返回值是什么。
  5.位运算：按位贪心，还是与位运算本身的性质有关。
  6.数学题：和最大公因数、质因子、取模是否有关。
  7.dp：怎么设计状态，状态转移方程是什么，初态是什么，使用循环还是记搜转移。
  8.搜索：dfs 还是 bfs ，搜索的时候状态是什么，需要记忆化吗。
  9.树上问题：是树形dp、树上贪心、或者是在树上搜索。
  10.图论：依靠什么样的关系建图，是求环统计结果还是最短路。
  11.组合数学：有几种值，每种值如何被组成，容斥关系是什么。
  12.交互题：log(n)次如何二分，2*n 次如何通过 n 次求出一些值，再根据剩余次数求答案。
  13.如果以上几种都不是，多半是有一个 point 你没有注意到，记住正难则反。
 */