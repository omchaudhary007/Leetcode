// Link:- https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/description/
/*
Logic:- 
1. If any arr[i]>k then return -1 because we can decrease a value but can't increase.
2. Put all value in set because firstMax(arr) h element will be secondUniqueMax(arr).
3. maxOperation will be set.Size() but if we have K then it will be set.size()-1.

*/

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
      unordered_set<int>st;  
      for(int i=0;i<nums.size();i++){
        if(nums[i]<k) return -1;
        st.insert(nums[i]);
      }
      int maxOperation=st.size();
      if(st.count(k)) maxOperation--;
      return maxOperation;
    }
};
