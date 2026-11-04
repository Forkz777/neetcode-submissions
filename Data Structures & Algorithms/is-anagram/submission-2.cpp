class Solution {
public:
    std::map<char, int> string1_map;
    std::map<char, int> string2_map;
    bool isAnagram(string s, string t) {
        for(char index : s){
            string1_map[index]++;
        }
        for(char index : t){
            string2_map[index]++;
        }
        if(string2_map != string1_map){
            return false;
        }

        return true;
    }
};
