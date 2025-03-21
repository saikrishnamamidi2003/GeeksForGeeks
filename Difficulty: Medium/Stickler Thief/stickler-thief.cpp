//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

class Solution {
    
    int theif(vector<int> &arr, vector<int> &dp, int ind){
        if(ind == 0){
            return arr[0];
        }
        if(ind < 0){
            return 0;
        }
        
        if(dp[ind] != -1) return dp[ind];
        
        int pick = arr[ind] + theif(arr, dp, ind-2);
        int notpick = theif(arr, dp, ind-1);
        return dp[ind] = max(pick, notpick);
    }
    
  public:
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> dp(n, -1);
        return theif(arr, dp, n-1);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends