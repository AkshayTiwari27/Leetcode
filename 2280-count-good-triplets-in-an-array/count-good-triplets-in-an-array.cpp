class FenwickTree {
private:
    vector<int> bit;
    int size;

public:
    FenwickTree(int n) {
        size = n;
        bit.resize(n + 1, 0);
    }

    void update(int idx, int delta) {
        idx++; 
        while (idx <= size) {
            bit[idx] += delta;
            idx += idx & (-idx);
        }
    }

    int query(int idx) {
        idx++; 
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }
};


class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        if (n < 3) {
            return 0;
        }

        vector<int> pos2(n);
        for (int i = 0; i < n; ++i) {
            pos2[nums2[i]] = i;
        }

        FenwickTree bit(n);

        long long good_triplets_count = 0;

        for (int j = 0; j < n; ++j) {
            int val_y = nums1[j];
            int p2_y = pos2[val_y];

            int count_left = bit.query(p2_y - 1);

            
            int count_greater_left = j - count_left;
            int total_greater_than_p2_y = (n - 1) - p2_y;
            int count_right = total_greater_than_p2_y - count_greater_left;

            if (count_left > 0 && count_right > 0) {
                 good_triplets_count += (long long)count_left * count_right;
            }

            bit.update(p2_y, 1);
        }

        return good_triplets_count;
    }
};