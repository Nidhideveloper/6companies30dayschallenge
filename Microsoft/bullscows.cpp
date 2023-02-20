class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> mpp;
        int b=0, c=0;
        for(int i=0; i<secret.size(); i++){
            if(secret[i]==guess[i]) b++;
            else mpp[secret[i]]++;
        }
        for(int i=0; i<secret.size(); i++){
            if(secret[i]==guess[i]) continue;
            else if(mpp[guess[i]]){
                mpp[guess[i]]--;
                c++;
            }
        }
        string ans="";
        ans+=to_string(b);
        ans+="A";
        ans+=to_string(c);
        ans+="B";
        return ans;
    }
};