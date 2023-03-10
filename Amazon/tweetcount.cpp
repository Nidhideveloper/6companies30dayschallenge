class TweetCounts {
unordered_map<string,map<int,int>> mpp;
public:
    TweetCounts() {  
    }
    
    void recordTweet(string tweetName, int time) {
        mpp[tweetName][time]++;
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int interval = freq[0] == 'm' ? 60 : (freq[0] == 'h' ? 60*60 : 60*60*24);
        vector<int> ans((endTime-startTime)/interval + 1,0);
        const auto &end = mpp[tweetName].upper_bound(endTime);
        for(auto it = mpp[tweetName].lower_bound(startTime);it != end;it++){
            ans[(it->first-startTime)/interval] += it->second;
        }
        return ans;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */