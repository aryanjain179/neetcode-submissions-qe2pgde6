class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;                 // left and right pointers
        int leftMax = 0, rightMax = 0;      // max heights seen so far from each side
        int water = 0;                       // total trapped water

        while (l <= r) {
            if (height[l] < height[r]) {    // left is shorter → left limits water
                if (height[l] >= leftMax)
                    leftMax = height[l];    // update leftMax if current bar is taller
                else
                    water += leftMax - height[l]; // trap water above current bar
                l++;                        // move left pointer right
            } else {                        // right is shorter or equal → right limits water
                if (height[r] >= rightMax)
                    rightMax = height[r];   // update rightMax if current bar is taller
                else
                    water += rightMax - height[r]; // trap water above current bar
                r--;                        // move right pointer left
            }
        }

        return water;
    }
};
