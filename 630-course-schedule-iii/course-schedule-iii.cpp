class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {

        vector<pair<int,int>> arr;

        // lastdy, duration
        for (int i = 0; i < courses.size(); i++) {
            arr.push_back({courses[i][1], courses[i][0]});
        }

        sort(arr.begin(), arr.end());

        priority_queue<int> pq;

        int time = 0;

        for (int i = 0; i < arr.size(); i++) {

            time += arr[i].second;
            pq.push(arr[i].second);

            if (time > arr[i].first) {
                time -= pq.top();
                pq.pop();
            }
        }

        return pq.size();
    }
};