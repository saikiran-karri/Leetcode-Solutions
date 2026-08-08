class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        int i = m + n - 1;

        // Compare elements from the end and place the larger one at index i
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[i] = nums1[p1];
                p1--;
            } else {
                nums1[i] = nums2[p2];
                p2--;
            }
            i--;
        }

        // If there are remaining elements in nums2, copy them over
        // (If nums1 has remaining elements, they are already in correct positions)
        while (p2 >= 0) {
            nums1[i] = nums2[p2];
            p2--;
            i--;
        }
    }
};