// Problem link:- https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/description/
/* 
 what we need:- We need minimum possible penelity so our goal is reduce all maximum value.
 
 why not priority queue:- 
  Logic:- We may thing that store all value in p.queue and divide maxOperations big numbers and then traverse p.queue to return maximum penelity.
   1. There is no clear logic to divide a big number. 
   for e.g:- arr=[12] and maxOperation=2 then we may thing divide 12=6,6 and then 6/2=3,3 but this way max penelity will be 6.
   but we can divide it as 8,4=> then 8/2=4,4 in this way max will be 4 only.
   another e.g:- arr=[14] and maxOperations=2 then 14=[7,7] and 7=4,3 and max is 7.
   but if 14=9,5 then 9=4,5 and max is 5 or even 14=10,4 will be 10=5,5 and max is 5.
   so we can see there is no clear logic to decide division and if we plan to run loop then t.c will be O(n*n) for n number we may go n/2 so it will be N^2.
*/
