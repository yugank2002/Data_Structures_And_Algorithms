class Solution {
public:
    pair<int, int> getStr(int size1, int ind1, int size2, int ind2, string& s) {
        string str1 = s.substr(ind1, size1);
        string str2 = s.substr(ind2, size2);
        if (str1 < str2) {
            return {size1, ind1};
        }
        return {size2, ind2};
    }
    string shortestBeautifulSubstring(string s, int k) {

        vector<int> track;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '1') {
                track.push_back(i);
            }
        }
        if (track.size() < k)
            return "";

        int first = 0;
        int second = k - 1;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        while (second < track.size()) {
            int size = track[first] - track[second] + 1;
            int ind = track[second];
            pq.push({size, ind});
            second++;
            first++;
        }

        auto [size1, ind1] = pq.top();
        pq.pop();
        while (!pq.empty() && size1 == pq.top().first) {
            auto [si, i] =
                getStr(size1, ind1, pq.top().first, pq.top().second, s);
            size1 = si;
            ind1 = i;
            pq.pop();
        }

        return s.substr(ind1, size1);
    }
};