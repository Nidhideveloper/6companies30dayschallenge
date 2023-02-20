class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> st{bank.begin(),bank.end()};
        if(!st.count(end)) return -1;
        queue<string> q;
        q.push(start);
        int c=0,s;
        string cur,t;
        while(!q.empty())
        {
            s=q.size();
            while(s--)
            {
                cur=q.front();
                q.pop();
                if(cur==end) return c;
                st.erase(cur);
            
                for(int i=0;i<8;i++)
                {
                    string t=cur;
                    t[i]='A';
                    if(st.count(t)!=0)
                        q.push(t);
                    t[i]='C';
                    if(st.count(t)!=0)
                        q.push(t);
                    t[i]='G';
                    if(st.count(t)!=0)
                        q.push(t);
                    t[i]='T';
                    if(st.count(t)!=0)
                        q.push(t);
                }
            
            }
            c++;
        }
        return -1;
    }
};