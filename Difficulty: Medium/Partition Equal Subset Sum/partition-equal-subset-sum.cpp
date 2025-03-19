//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool checksubsets(vector<vector<int>> &dp, int n, int sum, vector<int> &arr){
        if(sum == 0) return true;
        if(n == 0) return false;
        
        if(dp[n-1][sum] != -1) return dp[n-1][sum];
        
      int take = checksubsets(dp, n-1, sum, arr);
      int notTake = 0;
        if(arr[n-1] <= sum)  {
           notTake = checksubsets(dp, n-1, sum-arr[n-1], arr);
        }
        return dp[n-1][sum] = take || notTake;
    }
    bool equalPartition(vector<int>& arr) {
        // code here
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if(sum % 2 != 0) return false;
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> ((sum/2)+1, -1));
        if( checksubsets(dp, n, sum/2, arr) ) return true;
        return false;
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
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends