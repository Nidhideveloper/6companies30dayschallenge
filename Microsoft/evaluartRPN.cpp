//using recurrsion -0(N) and stack space of O(N)
//while using array as stack O(N) & O(1)

/*class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        string curr=tokens.back();
        tokens.pop_back();
       if(curr!="+" && curr!="-" && curr!="*" && curr!="/") return stoi(curr);
       else{
           long b=evalRPN(tokens);
           long a=evalRPN(tokens);
           if(curr=="+") return a+b;
           else if(curr=="-") return a-b;
           else if(curr=="*") return a*b;
           else return a/b;
       }
    }
};*/


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int tp=0;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                int a=stoi(tokens[--tp]);
                int b=stoi(tokens[--tp]);
                if(tokens[i]=="+") a=a+b;
                else if(tokens[i]=="-") a=b-a;
                else if(tokens[i]=="*") a=a*b;
                else if(tokens[i]=="/") a=b/a;
                tokens[tp++]=to_string(a);
            }
            else tokens[tp++]=tokens[i];
        }
        return stoi(tokens[0]);
    }
};