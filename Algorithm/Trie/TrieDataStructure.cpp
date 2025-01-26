#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node *links[26];
    bool flag = false;

    bool containKay(char ch) {
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

    bool isEnd(){
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
        for(int i = 0; i < word.length(); i++) {
            if(!node->containKay(word[i])) {
                node->put(word[i], new Node());
            }

            node = node->get(word[i]);
        }

        node->setEnd();
    }

    bool search(string word) {
        Node* node = root;

        for(int i = 0; i < word.length(); i++) {
            if(!node->containKay(word[i])) {
                return false;
            }

            node = node->get(word[i]);
        }

        return node->isEnd();
    }

    bool startWith(string prefix) {
        Node* node = root;

        for(int i = 0; i < prefix.size(); i++) {
            if(!node->containKay(prefix[i])) {
                return false;
            }

            node = node->get(prefix[i]);
        }

        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Trie trie;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        string s;
        cin >> a >> s;

        if(a == 1) {
            trie.inserting(s);
        } else if(a == 2) {
            trie.search(s);
            bool ok = trie.startWith(s);

            if(ok) {
                cout << "Found\n";
            } else {
                cout << "Not Found!\n";
            }
        } else {
            bool ok = trie.startWith(s);
            if(ok) {
                cout << "Found\n";
            } else {
                cout << "Not Found!\n";
            }
        }
    }
}