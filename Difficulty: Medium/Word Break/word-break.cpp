//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;

// Trie Node Definition
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEnd;
    TrieNode() : isEnd(false) {}
};

class Trie {
public:
    TrieNode *root;
    Trie() { root = new TrieNode(); }

    void insert(const string &word) {
        TrieNode *node = root;
        for (char c : word) {
            if (!node->children.count(c))
                node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->isEnd = true;
    }

    bool search(const string &word) {
        TrieNode *node = root;
        for (char c : word) {
            if (!node->children.count(c))
                return false;
            node = node->children[c];
        }
        return node->isEnd;
    }
};

class Solution {
public:
    Trie trie;
    unordered_map<int, bool> memo;

    bool solve(int index, const string &s) {
        if (index == s.size()) return true;
        if (memo.count(index)) return memo[index];

        TrieNode *node = trie.root;
        for (int i = index; i < s.size(); i++) {
            if (!node->children.count(s[i])) break;
            node = node->children[s[i]];
            if (node->isEnd && solve(i + 1, s))
                return memo[index] = true;
        }
        return memo[index] = false;
    }

    bool wordBreak(string &s, vector<string> &dictionary) {
        for (const string &word : dictionary)
            trie.insert(word);
        return solve(0, s);
    }
};



//{ Driver Code Starts.

vector<string> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    vector<string> res;
    while (ss >> str) {
        res.push_back(str);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        cin >> s;
        cin.ignore();
        vector<string> dictionary = inputLine();

        Solution ob;
        if (ob.wordBreak(s, dictionary)) {
            cout << "true\n";
        } else
            cout << "false\n";
        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends