#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long

const int N = 234567;
int a[N], seg[4*N];

void BuildInSegmentTree(int ind, int low, int high) {
    if(low == high) {
        seg[ind] = a[low];
        return;
    }

    int mid = (low+high)/2;

    BuildInSegmentTree(2*ind+1, low, mid);
    BuildInSegmentTree(2*ind+2, mid+1, high);

    seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    return;
}

void update(int ind, int low, int high, int pos, int new_val) {
    if (low == high) {
        seg[ind] = new_val;
    } else {
        int tm = (low + high) / 2;
        if (pos <= tm)
            update(ind*2+1, low, tm, pos, new_val);
        else
            update(ind*2+2, tm+1, high, pos, new_val);
        
        seg[ind] = seg[ind*2+1] + seg[ind*2+2];
    }
}

int query(int ind, int low, int high, int l, int r) {
    if(high < l || low > r) return 0;
    if(low >= l && high <= r) {
        return seg[ind];
    }


    int mid = (low+high) / 2;
    int left = query(2*ind+1, low, mid, l, r);
    int right = query(2*ind+2, mid+1, high, l, r);

    return left + right;
}

void solve() {
    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    BuildInSegmentTree(0, 0, n-1);

    while(q--) {
        int check, l, r;
        cin >> check >> l >> r;
        l--, r--;

        if(check == 2) {
            cout << query(0, 0, n-1, l, r) << '\n';
        } else {
            r++;
            update(0, 0, n-1, l, r);
        }
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