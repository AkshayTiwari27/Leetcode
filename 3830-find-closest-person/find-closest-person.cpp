class Solution {
public:
    int findClosest(int x, int y, int z) {
        int diffxz = abs(z - x);
        int diffyz = abs(z - y);
        if(diffxz < diffyz) return 1;
        else if(diffxz > diffyz) return 2;
        else return 0;
    }
};