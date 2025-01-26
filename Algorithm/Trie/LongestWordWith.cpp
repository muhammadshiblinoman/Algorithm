#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];
    bool flag = false;

    bool computeKey(char ch) {
        return links[ch-'a'] != NULL;
    }

    void put(char ch, Node* node) {
        links[ch-'a'] = node;
    }

    Node* get(char ch) {
        return links[ch-'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool getEnd() {
        return flag;
    }
};

class Trie{
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void inserting(string word) {
        Node* node = root;
        for(auto u: word) {
            if(!node->computeKey(u)) {
                node->put(u, new Node());
            }

            node = node->get(u);
        }

        node->setEnd();
    }

    bool checkIfPrefixExist(string word) {
        bool fl = true;
        Node* node = root;

        for(auto u: word) {
            if(node->computeKey(u)) {
                node  = node->get(u);

                if(node->getEnd() == false) {
                    return false;
                }
            } else {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Trie trie;
    int n;
    cin >> n;
    vector<string>s(n);

    for(int i = 0;i < n; i++) {
        cin >> s[i];
        trie.inserting(s[i]);
    }

    string ans = "";

    for(auto u: s) {
        if(trie.checkIfPrefixExist(u)) {
            if(ans.size() < u.size()) {
                ans = u;
            } else if(ans.size()==u.size() && ans < u) {
                ans = u;
            }
        }
    }

    cout << ans << '\n';
}