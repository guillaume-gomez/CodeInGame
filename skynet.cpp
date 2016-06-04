#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

std::string manageMoto(int road, int gap, int platform, int speed, int coordX) {
    if (gap > speed) {
        return "SPEED";
    }
    if (coordX + speed > (road - coordX) + gap ) {
        return "JUMP"
    }
    return "WAIT";
}

void move(int coordX, int speed) {
    return coordX + speed;
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int road; // the length of the road before the gap.
    cin >> road; cin.ignore();
    int gap; // the length of the gap.
    cin >> gap; cin.ignore();
    int platform; // the length of the landing platform.
    cin >> platform; cin.ignore();

    // game loop
    while (1) {
        int speed; // the motorbike's speed.
        cin >> speed; cin.ignore();
        int coordX; // the position on the road of the motorbike.
        cin >> coordX; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        coordX = move(coordX, speed);
        // A single line containing one of 4 keywords: SPEED, SLOW, JUMP, WAIT.
        cout << "SPEED" << endl;
    }
}