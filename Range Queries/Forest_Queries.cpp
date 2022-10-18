#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 10000000000000007
#define FOR(i,x) for(ll i = 0; i < x; i++)
#define For(i,x,y) for(ll i = x; i <= y; i++)
#define rep(i,x,y) for(int i = x; i >= y; i--)
#define vint vector<int>
#define vl vector<long>
#define vll vector<long long>
#define um unordered_map
#define pb push_back
#define pll pair<ll,ll>
#define mone cout<<-1<<"\n"
#define yess cout<<"YES\n"
#define noo cout<<"NO\n"
#define nl cout<<"\n"
#define all(x) x.begin(),x.end()
#define oset tree <int, null_type , less , rb_tree_tag, tree_order_statistics_node_update>
#define INF 1000000000000000000
const ll mx = 1e6;
/*ll numinv[mx+1];
void InverseofNumber(ll p)
{
    numinv[0] = numinv[1] = 1;
    for (ll i = 2; i <= mx; i++)
        numinv[i] = numinv[mod % i] * (mod - mod / i) % mod;
}
ll fac[mx+1] = {0}, infac[mx+1] = {0};
ll comb(ll n, ll r)
{
	if(r > n)
	return 0;
	return (fac[n]%mod * infac[r]%mod * infac[n-r]%mod)%mod;
}*/
ll power(ll a,ll b, ll m)
{
    if(b == 0)
    return 1;
    if(b&1)
    return (a%m * power((a%m * a%m)%m, (b-1)/2, m)%m)%m;
    return power((a%m * a%m)%m, b/2, m)%m;
}
ll fact(ll a, ll b)
{
    if(a == b)
    return 1;
    return (a%mod * fact(a-1,b)%mod)%mod;
}
bool sortthis(pair<ll,ll> &a,pair<ll,ll> &b)
{
    return (a.first > b.first);
}
bool prime(ll n)
{
	if(n == 2)
	return true;
	if(n%2 == 0 || n == 1)
	return false;
	for(ll i = 3; (i*i) <= n; i += 2)
	{
		if(n%i == 0)
		return false;
	}
	return true;
}
ll build(ll tree[], ll n, ll arr[], ll s, ll e)
{
	if(s == e)
	{
		tree[n] = arr[s];
		return arr[s];
	}
	ll mid = (s+e)/2;
	ll a = build(tree,2*n,arr,s,mid);
	ll b = build(tree,2*n+1,arr,mid+1,e);
	tree[n] = a^b;
	return tree[n];
}
void update(ll tree[], ll n, ll l, ll r, ll y, ll s, ll e)
{
	if(s > r || e < l)
	return;
	if(l <= s && e <= r)
	{
		tree[n] += y;
		return;
	}
	ll mid = (s+e)/2;
	update(tree,2*n,l,r,y,s,mid);
	update(tree,2*n+1,l,r,y,mid+1,e);
}
void query(ll tree[], ll arr[], ll n, ll i, ll s, ll e)
{
	if(s > i || e < i)
	return;
	if(tree[n] > 0)
	{
		ll op = tree[n];
		tree[n] = 0;
		if(s == e)
		arr[s] += op;
		else
		{
			tree[2*n] += op;
			tree[2*n+1] += op;
		}		
	}
	if(s == e)
	return;
	ll mid = (s+e)/2;
	query(tree,arr,2*n,i,s,mid);
	query(tree,arr,2*n+1,i,mid+1,e);	
}
int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t;
	t=1;
	while(t--)
	{
		ll n,q;
		cin>>n>>q;
		ll dp[n+1][n+1];
		memset(dp,0,sizeof(dp));
		For(i,1,n)
		{
			For(j,1,n)
			{
				char c;
				cin>>c;
				if(c == '*')
				dp[i][j] = 1;
				dp[i][j] += dp[i][j-1]; 
			}
		}
		For(i,1,n)
		{
			For(j,1,n)
			dp[j][i] += dp[j-1][i];
		}
//		ll tree[4*n+10] = {0};
//		FOR(i,n)
//		cin>>arr[i];
//		build(tree,1,arr,0,n-1);
		while(q--)
		{
//			ll x;
//			cin>>x;
//			if(x == 1)
//			{
//				ll l,r,y;
//				cin>>l>>r>>y;
//				--l, --r;
//				update(tree,1,l,r,y,0,n-1);
//			}
//			else
//			{
//				ll a;
//				cin>>a;
//				--a;
//				query(tree,arr,1,a,0,n-1);
//				cout<<arr[a]<<"\n";
//			}		
 
			ll x1,x2,y1,y2;
			cin>>x1>>y1>>x2>>y2;
			ll ans = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];
			cout<<ans<<"\n";
				
		}
	}
}
