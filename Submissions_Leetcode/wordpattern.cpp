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
        map<char,int> mapP;
        map<string,int> mapS;
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
        for(int i=0;i<sizeP;i++)
        {
            if(i==sizeP || mapP[pattern[i]]!=mapS[vectorS[i]]) return false;
            mapP[pattern[i]]=mapS[vectorS[i]]=i+1;
        }
    return sizeP==vectorS.size();
    }
};

int main()
{
    Solution test;
    cout<<test.wordPattern("abab","cat dog cat dog");
    cout<<test.wordPattern("abba","dog cat cat dog"); //failed
}