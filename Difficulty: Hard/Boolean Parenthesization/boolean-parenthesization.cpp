//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countWays(string &s) {
        int n = s.length();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));

        // Base case: Single operands (T or F)
        for (int i = 0; i < n; i += 2) {
            dp[i][i][1] = (s[i] == 'T');
            dp[i][i][0] = (s[i] == 'F');
        }

        // Iterate over different substring lengths
        for (int len = 2; len < n; len += 2) {    
            for (int i = 0; i < n - len; i += 2) {
                int j = i + len;
                
                dp[i][j][0] = dp[i][j][1] = 0; // Reset values for the current subproblem

                for (int k = i + 1; k < j; k += 2) { // Iterate over operators
                    char op = s[k];
                    int leftTrue = dp[i][k - 1][1], leftFalse = dp[i][k - 1][0];
                    int rightTrue = dp[k + 1][j][1], rightFalse = dp[k + 1][j][0];

                    if (op == '&') {
                        dp[i][j][1] += leftTrue * rightTrue;
                        dp[i][j][0] += leftFalse * rightFalse + leftTrue * rightFalse + leftFalse * rightTrue;
                    } 
                    else if (op == '|') {
                        dp[i][j][1] += leftTrue * rightTrue + leftTrue * rightFalse + leftFalse * rightTrue;
                        dp[i][j][0] += leftFalse * rightFalse;
                    } 
                    else if (op == '^') {
                        dp[i][j][1] += leftTrue * rightFalse + leftFalse * rightTrue;
                        dp[i][j][0] += leftTrue * rightTrue + leftFalse * rightFalse;
                    }
                }
            }
        }
        
        return dp[0][n - 1][1]; 
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        int ans = ob.countWays(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends