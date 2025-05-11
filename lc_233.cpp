class Solution {
public:
    int dp[11][2][11]; 

    int count(string &s, int ind, int tight, int cnt) {   
        int sz = s.size();
        if (ind == sz) return cnt;
        if (dp[ind][tight][cnt] != -1) return dp[ind][tight][cnt];
        int limit = (tight == 1) ? (s[ind] - '0') : 9;
        int ans = 0;
        for (int i = 0; i <= limit; i++) {
            int newCnt = cnt + (i == 1);
            int newTight = tight & (i == s[ind] - '0');
            ans += count(s, ind + 1, newTight, newCnt);
        }
        return dp[ind][tight][cnt] = ans;
    }

    int countDigitOne(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return count(s, 0, 1, 0);
    }
};

