class Solution {
public:
    string predictPartyVictory(string senate) {
        int cnt = 0, n = 0;
        while (senate.size() != n) {
            string s="";
            n = senate.size();
            for (int i = 0; i < n; i++) {
                if (senate[i] == 'R') {
                    if (cnt++ >= 0) s += 'R';
                }
                else if (senate[i] == 'D') {
                    if (cnt-- <= 0) s += 'D';
                }
            }  
            swap(s, senate);
        }
        if (senate[0] == 'R') 
            return "Radiant";
        else 
            return "Dire";
    }
};