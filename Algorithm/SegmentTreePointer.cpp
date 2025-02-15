#include<bits/stdc++.h>
using namespace std;

struct node {
    node *left, *right;
    int sum;

    node(): left(NULL), right(NULL), sum(0) {}

    void extend() {
        if(!left) {
            left = new node();
            right = new node();
        }
    }
    void update(int index, int updateBy, int l, int r) {
        if(l == r) {
            sum += updateBy;
            return;
        }
        extend();
        int mid = (l+r)/2;
        if(index <= mid) {
            left->update(index, updateBy, l, mid);
        } else {
            right->update(index, updateBy, mid+1, r);
        }
        sum = left->sum + right->sum;
    }
    int getSum(int qs, int qe, int l, int r) {
        if(r < qs || qe < l) {
            return 0;
        }

        if(qs <=l && r <= qe) {
            return sum;
        }
        extend();

        int mid = (l+r)/2;
        return left->getSum(qs, qe, l, mid) + right->getSum(qs, qe, mid+1, r);
    }
};

int main() {
    node* rmq = new node();
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
        rmq->update(a[i], 1, 0, 1e9);
    }
    while(q--) {
        char qt;
        cin >> qt;
        if(qt == '?') {
            int a, b; cin >> a >> b;
            cout << rmq->getSum(a, b, 0, 1e9) << "\n";
        } else {
            int k, x; cin >> k >> x;
            rmq->update(a[k-1], -1, 0, 1e9);
            rmq->update(x, 1, 0, 1e9);
            a[k-1] = x;
        }
    }
}