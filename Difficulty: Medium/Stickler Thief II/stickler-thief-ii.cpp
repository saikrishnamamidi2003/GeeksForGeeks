//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    
    int thief(vector<int> &arr, vector<int> &dp, int ind, int start) {
        if (ind < start) return 0;
        if (ind == start) return arr[start];

        if (dp[ind] != -1) return dp[ind];

        int pick = arr[ind] + thief(arr, dp, ind - 2, start);
        int notpick = thief(arr, dp, ind - 1, start);
        
        return dp[ind] = max(pick, notpick);
    }
    
  public:
    int maxValue(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];

        vector<int> dp1(n, -1), dp2(n, -1);

        // Case 1: Exclude the last house (consider 0 to n-2)
        int case1 = thief(arr, dp1, n - 2, 0);
        
        // Case 2: Exclude the first house (consider 1 to n-1)
        int case2 = thief(arr, dp2, n - 1, 1);
        
        return max(case1, case2);
    }
};






//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends