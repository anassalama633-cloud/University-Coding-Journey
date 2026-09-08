#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Create an output file stream object and open "data.txt" for writing
    ofstream outFile("data.txt");

    // Check if the file failed to open properly
    if (!outFile.is_open()) {
        // Display an error message if the file cannot be created or opened
        cerr << "Error: Unable to open file for writing." << endl;
        // Exit the program with an error status code
        return 1;
    }

    // Write a sentence into the file
    outFile << "Learning C++ File Handling." << endl;
    // Write a second sentence into the file
    outFile << "Files allow us to store data permanently." << endl;

    // Close the output file stream to save changes and free resources
    outFile.close();

    // Display a message indicating that data writing is complete
    cout << "Data has been successfully written to the file." << endl;

    // Create an input file stream object and open "data.txt" for reading
    ifstream inFile("data.txt");

    // Check if the file failed to open properly for reading
    if (!inFile.is_open()) {
        // Display an error message if the file cannot be found or opened
        cerr << "Error: Unable to open file for reading." << endl;
        // Exit the program with an error status code
        return 1;
    }

    // Declare a string variable to hold each line read from the file
    string currentLine;

    // Display a section header in the console
    cout << "\n--- Reading Content From File ---" << endl;

    // Read the file line by line until the end of the file is reached
    while (getline(inFile, currentLine)) {
        // Print the current line to the console
        cout << currentLine << endl;
    }

    // Close the input file stream after reading
    inFile.close();

    // Return 0 to indicate that the program executed successfully
    return 0;
}
