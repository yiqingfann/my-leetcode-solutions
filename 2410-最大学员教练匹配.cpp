class Solution {
  public:
    int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int n = players.size(), m = trainers.size();
        int ans = 0;
        for (int i = 0, j = 0; i < n && j < m; ++i, ++j) {
            while (j < m && trainers[j] < players[i]) ++j;
            if (j < m) ans++;
        }
        return ans;
    }
};