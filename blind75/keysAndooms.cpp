#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int i,vector<vector<int>>& rooms, vector<bool> &visited)
    {
        visited[i] = true;
        for(int key : rooms[i])
        {
            if(!visited[key])
            {
                dfs(key,rooms,visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n= rooms.size();
        vector<vector<int>> adj;
        vector<bool> visited(n,0);
        dfs(0,rooms,visited);
        for(int room : visited)
        {
            if(!room) return false;
        }
        return true;
    }
};

int main(){
    
    return 0;
}