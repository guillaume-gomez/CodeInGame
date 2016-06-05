#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

std::string toUppercase(std::string s)
{
    std::string uppercaseString;
    uppercaseString.resize(s.size());
    std::transform(s.begin(), s.end(), uppercaseString.begin(), std::ptr_fun<int, int>(std::toupper));
    return uppercaseString;
} 

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int L;
    cin >> L; cin.ignore();
    int H;
    cin >> H; cin.ignore();
    string T;
    getline(cin, T);
    auto acsciiLetters = std::vector< std::string >();
    for (auto i = 0; i < H; ++i) {
        string ROW;
        getline(cin, ROW);
        acsciiLetters.push_back(ROW);
    }
    std::string uppercaseS = toUppercase(T);
    for( auto y = 0; y < acsciiLetters.size(); ++y)
    {
        for(const char &it : uppercaseS)
        {
            int indexLetter = (it - 'A');
            if( indexLetter < 0 || indexLetter > 26)
            {
                indexLetter = 26;
            }
            int offsetLetter = indexLetter * L;
            for( auto x = offsetLetter; x < offsetLetter + L; ++x )
            { 
                cout << acsciiLetters[y][x];
            }
        }
        cout << endl;
    }
}