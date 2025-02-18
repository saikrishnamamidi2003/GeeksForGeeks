//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int euclid(int a, int b){
        while(a != 0 && b != 0){
            if(a > b){
                a = a%b;
            }
            else b = b % a;
        }
        if(a != 0){
            return a;
        }
        return b;
    }
    vector<int> lcmAndGcd(int a, int b) {
        // code here
        vector<int> res;
        int eu = euclid(a, b);
        int n = a*b / eu;
        res.push_back(n);
        res.push_back(eu);
        return res;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int A, B;

        cin >> A >> B;

        Solution ob;
        vector<int> ans = ob.lcmAndGcd(A, B);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends