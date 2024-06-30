#include <iostream>
#include <vector>
using namespace std;

class dsu{
    public:
    vector<int> parent;
    vector<int> rank;

    int find(int x)
    {
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    void unionfind(int x, int y)
    {
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent) return;
        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }
        else if(rank[x_parent] < rank[y_parent]){
            parent[x_parent] = y_parent;
        }
        else{
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
};

class DSU {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void union_sets(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        if (root_x == root_y) {
            return;
        }
        if (rank[root_x] < rank[root_y]) {
            parent[root_x] = root_y;
        } else if (rank[root_x] > rank[root_y]) {
            parent[root_y] = root_x;
        } else {
            parent[root_y] = root_x;
            rank[root_x]++;
        }
    }
};

int main() {
    int size = 5;
    DSU dsu(size);

    dsu.union_sets(0, 1);
    dsu.union_sets(2, 3);
    dsu.union_sets(3, 4);

    cout << "Are 1 and 3 in the same set? " << (dsu.find(1) == dsu.find(3)) << endl;
    cout << "Are 0 and 2 in the same set? " << (dsu.find(0) == dsu.find(2)) << endl;

    return 0;
}
