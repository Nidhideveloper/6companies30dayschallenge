class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans="";
        /*double n=(double)numerator;
        double d=(double)denominator;
        double a=n/d;
        return to_string(a);
        */
        if(!numerator) return "0";
        if (numerator > 0 ^ denominator > 0) ans += '-';
        long num = labs(numerator), den = labs(denominator);
        long q = num / den;
        long r = num % den;
        ans += to_string(q);
        if(r==0) return ans;
        else{
            ans+='.';
            unordered_map<long, int> mpp;
            while(r != 0){
                if(mpp.find(r) != mpp.end()){
                    int i = mpp[r];
                    ans.insert(i, "(");
                    ans += ')';
                    break;
                }
                else{
                    mpp[r] = ans.length();
                    r *= 10;
                    q = r / den;
                    r = r % den;
                    ans += to_string(q);
                }
            }
        }
        return ans;
    }
};