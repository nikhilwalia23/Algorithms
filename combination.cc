#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mo 1000000007
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll expo(ll a,ll b){ll res=1;while ( b > 0) {if ( b & 1)res= (res*a); a=(a*a); b= b >> 1; } return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime mod value
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
int main()
{
	ll *fact = new ll[200000 + 5];
	ll *ifact = new ll[200000 + 5];
    fact[0]=1;
    ifact[0]=1;
    ll monw=998244353;
    for(ll i=1;i<200005;i++)
    {
        fact[i]=mod_mul(fact[i-1],i,mo);
        ifact[i]=mminvprime(fact[i],mo);
    }
    int n,r;
    cin >> n >> r;
    cout << combination(n,r,mo,fact,ifact);
	return 0;
}
