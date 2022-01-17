#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using std::cout;
using std::string;
using std::vector;
using std::map;
/*
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
 

Constraints:

1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.
*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string> m;
        vector<string> vectorS;
        int sizeP=pattern.length();
        int sizeS=s.length();
        string temp="";
        for (int i=0;i<sizeS;i++)
        {
            if(isalpha(s[i]))
            {
                temp+=s[i];
                if(i==sizeS-1)
                    vectorS.push_back(temp);
            }
            else if(s[i]==' ')
            {
                vectorS.push_back(temp);
                temp="";
            }
        }
        // check if # of chars == number of words
        if(sizeP!=vectorS.size())
            return false;
        else
            for(int i=1;i<pattern.length();i++)
            {
                if(m.find(pattern[i])!=m.end())
                    if(m.at(char(pattern[i]))!=vectorS[i])
                        return 0;
                m[pattern[i]]=vectorS[i];
            }
        for(int i=0;i<sizeP;i++)
            cout<<m.at(pattern[i]);
    return true;
    }
};

int main()
{
    Solution test;
    test.wordPattern("abab","cat dog cat dog");
    test.wordPattern("abba","dog cat cat fish"); //failed
}