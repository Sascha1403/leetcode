#include <iostream>
#include <map>

class Solution;

class Solution {
public:
    int romanToInt(std::string s) {

        std::map<char, char> my_map = {
                { 'A', '1' },
                { 'B', '2' },
                { 'C', '3' }
        };
        std::map<std::string, int> roman_map = {
                {"I", 1},
                {"V", 5},
                {"X", 10},
                {"L", 50},
                {"C", 100},
                {"D", 500},
                {"M", 1000},
                {"IV", 4},
                {"IX", 9},
                {"XL", 40},
                {"XC", 90},
                {"CD", 400},
                {"CM", 900}
        };
        int i = 0;
        int sizeS = s.size();
        int result = 0;
        // Über alle Elemente iterieren mit flexibel i
        while (i < sizeS) {
            std::string oneElement;
            std::string twoElement;

            oneElement = s[i];
            twoElement = std::string(1,s[i]) + s[i+1];
            // Wenn kein Spezialfall
            if (roman_map.find(twoElement) == roman_map.end()){
                result += roman_map.at(oneElement);
                i++;
            }
            else {
                result += roman_map.at(twoElement);
                i = i+2;
            }
        }
        return result;

    }
};

int main() {
    std::string s = "MCMXCIV";
    int result;
    class Solution solution;
    result = solution.romanToInt(s);
    return 0;
}
