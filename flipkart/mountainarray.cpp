/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int t, MountainArray& arr) {
        auto l = 0, r = arr.length() - 1;
        while (l < r) {
            int mid = l+(r-l)/2;
            if (arr.get(mid) > arr.get(mid + 1)) r = mid;
            else l = mid + 1;
        }
        auto i = bSearch(arr, t, 0, l);
        return i != -1 ? i : bSearch(arr, t, l + 1, arr.length() - 1, false);
    }
    int bSearch(MountainArray& arr, int t, int l, int r, bool asc = true) {
        while (l <= r) {
            int m = (l + r) / 2;
            auto val = arr.get(m);
            if (val == t) return m;
            if (asc == val < t) l = m + 1;
            else r = m - 1;
        }
        return -1;
    }
};