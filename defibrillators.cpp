#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Defribilator
{
    public:
        Defribilator(std::string _name, std::string _long, std::string _lat)
        {
            name = _name;
            //change the content of param from outside (security issue)
            // but never mind here :)
            std::size_t found = _long.find(",");
            _long[found] = '.';
            found = _lat.find(",");
            _lat[found] = '.';

            longitude = ::atof(_long.c_str());
            latitude = ::atof(_lat.c_str());
        }

        const std::string& getName() const
        {
            return name;
        }

        double getLong() const
        {
            return longitude;
        }

        double getLat() const
        {
            return latitude;
        }
    private:
        std::string name;
        double longitude;
        double latitude;
};

//change the value of the parameter
std::vector<std::string> getSplittedLine(std::string line)
{
    for (int i=0; i<line.length(); i++)
    {
        if (line[i] == ';')
        {
            str[i] = ' ';
        }
    }
    std::vector<std::string> array = std::std::vector<std::string>();
    stringstream ss(line);
    std:string temp;
    while (ss >> temp) {
        array.push_back(temp);
    }
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    string LON;
    cin >> LON; cin.ignore();
    string LAT;
    cin >> LAT; cin.ignore();
    int N;
    cin >> N; cin.ignore();
    std::vector<Defribilator> defibrillators = std::vector<Defribilator>();
    for (int i = 0; i < N; i++) {
        string DEFIB;
        getline(cin, DEFIB);
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << "answer" << endl;
}