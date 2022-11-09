/* Jai Shree Krishna */
/* Ritika Jagtap */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef vector<bool> vb;
typedef vector<pair<int, int>> vpii;
#define sqr(x) ((ll)(x) * (x))
#define endl "\n"
#define pb push_back
#define pp pop_back
#define fi first
#define se second
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define alla(arr, sz) arr, arr + sz
#define setbits(x) __builtin_popcount(x)
#define unsetbits(x) (int)log2(x)-setbits(x)+1
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int M = 1e9 + 7;
const int P = 1e8 + 10;
// vb isPrime(P, true);

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" = "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fi); cerr << ","; _print(p.se); cerr << "}";}
template <class T, class V> void _printm(pair <T, V> p) {cerr << "{"; _print(p.fi); cerr << ":"; _print(p.se); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "{ "; for (T i : v) {_print(i); cerr << " ";} cerr << "}";}
template <class T> void _print(unordered_set <T> v) {cerr << "{ "; for (T i : v) {_print(i); cerr << " ";} cerr << "}";}
template <class T> void _print(multiset <T> v) {cerr << "{ "; for (T i : v) {_print(i); cerr << " ";} cerr << "}";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_printm(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_printm(i); cerr << " ";} cerr << "]";}

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

ll binMul(ll a ,ll b){ll ans = 0 ;while(b){if (b&1){ans = (ans+a)%M;}a = (a+a)%M;b>>= 1;}return ans ;}
ll binExp(ll a, ll b, int m) {a %= m;ll ans = 1;while (b) {if (b & 1) ans = binMul(ans,a);a = binMul(a,a);b = b >> 1;}return ans;}
// void sieve(){isPrime[0]=isPrime[1]=false;for(int i = 2; i*i < P; i++){if(isPrime[i]==true){ for(int j = i * i; j < P; j += i)isPrime[j] = false;}}}
ll gcd(ll a, ll b) {if (a == 0) return b; return gcd(b % a, a);}
ll lcm(ll a, ll b) {return ((a * b) / (gcd(a, b)));}

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    fastio();

    vi a = {1, 0, 0, 0, 3 ,5 ,9};
    vi res;
    int cnt = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if(a[i]!=0) res.pb(a[i]);
        else cnt++;
    }
    for (int i = 0; i < cnt; i++) res.pb(0);
    for (int i = 0; i < res.size(); i++) cout<<res[i]<<" ";
    
    
    return 0;
}