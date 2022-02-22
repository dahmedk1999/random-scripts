#include <string>
using std::string;
//base 26
// A B C String 'A'=65
// 0 1 2 Index
//     3 Size
//[0]*26**2+[1]*26**1+[2]*26**0
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sum=0;
        int length=columnTitle.length();
        for(int i=0;i<length;i++)
            sum+=pow(26,length-i-1) * (columnTitle[i]-'A'+1); 
        return sum;
    }
};