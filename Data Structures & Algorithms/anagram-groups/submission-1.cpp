class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // for (string str: strs){
        //     sort(str.begin(),str.end());
        // }
        // unordered_map<vector<int>,vector<string>> mp;
        // unordered_map<string,vector<string>> mp;
        // for (string str: strs){
        //     vector<int> count (26,0);
        //     for (char c: str){
        //         count[c-'a']++;
        //     }
        //     string key = to_string(count[0]);
        //     for (int i = 1; i < 26; ++i) {
        //         key += ',' + to_string(count[i]);
        //     }
        //     mp[key].push_back(str);
        // }
        // vector<vector<string>> ans;
        // for (auto& p : mp) {
        //     ans.push_back(p.second);
        // }
        // return ans;

        unordered_map<string, vector<string>> mp;
        for (string str: strs){
            vector <int> count (26,0);
            for (char c: str){
                count[c-'a']++;
            }
            string key = to_string(count[0]);
            for (int i = 1; i < 26; i++){
                key += ',' + to_string(count[i]);
            }
            mp[key].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto& p : mp) {
            ans.push_back(p.second);
        }
        return ans;
    }
};
