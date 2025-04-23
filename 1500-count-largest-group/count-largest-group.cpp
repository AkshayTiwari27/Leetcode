class Solution {
public:
    int findSum(int n){
        int sum = 0;
        while(n){
            sum+= n%10;
            n/= 10;
        }

        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int,int>mp;

        int maxi = 0;
        int count = 0;
        for(int i = 1; i<= n; i++){
            int sum = findSum(i);
            mp[sum]++;
            if(mp[sum] == maxi){
                count++;
            }
            else if(maxi< mp[sum]){
                maxi = mp[sum];
                count = 1;
            }
        }

        return count;
    }
};