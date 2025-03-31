//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        unordered_map<char, int> lastIndex;
        int n = s.size();
        
        // Step 1: Store last occurrence of each character
        for (int i = 0; i < n; i++) {
            lastIndex[s[i]] = i;
        }

        // Step 2: Iterate and make partitions
        int partitions = 0, end = 0;
        for (int i = 0; i < n; i++) {
            end = max(end, lastIndex[s[i]]);
            if (i == end) { // When we reach the last occurrence of all seen characters
                partitions++;
            }
        }
        return partitions;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends