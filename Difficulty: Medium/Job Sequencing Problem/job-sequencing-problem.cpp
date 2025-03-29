//{ Driver Code Starts
// Driver code
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    vector<int> parent;

    // Find function with path compression
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<int> ans = {0, 0}; // {number of jobs, total profit}

        // Pair jobs with profit and deadline
        vector<pair<int, int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }

        // Sort jobs by profit in descending order
        sort(jobs.rbegin(), jobs.rend());

        // Find the maximum deadline
        int max_deadline = *max_element(deadline.begin(), deadline.end());
        
        // Initialize DSU parent array
        parent.resize(max_deadline + 1);
        for (int i = 0; i <= max_deadline; i++) parent[i] = i;

        for (const auto &job : jobs) {
            int p = job.first, d = job.second;

            // Find the latest available slot
            int availableSlot = find(d);
            if (availableSlot > 0) {
                ans[0]++;   // Increment job count
                ans[1] += p; // Add profit
                parent[availableSlot] = find(availableSlot - 1); // Merge sets
            }
        }

        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> deadlines, profits;
        string temp;
        getline(cin, temp);
        int x;
        istringstream ss1(temp);
        while (ss1 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            profits.push_back(x);

        Solution obj;
        vector<int> ans = obj.jobSequencing(deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends