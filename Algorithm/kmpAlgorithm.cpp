#include <bits/stdc++.h>
using namespace std;

void hashTable(string pattern, vector<int>&fre) {
	int len = 0;
	int i = 1;

	while(i < pattern.size()) {
		if(pattern[i] == pattern[len]) {
			len++;
			fre[i] = len;
			i++;
		} else {
			if(len != 0) {
				len = fre[len-1];
			} else {
				fre[i] = 0;
				i++;
			}
		}
	}
}

int main() {
	string text, pattern;
	cin >> text >> pattern;

	int n = text.size();
	int m = pattern.size();

	vector<int>fre(m, 0);

	hashTable(pattern, fre);

	int i = 0, j = 0;
	vector<int>ans;

	while(i < n) {
		if(text[i] == pattern[j]) {
			i++;
			j++;

			if(j == m) {
				ans.push_back(i - j);
				j = fre[j-1];
			}
		} else{
			if(j != 0) {
				j = fre[j-1];
			} else {
				i++;
			}
		}
	}

	for(auto u: ans) cout << u << " ";

}