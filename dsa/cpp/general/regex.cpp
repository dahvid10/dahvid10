#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    string s1 = "Regex Tutorial";
    string s2 = "Regex 101";
    regex pattern("^[A-Z].*");
    if (regex_match(s2, pattern)) {
        cout << true;
    } else {
        cout << false;
    }
    return 0;
}