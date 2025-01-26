#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i <  n; i++) {
        cin >> a[i];
    }

    int len = sqrt(n) + 1;
    vector<int> b(len);
    for (int i=0; i<n; ++i)
        b[i / len] += a[i];


    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;

        int sum = 0;
        for (int i=l; i<=r; ){
            if (i % len == 0 && i + len - 1 <= r) {
                sum += b[i / len];
                i += len;
            }
            else {
                sum += a[i];
                i++;
            }
        }
        cout << sum << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc = 1; 
    // cin >> tc;
    for( int t = 1; t <= tc; t++ ) {
        solve();
    }
}