class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int left = (m + n + 1) / 2;  // middle for odd, first middle for even
        int right = (m + n + 2) / 2; // second middle for even

        // get the median by finding k-th elements
        return (getKth(nums1, 0, nums2, 0, left) + getKth(nums1, 0, nums2, 0, right)) / 2.0;
    }

    // int getKth(vector<int>& a, vector<int>& b, int k) {
    //     int aStart = 0, bStart = 0;

    //     while (true) {
    //         // base cases
    //         if (aStart >= a.size()) return b[bStart + k - 1];
    //         if (bStart >= b.size()) return a[aStart + k - 1];
    //         if (k == 1) return min(a[aStart], b[bStart]);

    //         // take k/2-th element in each array (or last if not enough elements)
    //         int aMidIndex = min((int)a.size() - aStart, k / 2);
    //         int bMidIndex = min((int)b.size() - bStart, k / 2);

    //         int aMidValue = a[aStart + aMidIndex - 1];
    //         int bMidValue = b[bStart + bMidIndex - 1];

    //         if (aMidValue <= bMidValue) {
    //             // discard first aMidIndex elements of a
    //             aStart += aMidIndex;
    //             k -= aMidIndex;
    //         } else {
    //             // discard first bMidIndex elements of b
    //             bStart += bMidIndex;
    //             k -= bMidIndex;
    //         }
    //     }
    // }

    int getKth(vector<int>& a, int aStart, vector<int>& b, int bStart, int k) {
        // Base cases
        if (aStart >= a.size()) return b[bStart + k - 1];
        if (bStart >= b.size()) return a[aStart + k - 1];
        if (k == 1) return min(a[aStart], b[bStart]);

        // Take k/2-th element in each array (or last if not enough elements)
        int aMidIndex = min((int)a.size() - aStart, k / 2);
        int bMidIndex = min((int)b.size() - bStart, k / 2);

        int aMidValue = a[aStart + aMidIndex - 1];
        int bMidValue = b[bStart + bMidIndex - 1];

        if (aMidValue <= bMidValue) {
            // Discard first aMidIndex elements of a
            return getKth(a, aStart + aMidIndex, b, bStart, k - aMidIndex);
        } else {
            // Discard first bMidIndex elements of b
            return getKth(a, aStart, b, bStart + bMidIndex, k - bMidIndex);
        }
    }
};