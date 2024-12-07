// Problem link:- https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/description/
/* 
 what we need:- We need minimum possible penalty  so our goal is reduce all maximum value.
 
 why not priority queue:- 
  Logic:- We may think that store all value in p.queue and divide maxOperations of big numbers and then traverse p.queue to return maximum penalty.
   But there is no clear logic to divide a big number. 
   for e.g:- arr=[12] and maxOperation=2 then we may think divide 12=6,6 and then 6/2=3,3 but this way max penalty  will be 6.
   but we can divide it as 8,4=> then 8/2=4,4 in this way max will be 4 only.
   another e.g:- arr=[14] and maxOperations=2 then 14=[7,7] and 7=4,3 and max is 7.
   but if 14=9,5 then 9=4,5 and max is 5 or even 14=10,4 will be 10=5,5 and max is 5.
   so we can see there is no clear logic to decide division and if we plan to run loop then t.c will be O(N*N) for n number we may go n/2 so it will be N^2. and here N can be 10^9 also.
*/
/* optimize solution using binary search:-
 1. Here our panalty can be 1 to max(arr) so we will use binary search to find possible penalty.
 2. N can be our penalty if all the value is either<= N or can be <=N by performing maxOperations.
 3. If arr[i]>penelty it means we need to reduce it so :-
  a. If arr[i]%penelty=0 means there will be (arr[i]/penelty)-1 operation to do so.
    e.g:- arr[i]=12 and penalty=4 then 12=>8,4=>4,4,4 so here we need 2 operations so (12/4)-1=3-1=3.
  b. If arr[i]%penelty!=0 means we cannot divide equally so (arr[i]/penalty) operation is required.
  e.g:- if arr[i]=9 and penalty=4 then 9=>5,4=>3,2,4 so 9/4=2.
  In this approch we don't need to worry about how i should divide a number because we are just getting count for penalty.
*/
class Solution {
public:
    bool isPossible(vector<int>&nums,int penalty,int maxOperations){
        for(int i=0;i<nums.size();i++){
          if(nums[i]>penalty){
             if(nums[i]%penalty==0){
                maxOperations-=nums[i]/penalty-1;
             }
             else
             maxOperations-=nums[i]/penalty;
          }
          if(maxOperations<0) return false;
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
      int s=1;
      int e=*max_element(nums.begin(),nums.end()); 
      int ans=e;
      while(s<=e){
        int penalty=s+(e-s)/2;
        if(isPossible(nums,penalty,maxOperations)){
            ans=penalty;
            e=penalty-1;
        }
        else
        s=penalty+1;
      }
      return ans;
    }
};
