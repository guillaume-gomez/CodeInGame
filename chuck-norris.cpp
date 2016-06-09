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
    int consecutiveBit = 0;
    char previousBit = binaryMessage.front();
    for(auto bit : binaryMessage)
    {
        if( bit != previousBit)
        {
            if( bit == '1')
            {
                std::cout << "00 ";
            }
            else
            {
                std::cout << "0 ";
            }
            std::cout << std::string(consecutiveBit, '0');
            previousBit = bit;
            consecutiveBit = 0;
        }
        else
        {
            consecutiveBit++;
        }
    }
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << binaryMessage << endl;
}