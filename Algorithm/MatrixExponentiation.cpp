#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long

vector<vector<int>> MatrixMultyply(vector<vector<int>>a, vector<vector<int>>b) {
    int n = a.size();
    vector<vector<int>> ans;

    for(int k = 0; k < n; k++) {
        vector<int>temp;

        for(int i = 0; i < n; i++) {
            int sum = 0;

            for(int j = 0; j < n; j++) {
                sum += a[k][i] * b[j][i];
            }
            temp.push_back(sum);
        }
        ans.push_back(temp);
    }
    return ans;
}

void solve() {
    int n, pow;
    cin >> n >> pow;

    vector<vector<int>>a(n, vector<int>(n));
    vector<vector<int>>ans(n, vector<int>(n, 1));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    while(pow > 0) {
        if(pow&1) {
            ans = MatrixMultyply(ans, a);
        }
        a = MatrixMultyply(a, a);

        pow = pow / 2;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        } cout << '\n';
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