class GenerateParentheses {
private:
    void backtrack(vector<string>& result, string current, 
                   int open, int close, int n) {
        // Base case: valid combination complete
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }
        
        // Add opening bracket if we haven't used all
        if (open < n) {
            backtrack(result, current + "(", open + 1, close, n);
        }
        
        // Add closing bracket if it won't make invalid
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, n);
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};
