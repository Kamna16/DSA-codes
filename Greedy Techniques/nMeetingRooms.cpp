#include<bits/stdc++.h>
using namespace std;
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    static bool customComparator(pair<int,int> a, pair<int,int> b)
    {
        return a.second < b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({start[i],end[i]});
        }
        sort(v.begin(),v.end(),customComparator);
        int count =1;
        int ansEnd = v[0].second;
        
        for(int i=1;i<n;i++)
        {
            if(v[i].first > ansEnd)
            {
                count++;
                ansEnd = v[i].second;
            }
        }
        return count;
    }
};.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
