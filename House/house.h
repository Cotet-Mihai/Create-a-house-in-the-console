#pragma once

#include <iostream>


using namespace std;

class House {
private:
    int _base; // the base size of the house
    string _border; // the border character
    string _fill; // the fill character

public:
    // Constructor
    House(int base, char border = 'X', char fill = '*')
        : _base((base <= 3) ? 3 : (base >= 30) ? 30 : base), // Initialize base size within range
        _border(1, border), // Initialize border character
        _fill(1, fill) // Initialize fill character
    {

    }

    // Get the base size of the house
    int GetSize() { return _base; }

    // Calculate and return the perimeter of the house
    int Perimeter() { return (3 * (_base + 2) + (2 * _base)); }

    // Calculate and return the area of the house
    float Area() { return (pow((_base + 2), 2) * (sqrt(3) / 4)) + (pow(_base, 2)); }

    // Increase the base size of the house by 1, unless it exceeds 30
    void Grow() { _base < 30 ? _base++ : _base; }

    // Decrease the base size of the house by 1, unless it goes below 3
    void Shrink() { _base > 3 ? _base-- : _base; }

    // Set the border character of the house
    void SetBorder(char newBorder) {
        // Limit newBoarder to characters between ASCII 33 and ASCII 126
        newBorder >= '!' && newBorder <= '~' ? _border = newBorder : _border = 'X';
    }

    // Set the fill character of the house
    void SetFill(char newFill) {
        // Limit newFill to characters between ASCII 33 and ASCII 126
        newFill >= '!' && newFill <= '~' ? _fill = newFill : _fill = '*';
    }

    // Draw the house
    void Draw() const {
        // Roof
        for (int i = 0; i <= _base; i++) {
            // Distance from the edge
            for (int j = 0; j < _base + 1 - i; j++) { cout << " "; }
            // Display the first outline in a row
            cout << _border << ' ';
            // If it is the first row, go directly to the next row
            if (i == 0) {
                cout << endl;
                continue;
            }
            // If it is the second row, add the second border
            else if (i == 1) {
                cout << _border << ' ' << endl;
                continue;
            }
            else {
                // Fill the row with the fill character
                for (int j = 0; j < i - 1; j++) { cout << _fill << ' '; }
                // Display the last border in the row
                cout << _border << ' ';
            }
            // Move to the next line after each row
            cout << endl;
        }

        // The base of the roof
        cout << _border << ' ' << _border << ' '; // Display the border twice
        for (int i = 0; i < _base - 2; i++) { cout << _fill << ' '; } // Fill the base
        cout << _border << ' ' << _border << ' ' << endl; // Display the border twice and move to the next line

        // Body
        for (int i = 0; i < _base - 1; i++) {
            // Display the border and fill the body
            cout << "  " << _border << ' ';
            for (int j = 0; j < _base - 2; j++) {
                // If it is the last row, fill with the border character
                cout << (i == _base - 2 ? _border : _fill) << ' ';
            }
            // Display the last border and move to the next line
            cout << _border << ' ' << endl;
        }
    }

    // Overload the << operator to display the house
    friend ostream& operator<<(ostream& os, const House& house) {
        house.Draw();
        return os;
    }

    // Display a summary of the house
    void Summary() {
        cout << "Summary of the house" << endl << endl;
        cout << "Size: " << GetSize() << endl;
        cout << "Perimeter: " << Perimeter() << endl;
        cout << "Area: " << Area() << endl;
    }
};
