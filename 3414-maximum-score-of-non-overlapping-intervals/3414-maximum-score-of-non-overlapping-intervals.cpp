class Solution {
public:
    struct Node
    {
        long long score = -1;
        vector<int> indexes;
    };
    
    int n;
    vector<int> nextidx;
    vector<vector<Node>> t;
    
    int findNext(vector<vector<int>>& intervals,int r)
    {
        int l = 0, h = n - 1;
        int result = n;
        while(l <= h)
        {
            int mid = l + (h - l) / 2;
            if(intervals[mid][0] > r)
            {
                result = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return result;
    }

    Node solve(int i,int k,vector<vector<int>>& intervals)
    {
        if(k == 0 || i >= n )
        {
            Node baseNode;
            baseNode.score = 0; 
            return baseNode;
        }
        if(t[i][k].score != -1)
        {
            return t[i][k];
        }
        
        long long weight = intervals[i][2]; 
        int idx = intervals[i][3];
        int j = nextidx[i];
        
        // Skip
        Node skip = solve(i+1,k,intervals);
        
        // Take
        Node temp = solve(j,k-1,intervals); 
        Node take;
        take.score = temp.score + weight;
        take.indexes = temp.indexes;
        take.indexes.push_back(idx);
        sort(take.indexes.begin(),take.indexes.end());

        Node result;
        if(skip.score > take.score)
        {
            result = skip;
        }
        else if(take.score > skip.score)
        {
            result = take;
        }
        else
        {
            result = take.indexes > skip.indexes ? skip : take;
        }
        return t[i][k] = result;
    }
    
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();
        nextidx.resize(n);
        int k = 4;
        t.assign(n+1,vector<Node>(k+1));
        
        for(int i = 0;i<n;i++)
        {
            intervals[i].push_back(i);
        }
        
        sort(intervals.begin(),intervals.end());
        
        for(int i = 0;i<n;i++)
        {
            int end = intervals[i][1];
            nextidx[i] = findNext(intervals,end);
        }
        
        auto result = solve(0,4,intervals);
        return result.indexes;
    }
};