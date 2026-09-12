class Solution {
public:

    struct State {
        long long score = 0;
        vector<int> indexes;
        bool done = false;
    };

    State shortt(const State& take, const State& skip) {

        if(take.indexes < skip.indexes)
            return take;

        return skip;
    }

    int findIndex(int start, int end, int prevBound,
                  vector<vector<int>>& intervals) {

        int save = -1;

        while(start <= end) {

            int mid = start + (end - start) / 2;

            if(intervals[mid][0] > prevBound) {
                save = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return save;
    }

    State solve(int ind,
                int count,
                vector<vector<int>>& intervals,
                vector<vector<State>>& memo,
                vector<int>& nxt) {

        if(ind >= intervals.size() || count == 4)
            return {0, {}};

        if(memo[ind][count].done)
            return memo[ind][count];

        // Skip
        State skip = solve(
            ind + 1,
            count,
            intervals,
            memo,
            nxt
        );

        // Take
        int nextInd = nxt[ind];

        State take = solve(
            nextInd == -1 ? intervals.size() : nextInd,
            count + 1,
            intervals,
            memo,
            nxt
        );

        take.score += intervals[ind][2];

        // Keep indices sorted
        take.indexes.push_back(intervals[ind][3]);
        sort(take.indexes.begin(), take.indexes.end());

        State result;

        if(take.score > skip.score)
            result = take;
        else if(skip.score > take.score)
            result = skip;
        else
            result = shortt(take, skip);

        result.done = true;

        return memo[ind][count] = result;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        for(int i = 0; i < n; i++)
            intervals[i].push_back(i);

        sort(intervals.begin(), intervals.end());

        // Precompute next compatible interval
        vector<int> nxt(n);

        for(int i = 0; i < n; i++) {
            nxt[i] = findIndex(
                i + 1,
                n - 1,
                intervals[i][1],
                intervals
            );
        }

        vector<vector<State>> memo(
            n,
            vector<State>(5)
        );

        State ans = solve(
            0,
            0,
            intervals,
            memo,
            nxt
        );

        return ans.indexes;
    }
};