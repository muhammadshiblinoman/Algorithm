#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long

void solve() {
    int a, b;
    cin >> a >> b;

    int ans = 1;

    while(b > 0) {
        if(b&1) {
            ans = (ans%mod * a%mod)%mod;
        }
        a = ( (a % mod) * (a % mod) ) % mod;

        b = b/2;
    }

    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc = 1; 
    // cin >> tc;
    for( int t = 1; t <= tc; t++ ) {
        solve();
    }
}