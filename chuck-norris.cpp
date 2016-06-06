#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    string MESSAGE;
    getline(cin, MESSAGE);
    string binaryMessage;
    binaryMessage.resize(MESSAGE.size() * 7);
    for (auto i : MESSAGE)
    {
      binaryMessage.append( bitset<7>(i).to_string()) ;
    }
    
    for(auto bit : binaryMessage)
    {
        
    }
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << binaryMessage << endl;
}