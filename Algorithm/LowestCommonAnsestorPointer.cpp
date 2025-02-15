#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;

    node(int val) {
        data = val;
        left = right = NULL;
    }
};

node *buildTree(string str) {
    if(str.size() == 0 || str[0] == 'N') {
        return NULL;
    }

    vector<string>ip;
    istringstream iss(str);

    for(string str; iss >> str;) {
        ip.push_back(str);
    }

    node *root = new node(stoi(ip[0]));

    queue<node*>q;
    q.push(root);

    int i = 1;

    while(!q.empty() && i < ip.size()) {
        node *currNode = q.front();
        q.pop();

        string currVal = ip[i];

        if(currVal != "N") {
            currNode->left = new node(stoi(currVal));
            q.push(currNode->left);
        }

        i++;
        if(i >= ip.size()) break;

        currVal = ip[i];

        if(currVal != "N") {
            currNode->right = new node(stoi(currVal));
            q.push(currNode->right);
        }
        i++;
    }

    return root;
}

node *LCA(node *root, int a, int b) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data > a && root->data > b) {
        return LCA(root->left, a, b);
    }
    if (root->data < a && root->data < b) {
        return LCA(root->right, a, b);
    }
    return root;
}

int main() {
    string s;
    getline(cin , s);

    node *root = buildTree(s);

    int a, b;
    cin >> a >> b;
    // cout << s << ' ';

    cout << LCA(root, a, b)->data;
}