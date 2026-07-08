class Solution {
public:
    struct cmp {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {
            if (a.first == b.first)
                return a.second < b.second;   
            return a.first > b.first;         
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> freq;

        for (string word : words)
            freq[word]++;

        priority_queue<pair<int, string>,
                       vector<pair<int, string>>,
                       cmp> pq;

        for (auto i : freq) {

            int frequency = i.second;
            string word = i.first;

            pair<int, string> curr = {frequency, word};

            if (pq.size() < k) {
                pq.push(curr);
            }
            else if (curr.first > pq.top().first ||
                    (curr.first == pq.top().first &&
                     curr.second < pq.top().second)) {

                pq.pop();
                pq.push(curr);
            }
        }

        vector<string> res;

        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};