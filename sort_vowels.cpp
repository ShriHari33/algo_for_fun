#include "iostream"
#include "string"
#include "map"

// Problem Link: https://leetcode.com/problems/sort-vowels-in-a-string/description/
// My Submission: https://leetcode.com/submissions/detail/1097913018/


bool isvowel(char c)
{
    c = std::tolower(c);
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;

    return false;
}

std::string sortVowels(std::string s)
{
    std::map<char, int> vow_map{};

    for(size_t i = 0; i < s.length(); ++i)
    {
        if( isvowel(s[i]) )
            vow_map[s[i]] = vow_map[s[i]] + 1;
    }

    auto it = vow_map.begin();
    for(size_t i = 0; i < s.length(); ++i)
    {
        //lEetcOde
        if( isvowel(s[i]) )
        {
            if (it != vow_map.end())
            {
                if(it->second > 1)
                    s[i] = it->first, vow_map[s[i]]--;
                else if(it->second == 1)
                {
                    s[i] = it->first;
                    auto prev_it = it;

                    it = std::next(it);

                    vow_map.erase(prev_it);
                }
            }
        }
    }

    return s;
}


int main()
{
    std::string s = {"lEetcOde"};

    std::cout << sortVowels(s);
}