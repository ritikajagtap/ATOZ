/* Jai Shree Krishna */
/* Ritika Jagtap */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pb push_back
#define db pop_back
#define f first
#define s second
#define rep(i, a, b) for (ll i = a; i < b; ++i)
#define repi(i, b, a) for (ll i = b - 1; i >= a; --i)
#define all(a) (a).begin(), (a).end()
int maxSubArray(int A[], int n1);
// int solve(int x);
long long gcd(long long int a, long long int b);
long long lcm(int a, int b);
const int N = 200001;

int main()
{
    ll x;
    ll y;
    cin>>x>>y;
    cout<<gcd(x, y)<<endl;
}
// int solve(int x)
// {
// }
long long gcd(long long int a, long long int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}