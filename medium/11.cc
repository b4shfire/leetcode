// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int i=0, j=height.size()-1, max_area=0;
        
        while (i < j) {
            
            // calculate the area between height[i] and height[j]
            max_area = max(max_area, (j-i) * min(height[i], height[j]));
            
            // the shorter line is 'saturated', we cannot get a larger area from it
            // because any formed rectangle would have the same height but smaller width
            if (height[i] < height[j]) ++i;
            else --j;
        }
        
        return max_area;
    }
};
