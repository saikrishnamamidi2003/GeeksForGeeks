//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Your code here
        priority_queue<pair<float,vector<int>>, vector<pair<float,vector<int>>>, greater<> > mh;
        for(int i=0; i<points.size(); i++){
            vector<int> point = points[i];
            int x = point[0];
            int y = point[1];
           float dis = sqrt((x*x) + (y * y) );
           mh.push( {dis,{ x, y}});
        }
        vector<vector<int>> res;
        while(k-- && !mh.empty()){
            res.push_back({mh.top().second});
            mh.pop();
        }
        return res;
    }
};






//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        Solution ob;
        vector<vector<int>> ans = ob.kClosest(points, k);
        sort(ans.begin(), ans.end());
        for (const vector<int>& point : ans) {
            cout << point[0] << " " << point[1] << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends