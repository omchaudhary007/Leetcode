// problem link:- https://leetcode.com/problems/fruit-into-baskets/description/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int IndOne = -1, IndTwo = -1;
        int start = 0, maxCount = 0;
        
        for (int i = 0; i < fruits.size(); i++) {
            if (IndOne == -1 || fruits[IndOne] == fruits[i])
                IndOne = i;
            else if (IndTwo == -1 || fruits[IndTwo] == fruits[i])
                IndTwo = i;
            else {
                (IndOne < IndTwo) ? (start = IndOne + 1, IndOne = i)
                                  : (start = IndTwo + 1, IndTwo = i);
            }
            maxCount = max(maxCount, i - start + 1);
        }
        
        return maxCount;
    }
};
