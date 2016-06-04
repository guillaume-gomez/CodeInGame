#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX_X = 39;
const int MAX_Y = 17;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/

std::string direction(int currentTX, int currentTY, int lightX, int lightY) {
    std::string xAxis = "";
    if( currentTX < lightX && (currentTX + 1) <= MAX_X) {
        xAxis =  "E";
    }
    else if ( currentTX > lightX && (currentTX - 1 ) >= 0) {
        xAxis = "W";
    }

    std::string yAxis = "";
    if( currentTY > lightY && ( currentTY - 1 ) >= 0 ) {
        yAxis = "N";
    }
    else if( currentTY < lightY && (currentTY + 1) <=  MAX_Y ) {
        yAxis = "S";
    }
    return yAxis + xAxis;
}

void moveThor(int &currentTX, int &currentTY, std::string direction) {
    if( direction == "N") {
        currentTY--;
        return;
    }
    if( direction == "S") {
        currentTY++;
        return;
    }
    if( direction == "E") {
        currentTX++;
        return;
    }
    if( direction == "W") {
        currentTX--;
        return;
    }
    if( direction == "NE") {
        currentTX++;
        currentTY--;
        return;
    }
    if( direction == "SE") {
        currentTX++;
        currentTY++;
        return;
    }
    if( direction == "NW") {
        currentTX--;
        currentTY--;
        return;
    }
    if( direction == "SW") {
        currentTX--;
        currentTY++;
        return;
    }
}


int main()
{
    int lightX; // the X position of the light of power
    int lightY; // the Y position of the light of power
    int initialTX; // Thor's starting X position
    int initialTY; // Thor's starting Y position
    cin >> lightX >> lightY >> initialTX >> initialTY; cin.ignore();

    // game loop
    while (1) {
        int remainingTurns; // The remaining amount of turns Thor can move. Do not remove this line.
        cin >> remainingTurns; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        std::string newDirection = direction(initialTX, initialTY, lightX, lightY);
        //update the thor position
        moveThor(initialTX, initialTY, newDirection);
        // A single line providing the move to be made: N NE E SE S SW W or NW
        cout <<  newDirection << endl;
    }
}