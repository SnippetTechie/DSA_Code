class Permutations {
private:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, 
                   vector<int>& current, vector<bool>& used) {
        // Base case: permutation is complete
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        
        // Try adding each unused number
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            
            // Choose
            current.push_back(nums[i]);
            used[i] = true;
            
            // Explore
            backtrack(nums, result, current, used);
            
            // Unchoose (backtrack)
            current.pop_back();
            used[i] = false;
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        
        backtrack(nums, result, current, used);
        return result;
    }
};
