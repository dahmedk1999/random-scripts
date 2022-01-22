#include <vector>
#include <math.h>
#include <iostream>
using std::cout;
using std::vector;
/* Runtime: 44 ms, faster than 67.45% of C++ online submissions for Stone Game IV.
Memory Usage: 6.4 MB, less than 61.74% of C++ online submissions for Stone Game IV. 
Alice and Bob take turns playing a game, with Alice starting first.

Initially, there are n stones in a pile. On each player's turn, that player makes a move consisting of removing any non-zero square number of stones in the pile.

Also, if a player cannot make a move, he/she loses the game.

Given a positive integer n, return true if and only if Alice wins the game otherwise return false, assuming both players play optimally.

 

Example 1:

Input: n = 1
Output: true
Explanation: Alice can remove 1 stone winning the game because Bob doesn't have any moves.
Example 2:

Input: n = 2
Output: false
Explanation: Alice can only remove 1 stone, after that Bob removes the last one winning the game (2 -> 1 -> 0).
Example 3:

Input: n = 4
Output: true
Explanation: n is already a perfect square, Alice can win with one move, removing 4 stones (4 -> 0).
 

Constraints:

1 <= n <= 105
*/

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> a(n+1,0);
        // bool *a= new bool[n];
        for(int i=0;i<n;i++)
            a[i]=false;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sqrt(i);j++)
                if(a[i-j*j]==false)
                {
                    a[i]=true;
                    break;
                }
        }
        // bool ret= a[n];
        // delete[] a;
        // return ret;
        return a[n];
    }
};

int main()
{
    Solution Test;
    for (int i=1;i<99999;i++)
        cout<<Test.winnerSquareGame(i);    
}