class Solution {
public:
    void updateSegmentTree(int i, int l,int r,int idx,vector<long long>&segmentTree)
    {
        if(l == r)
        {
            segmentTree[i] = 1;
            return;
        }
        int mid = l + (r-l)/2;
        if(idx <= mid)
        {
            updateSegmentTree(2*i+1,l,mid,idx,segmentTree);

        }else{
            updateSegmentTree(2*i+2,mid+1,r,idx,segmentTree);

        }
        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
        return;

    }
    long long query(int qs,int qe,int i,int l,int r,vector<long long> &segmentTree)
    {
        if(r < qs || l>qe)
        {
            return 0;
        }
        if(l >= qs && r <= qe)
        {
            return segmentTree[i];
        }
        int mid = l + (r-l)/2;
        long long left = query(qs,qe,2*i+1,l,mid,segmentTree);
        long long right = query(qs,qe,2*i+2,mid+1,r,segmentTree);
        return left+right;

    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int,int> mp;
        for(int i = 0;i<n;i++)
        {
            mp[nums2[i]] = i;
        }

        // Segment Tree
        vector<long long> segmentTree(4*n);
        long long result  = 0;
        updateSegmentTree(0,0,n-1,mp[nums1[0]],segmentTree);

        for(int i = 1;i<n;i++){
            int idx = mp[nums1[i]];

            long long leftCommonCount = query(0,idx,0,0,n-1,segmentTree);
            long long leftNotCommon = i - leftCommonCount;
            long long elementsAfterIdxNum2 = n-1-idx;
            long long rightCommonCount = elementsAfterIdxNum2 - leftNotCommon;
            result +=    leftCommonCount * rightCommonCount;
            updateSegmentTree(0,0,n-1,idx,segmentTree);
        }
        return result;

        
    }
};