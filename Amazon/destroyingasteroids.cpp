class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long mx = mass;
        sort(asteroids.begin(),asteroids.end());
        for(auto i: asteroids)
        {
            if(i<=mx)
                mx += i;
            else
                return 0; 
        }
        return 1;
    }
};