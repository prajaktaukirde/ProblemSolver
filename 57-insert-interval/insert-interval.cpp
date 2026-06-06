class Solution {
public:
    vector<vector<int>> mergeintervals(vector<vector<int>> &res){
        vector<vector<int>>newres;

        int start1 = res[0][0];
        int end1 = res[0][1];

        for(int i=1;i<res.size();i++){
            int start2 = res[i][0];
            int end2 = res[i][1];

            if(start2 <= end1){
                start1 = start1;
                end1 = max(end1,end2);
                continue;
            }
            newres.push_back({start1,end1});

            start1 = start2;
            end1 = end2;
        }
        newres.push_back({start1,end1});
        return newres;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>res;
        int n = intervals.size();
        int insert = false;

        for(int i=0;i<n;i++){
            if(intervals[i][0] >= newInterval[0] && insert == false){
                res.push_back(newInterval);
                insert = true;
            }
            res.push_back(intervals[i]);
        }
        if(!insert){
            res.push_back(newInterval);
        }

        // sort(res.begin(), res.end());

        vector<vector<int>>newres = mergeintervals(res);
        return newres;
    }
};