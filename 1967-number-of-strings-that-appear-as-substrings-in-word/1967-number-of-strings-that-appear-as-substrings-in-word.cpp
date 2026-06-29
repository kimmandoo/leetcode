class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int sum = 0;
        for(const auto& p: patterns){
            if(word.contains(p)) sum++;
        }
        return sum;
    }
};