class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>result(n,0);

        vector<bool>a(n+1,false),b(n+1,false);

        for(int i=0;i<n;i++){
            a[A[i]]=true;
            b[B[i]]=true;
            int count=0;
            for(int j=1;j<n+1;j++){
                if(a[j]==true && b[j]==true) count++;
            }
            result[i]=count;

        }
        return result;
    }
};