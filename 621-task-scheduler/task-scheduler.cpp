class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26, 0);

        for (char ch : tasks)
            freq[ch - 'A']++;

        priority_queue<int> pq;

        for (int x : freq)
            if (x > 0)
                pq.push(x);

        int time = 0;

        while (!pq.empty()) {

            vector<int> temp;
            int k = n + 1;

            while (k > 0 && !pq.empty()) {

                int x = pq.top();
                pq.pop();

                x--;

                if (x > 0)
                    temp.push_back(x);

                time++;
                k--;
            }

            for (int x : temp)
                pq.push(x);

            if (pq.empty())
                break;

            time += k;
        }

        return time;
    }
};