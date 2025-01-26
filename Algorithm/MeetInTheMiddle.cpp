#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
const int N = 1e5;

void solve() {
    int n, s;
    cin >> n >> s;

    vector<int>a(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i];

    auto get_subset_sums = [&] (int l, int r) {
        int len = (r-l+1);

        vector<int>ans;

        for(int i = 0; i < (1<<len); i++) {
            int sum = 0;
            for(int j = 0; j < len; j++) {
                if( i & (1<<j) ) {
                    sum += a[l + j];
                }
            }
            ans.push_back(sum);
        }

        return ans;
    };

    vector<int>left = get_subset_sums(0, n/2-1);
    vector<int>right = get_subset_sums(n/2, n-1);

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int ans = 0;

    for(auto u: left) {
        auto l = lower_bound(right.begin(), right.end(), s - u);
        auto r = upper_bound(right.begin(), right.end(), s - u);

        ans += (r-l);
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