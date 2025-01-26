#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];
    int cntEnd = 0;
    int cntPrefix = 0;

    bool containKay(char ch) {
        return links[ch-'a'] != NULL;
    }

    void put(char ch, Node* node) {
        links[ch-'a'] = node;
    }

    Node* get(char ch) {
        return links[ch-'a'];
    }

    void increaseEnd() {
        cntEnd++;
    }

    void inceasePrefix() {
        cntPrefix++;
    }

    void deleteEnd() {
        cntEnd--;
    }

    void reducePrefix() {
        cntPrefix--;
    }

    int getEnd() {
        return cntEnd;
    }

    int getPrefix() {
        return cntPrefix;
    }
};

class Trie{
private:
    Node* root;

public:
    Trie(){
        root = new Node();
    }

    void inserting(string word) {
        Node *node = root;
        for(int i = 0; i < word.size(); i++) {
            if(!node->containKay(word[i])) {
                node->put(word[i], new Node());
            }

            node = node->get(word[i]);
            node->inceasePrefix();
        }

        node->increaseEnd();
    }

    int countWordsEqualTo(string word) {
        Node* node = root;
        for(int i = 0;i < word.size(); i++) {
            if(node->containKay(word[i])) {
                node = node->get(word[i]);
            } else {
                return 0;
            }
        }

        return node->getEnd();
    }

    int countWordsStartingWith(string word) {
        Node* node = root;
        for(int i = 0;i < word.size(); i++) {
            if(node->containKay(word[i])) {
                node = node->get(word[i]);
            } else {
                return 0;
            }
        }

        return node->getPrefix();
    }

    void eraseWord(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(node->containKay(word[i])) {
                node = node->get(word[i]);
                node->reducePrefix();
            } else {
                return;
            }
        }

        node->deleteEnd();
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Trie trie;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        string word;
        cin >> word;

        if(a == 1) {
            trie.inserting(word);
        } else if(a == 2) {
            cout << trie.countWordsEqualTo(word) << '\n';
        } else if(a == 3){
            cout << trie.countWordsStartingWith(word) << '\n';
        } else {
            trie.eraseWord(word);
        }
    }
}