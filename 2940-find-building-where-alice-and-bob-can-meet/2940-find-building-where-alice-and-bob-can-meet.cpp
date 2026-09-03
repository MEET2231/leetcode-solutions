class Solution {
public:
    void build(int i,vector<int>& segTree,vector<int>&heights,int l,int r)
    {
        if(l == r)
        {
            segTree[i] = l;
            return;
        }
        int mid = l + (r-l)/2;
        build(2*i+1,segTree,heights,l,mid);
        build(2*i+2,segTree,heights,mid+1,r);
        int left = segTree[2*i+1];
        int right = segTree[2*i+2];
        if(heights[left] >= heights[right])
        {
            segTree[i] = left;
        }
        else
        {
            segTree[i] = right;
        }
        return;
    }
    int segQuery(int i, int start, int end, vector<int>& segTree, vector<int>& heights, int l, int r)
    {
        if(start > r || end < l) return -1;
        if(start <= l && r <= end) return segTree[i];
        int mid = l + (r - l)/2;
        int left = segQuery(2*i+1,start,end,segTree,heights,l,mid);
        int right = segQuery(2*i+2,start,end,segTree,heights,mid + 1,r);
        if(left == -1) return right;
        if(right == -1) return left;

        return (heights[left]>=heights[right]?left:right);
    }
        int RMIQ(vector<int>& segmentTree, vector<int>& heights, int n, int a, int b) {
        return segQuery(0,a, b, segmentTree, heights,0, n - 1);
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        vector<int> segTree(4*n);
        vector<int> ans;
        build(0,segTree,heights,0,n-1);
        for(auto& q :queries )
        {
            int a = min(q[0], q[1]);
            int b = max(q[0], q[1]);

            if (a == b || heights[a] < heights[b]) {
                ans.push_back(b);
                continue;
            }
            int l = b + 1; 
            int r = n - 1;
            int res_idx = -1;
            int target = max(heights[q[0]], heights[q[1]]);

            while(l <= r) {
                int mid = l + (r - l) / 2;
                int idx = RMIQ(segTree, heights, n, l, mid);
                
                if (idx != -1 && heights[idx] > target) {
                    res_idx = idx;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            ans.push_back(res_idx);
        }
        return ans;

        
    }
};