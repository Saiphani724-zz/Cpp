//created by P.Sai Phani	
//Copyright © 2018 P.Sai Phani, All rights reserved.
#include <bits/stdc++.h> 
using namespace std;

#define mod 1000000007
#define inf 1e9
typedef long long ll;
typedef long double ld;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<float> vf;
typedef vector <ld> vd;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define vec(x) vector<x >
#define z size()
#define get(x) cin>>x
#define put(x) cout<<x
#define pls(x) cout<<x<<' '
#define pln(x) cout<<x<<"\n"
#define f(i,a,b) for(int i=a;i<b;i++)
#define F(i,a,b) for(int i=b-1;i>=a;i--)
#define vput(a) f(i,0,a.z) pls(a[i]); nl;
#define vget(v) f(i,0,v.z) get(v[i]);
#define vsort(v) sort(v.begin(),v.end())
#define all(v) v.begin(),v.end()
#define vuni(v) v.erase(unique(all(v)),v.end())
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define vmin(v) *min_element(all(v))
#define vmax(v) *max_element(all(v))
#define total(v) *accumulate(all(v),0)

#define bs(v,x) binary_search(all(v),x)
#define parray(a,n) f(i,0,n) pls(a[i]); nl;
#define ppair(x) cout<<x.first<<' '<<x.second<<"\n";
#define vp(x,y) vector<pair<x,y> >
#define p(x,y) pair<x,y >
#define endl '\n'
#define nl cout<<'\n';
#define w(a) while(a--)
#define wh(a) while(a)

ll maxi=LLONG_MAX;
ll mini=LLONG_MIN;

void fast() { ios_base::sync_with_stdio(false); cin.tie(NULL); }


#define con continue
#define ret return
#define bk break
#define setpr fixed<<setprecision
#define gl(a) getline(cin,a)
#define ppb pop_back
#define pq priority_queue

//Geometry Template
#define pi acos(-1)
#define len2(p) ((p.X)*(p.X) + (p.Y)*(p.Y))
#define len(p) (sqrt(len2(p)))
pdd norm(pdd p){ ld lenp = len(p);ret {p.X/lenp,p.Y/lenp};}
pdd rotate(pdd p,int a) {ret {cos(a)*p.X-sin(a)*p.Y,cos(a)*p.Y+sin(a)*p.X};}
ld dot(pdd p,pdd q){ret p.X*q.X+p.Y*q.Y;}
ld cross(pdd p,pdd q){ret p.X*q.Y-p.Y*q.X;}
ld cosv(pdd p,pdd q){ret dot(p,q)/(len(p)*len(q));}
ld sinv(pdd p,pdd q){ret sqrt(1 - cosv(p,q)*cosv(p,q));}
ld dist2(pii p,pii q) {ret (p.X-q.X)*(p.X-q.X)+(p.Y-q.Y)*(p.Y-q.Y);}
ld dist(pii p,pii q) {ret sqrt(dist2(p,q));}

ll gcd(ll a,ll b) { if(b>a) swap(a,b); 
	if (b==0) ret a; if(b!=0) ret gcd(b,a%b); }

int sti(string s)
{	int n=0;
	f(i,0,s.z){
		n*=10;
		n+=(s[i]-'0');}
	ret n; }

ll power(ll x,ll y)
{
	ll p = 1000000007;
    ll res = 1;
    x = x % p;
    while (y > 0){
        if (y & 1) res = (res*x) % p;
    	y = y>>1;
        x = (x*x) % p;}
    ret res%p; 
}
ll modInverse(ll a, ll m)
{
    ll m0 = m;
    ll y = 0, x = 1;
 
    if (m == 1)
      return 0;
 
    while (a > 1)
    {
        // q is quotient
        ll q = a / m;
        ll t = m;
 
        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;
 
        // Update y and x
        y = (x - q * y);
        x = t;
    }
 
    // Make x positive
    if (x < 0)
       x += m0;
 
    return x;
}

ll C[205][205];
void nCr()
{
	f(i,0,205)
	{
		C[i][i]=1;
		C[i][0]=1;
	}
	f(i,1,205)
	{
		C[i][1]=i;
	}
	f(r,1,204)
	{
		f(n,r+1,203)
		{
			C[n][r]=((C[n-1][r-1]%mod)+(C[n-1][r]%mod))%mod;
		}
	}
}

bool isPal(string s)
{
	string s1 = s.substr(0,s.z/2);
	string s2=s.substr((s.z+1)/2,s.z/2);
	reverse(all(s2));
	// pls(s1),pln(s2);
	if(s1==s2)
		ret 1;
	else
		ret 0;
}
 

vb prm(100005,1);
// vi p;
void sieve()
{
	prm[0]=prm[1]=0;
	for(int i=2;i*i<=prm.z;i++)
	{
		if(prm[i])
		for(int j=i*2;j<prm.z;j+=i)
		{
			prm[j]=0;
		}
	}
	// f(i,0,prm.z)
	// if(prm[i]) p.pb(i);
}

struct line{int a,b,c;};

pdd insc(line l1,line l2){
	pair <ld,ld> p;
	ld a = l1.b*l2.c -l2.b*l1.c;
	ld b = l1.c*l2.a - l2.c*l1.a;
	ld c = l1.a*l2.b - l2.a*l1.b;
	p.X = a/c;
	p.Y = b/c;
	return p;
}

line twoPline(pdd A,pdd B){
	line l;
	l.a = B.Y - A.Y;
	l.b = A.X - B.X;
	l.c = l.a*A.X+l.b*A.Y;
	l.c = -(l.c);
	ret l;
}

int main()
{

	#ifndef ONLINE_JUDGE
	freopen("C:/Users/Sai/Desktop/Competetive_Coding/input.txt", "r", stdin);
	freopen("C:/Users/Sai/Desktop/Competetive_Coding/output.txt", "w", stdout);
	#endif
	fast();	
	int t;
	get(t);
	w(t)
	{

	}



	ret 0;
}