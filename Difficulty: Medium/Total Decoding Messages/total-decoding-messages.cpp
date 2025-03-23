//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int countWays(string &digits) {
        int n = digits.size();
        if (n == 0 || digits[0] == '0') return 0;

        vector<int> dp(n + 1, 0);
        dp[0] = 1;  // Empty string has one way
        dp[1] = 1;  // Single valid digit has one way

        for (int i = 2; i <= n; i++) {
            if (digits[i - 1] != '0') 
                dp[i] += dp[i - 1];  // Single digit decoding

            int twoDigit = stoi(digits.substr(i - 2, 2));
            if (twoDigit >= 10 && twoDigit <= 26) 
                dp[i] += dp[i - 2];  // Two-digit decoding
        }
        return dp[n];
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends