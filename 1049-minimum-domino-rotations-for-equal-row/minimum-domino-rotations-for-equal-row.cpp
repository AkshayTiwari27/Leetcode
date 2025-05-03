class Solution {
private:
    int check(int target, const vector<int>& tops, const vector<int>& bottoms) {
        int n = tops.size();
        int rotations_to_make_top_target = 0;
        int rotations_to_make_bottom_target = 0;

        for (int i = 0; i < n; ++i) {
            if (tops[i] != target && bottoms[i] != target) {
                return numeric_limits<int>::max();
            } else if (tops[i] != target) {
                rotations_to_make_top_target++;
            } else if (bottoms[i] != target) {
                rotations_to_make_bottom_target++;
            }
        }

        return min(rotations_to_make_top_target, rotations_to_make_bottom_target);
    }

public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        if (n == 0) return -1;

        int rotations1 = check(tops[0], tops, bottoms);
        if (tops[0] != bottoms[0]) {
            int rotations2 = check(bottoms[0], tops, bottoms);
            rotations1 = min(rotations1, rotations2);
        }

        return (rotations1 == numeric_limits<int>::max()) ? -1 : rotations1;
    }
};
