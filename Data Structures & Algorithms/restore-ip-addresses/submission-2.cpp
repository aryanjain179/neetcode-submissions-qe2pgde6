class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.size() > 12) return res;

        // auto valid = [&](string& num) {
        //     if (num.size() > 1 && num[0] == '0') return false;
        //     int value = stoi(num);
        //     return value <= 255;
        // };

        for (int seg1 = 1; seg1 < 4; ++seg1) {
            for (int seg2 = 1; seg2 < 4; ++seg2) {
                for (int seg3 = 1; seg3 < 4; ++seg3) {
                    for (int seg4 = 1; seg4 < 4; ++seg4) {
                        if (seg1 + seg2 + seg3 + seg4 != s.size()) continue;

                        string num1 = s.substr(0, seg1);
                        string num2 = s.substr(seg1, seg2);
                        string num3 = s.substr(seg1 + seg2, seg3);
                        string num4 = s.substr(seg1 + seg2 + seg3);

                        if (valid(num1) && valid(num2) && valid(num3) && valid(num4)) {
                            res.push_back(num1 + "." + num2 + "." + num3 + "." + num4);
                        }
                    }
                }
            }
        }
        return res;
    }

    bool valid (string& num){
        if (num.size() > 1 && num[0] == '0') return false;
        int value = stoi(num);
        return value <= 255;
    }
};