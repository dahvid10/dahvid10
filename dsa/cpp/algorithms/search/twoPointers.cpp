#include <iostream>
#include <string>

using namespace std;

int main()
{
    string txt = "tenet";
    int f, l;
    bool palindrome = true;
    f = 0;
    l = txt.size() - 1;
    while (l > f)
    {
        if (txt[f] != txt[l])
        {
            palindrome = false;
            break;
        }
        l--;
        f++;
    }
    cout << palindrome;

    return 0;
}