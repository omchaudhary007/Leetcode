# 1422. Maximum Score After Splitting a String

**Problem:-** Given a string `s` of zeros and ones, *return the maximum score after splitting the string into two **non-empty** substrings* (i.e. **left** substring and **right** substring).

**Using prefix sum:-**

1. For each index (0,index) zero count and from (index+1,N) one count.
2. To get 1 count of right we will count prefix count of 1.
3. For each index if it is 1 reduce 1 count if 0 increase zero count and find maxi using left+ right.

**Time complexity=O(n) space complexity=O(1)**

**Code:-** 

```cpp
class Solution {
public:
    int maxScore(string s) {
       int left=0,right=0,maxi=0; 
       for(int i=0;i<s.size();i++){
         if(s[i]=='1') right++;
       }
       for(int i=0;i<s.size()-1;i++){
        if(s[i]=='0') left++;
        else right--;
        maxi=max(maxi,left+right);
       }
       return maxi;
    }
};
```
