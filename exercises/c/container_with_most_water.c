#include <stdio.h>

int maxArea(int* height, int heightSize) {
    int l = 0, r = heightSize - 1;
    int ans = 0;
    while (l < r) {
        int area = (height[l] < height[r] ? height[l] : height[r]) * (r - l);
        if (area > ans) {
            ans = area;
        }
        if (height[l] <= height[r]) {
            ++l;
        } else {
            --r;
        }
    }
    return ans;
}
