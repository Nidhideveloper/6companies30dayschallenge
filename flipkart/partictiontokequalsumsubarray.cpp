public:
    bool canPartitionKSubsets(vector<int>& a, int k) {
        int s = 0;
        s = accumulate(a.begin(), a.end(), s);
        if (a.size() < k || s % k) return 0;
        
        vector<int>visited(a.size(), 0);
        return backtrack(a, visited, s / k, 0, 0, k);
    }
    
    bool backtrack(vector<int>& nums,vector<int>visited, int target, int curr_sum, int i, int k) {
        if (k == 1) 
            return true;
        
        if (curr_sum == target) 
            return backtrack(nums, visited, target, 0, 0, k-1);
        
        for (int j = i; j < nums.size(); j++) {
            if (visited[j] || curr_sum + nums[j] > target) continue;
            
            visited[j] = 1;
            if (backtrack(nums, visited, target, curr_sum + nums[j], j+1, k)) return 1;
            visited[j] = 0;
        }
        
        return 0;
    }
};