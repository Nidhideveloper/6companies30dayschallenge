class Solution {
public:
    int count=0;
    void helper(set<string>&m,string s,string ds){
        if(s.empty())
        {   int len=m.size();
            count=max(count,len);
            return;
        }
        
        for(int i=0;i<s.length();i++){
           ds=s.substr(0,i+1);
            if(m.find(ds)==m.end()){
                m.insert(ds);
                helper(m,s.substr(i+1),ds);
                m.erase(ds);
            }
        }
        return ;
    }
    int maxUniqueSplit(string s) {
        set<string>m;
        helper(m,s,"");
        return count;
    }
    
};