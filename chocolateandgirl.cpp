#include <bits/stdc++.h>

using namespace std;
 
#define ll long long int
 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define _cin ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
 
#define INF 2147483647
#define MAXN 100004

ll mod = 1000000007;

int main()
{
	_cin;
	ll t, n;
	cin >> t;
	while(t--){
		cin >> n;
		string str;
		cin >> str;
		vector<pair<char, ll> > v;
		char ch = str[0];
		ll ct = 1;
		for(int i=1; i<n; i++){
			if(str[i] == ch){
				ct++;
			}
			else{
				v.pb(mp(ch, ct));
				ct = 1;
				ch = str[i];
			}
		}
		v.pb(mp(ch, ct));
		int sz = v.size();
		ll c[26];
		pll cc[26][26];
		for(int i=0; i<26; i++){
			c[i] = 0;
			for(int j=0; j<26; j++){
				cc[i][j].fi = 0;
				cc[i][j].se = 0;
			}
		}
		map<pair<char, char>, ll> m;
		ll ans = 0, i1, i2, diff, a, b;
		for(int i=0; i<sz; i++){
			c[v[i].fi-97] = max(c[v[i].fi-97], v[i].se);
		}
		for(int i=0; i<26; i++){
			ans = ans + c[i];
		}
		for(int i=0; i<sz-1; i++){
			i1 = v[i].fi - 97;
			i2 = v[i+1].fi - 97;
			a = cc[i1][i2].fi;
			b = cc[i1][i2].se;
			//cout << i1 << " " << i2 << " " << a << " " << b << " " << v[i].se << " " << v[i+1].se << endl;
			if(v[i].se > a && v[i+1].se > b){
				/*diff = v[i].se - a;
				ans = ans + diff * v[i+1].se;
				diff = v[i+1].se - b;
				ans = ans + diff * a;*/
				ans = ans - (a * b);
				ans = ans + v[i].se * v[i+1].se;
			}
			else if(v[i].se > a){
				diff = v[i].se - a;
				ans = ans + diff * v[i+1].se;
			}
			else if(v[i+1].se > b){
				diff = v[i+1].se - b;
				ans = ans + diff * v[i].se;
			}
			cc[i1][i2].fi = max(cc[i1][i2].fi, v[i].se);
			cc[i1][i2].se = max(cc[i1][i2].se, v[i+1].se);
		}
		cout << ans << endl;
	}
	return 0;
}