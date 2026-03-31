class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size()-1;
        int maxArea = 0;

        while (l < r){
            int height = min(heights[l],heights[r]);
            int length = r - l;
            int tempArea = length * height;
            maxArea = max(maxArea,tempArea);
            if (heights[l] < heights[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxArea;
    }
};
