#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void build(int i, int l, int r, vector<int>& baskets, vector<int>& segmentTree) {
        if (l == r) {
            segmentTree[i] = baskets[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * i + 1, l, mid, baskets, segmentTree);
        build(2 * i + 2, mid + 1, r, baskets, segmentTree);
        segmentTree[i] = max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
    }

    // Returns true if a valid basket was found and consumed, false otherwise
    bool placeFruit(int f, int i, int l, int r, vector<int>& segmentTree) {
        // Step 1: Range maximum is smaller than fruit capacity -> impossible in this subtree
        if (segmentTree[i] < f) {
            return false;
        }

        // Step 2: Leaf node reached -> consume the basket
        if (l == r) {
            segmentTree[i] = -1; // Mark basket as used
            return true;
        }

        int mid = l + (r - l) / 2;
        bool placed = false;

        // Step 3: Prioritize leftmost valid basket
        if (segmentTree[2 * i + 1] >= f) {
            placed = placeFruit(f, 2 * i + 1, l, mid, segmentTree);
        } else {
            placed = placeFruit(f, 2 * i + 2, mid + 1, r, segmentTree);
        }

        // Step 4: Pull updated max values back up to maintain segment tree invariants
        segmentTree[i] = max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);

        return placed;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int> segmentTree(4 * n);
        
        build(0, 0, n - 1, baskets, segmentTree);

        int unplaced = 0;
        for (int f : fruits) {
            if (!placeFruit(f, 0, 0, n - 1, segmentTree)) {
                unplaced++;
            }
        }

        return unplaced;
    }
};