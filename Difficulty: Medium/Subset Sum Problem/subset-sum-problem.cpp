//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    bool subset(vector<int> &arr, int sum , int ind, vector<vector<int>> &dp){
        if(sum == 0) return true;
        
        if(ind == 0){
            return arr[0] == sum;
        }
        
        if(dp[ind][sum] != -1){
            return dp[ind][sum];
        }
        
       int notTake = subset(arr, sum, ind-1, dp);
       int take = 0;
       if(arr[ind] <= sum){
           take = subset(arr, sum - arr[ind], ind-1, dp);
       }
       return dp[ind][sum] = take || notTake;
    }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (sum+1, -1));
        if( subset(arr, sum, n-1, dp) ){
            return true;
        }
        return 0;
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
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends