#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;
int romanCharValue(char r) {
    //yields the numeric value of the passed Roman numeral character.
    if (r == 'I') return 1;
    if (r == 'V') return 5;
    if (r == 'X') return 10;
    if (r == 'L') return 50;
    if (r == 'C') return 100;
    if (r == 'D') return 500;
    if (r == 'M') return 1000;

    return -1;
}
int convertRomanToInt(string s) {
    //this function converts the Roman number string into its 
    //equivalent integer value by implementing the following algorithm.
    int res = 0;
    for (int i = 0; i < s.length(); i++) {
        int s1 = romanCharValue(s[i]);
        if (i + 1 < s.length()) {
            int s2 = romanCharValue(s[i + 1]);
            if (s1 >= s2) {
                res = res +s1;
            }
            else {
                res = res + s2 - s1;
                i++;
            }

        }
        else {
            res = res + s1;
        }
    }
    return res;
}

int main () {
    string str;

    cout << "Enter a Roman number or Q to quit: ";
    cin >> str;
    if (str == "Q") return 0;
    cout << str << " = " << convertRomanToInt(str) << endl;
}
