#include "house.h"

using namespace std;

// Main Test
void mainTest() {

	// create some Houses
	House h1(-5), h2(7, '^'), h3(12, 'W', 'o'), h4(50, '$', '-');
	// display original Houses

	cout << "h1 has size = " << h1.GetSize() << " units.\n";
	h1.Draw();
	cout << "\nh2 has size = " << h2.GetSize() << " units.\n";
	h2.Draw();
	cout << "\nh3 has size = " << h3.GetSize() << " units.\n";
	h3.Draw();
	cout << "\nh4 has size = " << h4.GetSize() << " units.\n";
	h4.Draw();
	cout << '\n';

	h1.Shrink(); // demonstrate shrink
	h2.Shrink();
	h3.Grow(); // and grow
	h4.Grow();
	cout << "h1 now has size = " << h1.GetSize() << " units.\n";
	cout << "h2 now has size = " << h2.GetSize() << " units.\n";
	cout << "h3 now has size = " << h3.GetSize() << " units.\n";
	cout << "h4 now has size = " << h4.GetSize() << " units.\n";

	// demonstrate perimeter
	cout << "h2 has perimeter = " << h2.Perimeter() << " units.\n";
	cout << "h3 has perimeter = " << h3.Perimeter() << " units.\n";
	// and area
	cout << "h2 has area = " << h2.Area() << " square units.\n\n";
	cout << "h3 has area = " << h3.Area() << " square units.\n\n";

	h1.Draw();
	h1.Grow();               // show that fill character
	cout << "h1 grows:\n";   // appears only when size
	h1.Draw();               // is at least 3
	h1.Grow();
	cout << "... and grows:\n";
	h1.Draw();
	cout << '\n';

	h1 = h2; // demonstrate the default overload of the
	// assignment operator
	cout << "h1 now has size = " << h1.GetSize() << " units.\n";
	h1.Draw();

	// demonstrate the changing of border and fill characters
	h2.SetBorder('@');
	h2.SetFill('-');
	cout << "h2 now looks like:\n";
	h2.Draw();
	cout << '\n';
	h2.SetBorder('\n');	 // illegal border
	h2.SetFill('\a');	 // illegal fill
	cout << "h2 now looks like:\n";
	h2.Draw();
	cout << '\n';

	cout << "\nHere is a summary on h3:\n"; // demonstrate summary
	h3.Summary();
}

// My Test
void myTest() {

	int size; // Declare a variable to store the size of the house
	do {
		cout << "Enter the size of the house (a positive integer): "; // Prompt the user to enter the size of the house
		cin >> size; // Read the input for the size of the house

		if (size <= 0) { // Check if the input is not a positive integer
			cout << "Invalid input. Please enter a positive integer." << endl << endl; // Display an error message for invalid input
			cin.clear(); // Clear the error state of the input stream
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the remaining characters until the next newline
		}
	} while (size <= 0); // Repeat the loop if the input is not a positive integer


	House house(size); // Create a House object with the specified size
	cout << house; // Draw the initial house

	cout << endl;
	house.Summary(); // Display the summary of the initial house
	cout << endl;

	bool isRunning = true; // Initialize the flag to control the loop

	while (isRunning) { // Start a loop for modifying the house
		cout << "|------------------------------|" << endl;
		cout << "| Menu for modifying the house |" << endl;
		cout << "|------------------------------|" << endl;
		cout << "|1| Increase House Size        |" << endl; // Option to increase house size
		cout << "|2| Decrease House Size        |" << endl; // Option to decrease house size
		cout << "|3| Change Border              |" << endl; // Option to change the border of the house
		cout << "|4| Change Interior            |" << endl; // Option to change the interior of the house
		cout << "|------------------------------|" << endl;
		cout << "|9| Close the application      |" << endl; // Option to close the application
		cout << "|------------------------------|" << endl;
		cout << endl;
		cout << "Navigate: ";

		int choice;

		cin >> choice; // Read the user's choice
		cout << endl;

		switch (choice) // Perform actions based on the user's choice
		{
		case (1):
			house.Grow(); // Increase the size of the house
			cout << house; // Redraw the house

			cout << endl;

			house.Summary(); // Display the summary of the modified house

			cout << endl;
			break;

		case (2):
			house.Shrink(); // Decrease the size of the house
			cout << house; // Redraw the house

			cout << endl;

			house.Summary(); // Display the summary of the modified house

			cout << endl;
			break;

		case (3):

			cout << "Symbol to change the border: ";
			char changeBorder;
			cin >> changeBorder;

			house.SetBorder(changeBorder); // Change the border symbol of the house
			cout << house; // Redraw the house

			cout << endl;

			house.Summary(); // Display the summary of the modified house

			cout << endl;
			break;

		case (4):
			cout << "Symbol to change the interior: ";
			char changeFill;
			cin >> changeFill;

			house.SetFill(changeFill); // Change the interior symbol of the house
			cout << house; // Redraw the house

			cout << endl;

			house.Summary(); // Display the summary of the modified house

			cout << endl;
			break;

		case (9):
			cout << "Are you sure you want to close the application? (y): "; // Ask the user if they want to close the application
			char answer; // Declare a variable to store the user's response
			cin >> answer; // Read the user's response
			cout << endl << endl;

			answer = tolower(answer); // Convert the user's response to lowercase

			if (answer == 'y') { // Check if the user's response is 'y'
				isRunning = false; // Set the variable isRunning to false to exit the loop
			}
			else {
				cout << "Continuing the application." << endl; // Display a message indicating that the application will continue
			}

			cout << endl;
			break;


		default:
			cout << "Command not recognized. Please enter a number between 1 - 4 or 9 to close the application!";

			//For the case that the user enters anything other than an integer

			cin.clear(); // Clear the error state of the input stream
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the remaining characters until the next newline
			break;
		}
	}
}


int main()
{
	myTest();
		
	return 0;
}