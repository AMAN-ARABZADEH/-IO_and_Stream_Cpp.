#include <iostream>
#include <string>

// Most I/O and Stream used Libraries:
#include <iomanip>
#include <fstream>
#include <sstream>
#include <limits>

bool isInteger(const std::string& input) {
    std::stringstream ss(input); // Create a stringstream object using the input string
    int number;
    return (ss >> number) && ss.eof(); // Check if extraction was successful and the stringstream is at the end of input
}



int main() {


    auto newLine = [](){
        std::cout << std::endl;
        std::cout << "Press Enter to continue: ";
        std::cin.get();
        std::cout << "\n\n" ;

    };
    double pi = 3.1415926535; // Full value of pi with 10 decimal places
    // String Streams Example

    // String Streams Example

    int number1 = 42; // Initialize an integer variable 'number1' with the value 42

    std::stringstream ss; // Create a string stream object 'ss'

// Insert values into the string stream
    ss << "The pi is: " << number1 << ", and pi is approximately: " << pi;

    std::string result = ss.str(); // Get the string value from the string stream using 'str()' method

    std::cout << "Result is: " << result << std::endl; // Print the resulting string to the console





    // A more useful example.
    std::string input; // Variable to store the user input as a string
    int number; // Variable to store the converted integer

    while (true) { // Continue looping until a valid integer is entered
        std::cout << "Enter an integer: "; // Prompt the user to enter an integer
        std::getline(std::cin, input); // Read the entire line of user input

        std::stringstream ss(input); // Create a stringstream object using the input string
        if (ss >> number) { // Attempt to extract an integer from the stringstream
            std::cout << "You entered: " << number << std::endl; // Print the entered integer
            break; // Break out of the loop when a valid integer is entered
        } else {
            std::cerr << "Invalid input. Please enter an integer." << std::endl; // Print an error message for invalid input
        }
    }

    /// Now another example using ostringstream,
    std::cout << "\nNow another example using ostringstream\n";
    std::ostringstream oss; // Create an ostringstream object

    int number2 = 42;

    std::string name = "John Doe";

    // Insert values into the ostringstream
    oss << "Number: " << number2 << ", Pi: " << pi << ", Name: " << name;

    std::string result1 = oss.str(); // Get the resulting string from the ostringstream

    std::cout << result1 << std::endl; // Print the resulting string


    // Checker validator
    std::string inputVal;
    bool validInput = false;

    do {
        std::cout << "Validator of integer.\n";
        std::cout << "Enter an integer: "; // Prompt the user to enter an integer
        std::cin >> inputVal; // Read the user input

        if (isInteger(inputVal)) { // Call the isInteger function to validate the input string
            std::cout << "Valid integer input." << std::endl; // Print a success message if the input is a valid integer
            validInput = true;
        } else {
            std::cout << "Invalid input. Not an integer." << std::endl; // Print an error message if the input is not a valid integer
            std::cin.clear(); // Clear the error state of cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the remaining characters in the buffer
        }
    } while (!validInput);


    newLine();


    // I/O Example
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;
    std::cout << "You entered: " << num << "\n";



    newLine();
    // I/O and stream  Manipulators


    /*
    Stream manipulators are functions that modify the formatting of input/output streams using the insertion (<<) and extraction (>>) operators.
     They allow you to control various aspects of the stream, such as the base, precision, alignment, fill character, and more.

     Read more here:     // https://en.cppreference.com/w/cpp/io/manip

    By applying manipulators to the output stream (std::cout) or input stream (std::cin), you can change the way data is presented or read from the stream.
     For example, you can use manipulators like std::fixed for fixed-point notation, std::scientific for scientific notation, or std::hex for hexadecimal representation.
     The std::setprecision manipulator allows you to control the pi of digits displayed after the decimal point.

    Stream manipulators also impact the alignment and width of the output.
     For instance, you can use std::setw to set the width of the output field and std::setfill to specify the fill character used for padding.
     Additionally, std::left and std::right manipulators allow you to control the alignment of the output within the field.

    The iomanip library provides a range of predefined manipulators, such as std::setw and std::setfill, specifically designed for use with the standard streams.
     These manipulators simplify the process of formatting output and reading input, as they encapsulate common formatting tasks.

    By utilizing stream manipulators effectively, you can enhance the readability and aesthetics of your program's input/output.
     This not only improves user-friendliness but also contributes to a more visually appealing and organized presentation of data.


    Explanation of each manipulator used:

    std::fixed sets the output format to fixed-point notation for floating-point numbers.
    std::setprecision() sets the precision (number of digits after the decimal point) for floating-point numbers.
    std::scientific sets the output format to scientific notation for floating-point numbers.
    std::hex sets the output format to hexadecimal representation for integer numbers.
    std::uppercase changes the output to uppercase.
    std::setw() sets the width of the output field for the next value.
    std::setfill() sets the fill character used for padding the output field.
    std::left sets the alignment of the output to left within the field.
    std::showpos displays the positive sign for positive numbers.
    std::resetiosflags() resets the specified stream manipulators to their default values.
    std::hex sets the output format to hexadecimal representation.
    std::oct sets the output format to octal representation.
    std::dec sets the output format back to decimal (default).
    std::showbase adds the base prefix (0x for hex, 0 for octal).
    std::boolalpha changes the output of bool values to alphanumeric (true or false).

     */


    // Default output: No stream manipulators are applied, so the default output format is used
        std::cout << "Default output: " << pi << std::endl;

    // Fixed-point notation with different precisions: std::fixed sets the output format to fixed-point notation
        std::cout << "Fixed-point notation (default precision): " << std::fixed << pi << std::endl;
        std::cout << "Fixed-point notation (precision: 2): " << std::fixed << std::setprecision(2) << pi << std::endl;
        std::cout << "Fixed-point notation (precision: 5): " << std::fixed << std::setprecision(5) << pi << std::endl;

    // Scientific notation with different precisions: std::scientific sets the output format to scientific notation
        std::cout << "Scientific notation (default precision): " << std::scientific << pi << std::endl;
        std::cout << "Scientific notation (precision: 2): " << std::scientific << std::setprecision(2) << pi << std::endl;
        std::cout << "Scientific notation (precision: 5): " << std::scientific << std::setprecision(5) << pi << std::endl;

    // Hexadecimal output: std::hex sets the output format to hexadecimal and std::uppercase changes the output to uppercase
        int value = 255;
        std::cout << "Hexadecimal output (uppercase): " << std::hex << std::uppercase << value << std::endl;
        std::cout << "Hexadecimal output (lowercase): " << std::hex << std::nouppercase << value << std::endl;

    // Width and fill: std::setw sets the width of the output field and std::setfill sets the fill character
        std::cout << "Width and fill: " << std::setw(10) << std::setfill('*') << num << std::endl;

    // Setting the width and alignment for integer values
        std::cout << "Default width and alignment: " << num << std::endl;
        std::cout << "Width 6: " << std::setw(6) << num << std::endl;
        std::cout << "Left-aligned width 6: " << std::left << std::setw(6) << num << std::endl;

    // Using fill characters
        std::cout << "Fill character ('*') with width 8: " << std::setfill('*') << std::setw(8) << num << std::endl;
        std::cout << "Fill character ('+') with width 6: " << std::setfill('+') << std::setw(6) << num << std::endl;

    // Show positive/negative signs: std::showpos displays the positive sign for positive numbers
        double positive = 123.45;
        double negative = -123.45;
        std::cout << "Positive value with sign: " << std::showpos << positive << std::endl;
        std::cout << "Negative value with sign: " << std::showpos << negative << std::endl;

    // Reset stream manipulators: std::resetiosflags resets the stream manipulators to their default values
        std::cout << std::resetiosflags(std::ios::scientific | std::ios::fixed | std::ios::showpos);
        std::cout << "Back to default format: " << pi << std::endl;

    // Custom alignment: std::left sets the output alignment to the left and std::setw sets the width of the output field
        std::cout << "Custom alignment: " << std::left << std::setw(10) << pi << std::endl; // prints 3.14159****

    // Hexadecimal base: std::hex sets the output format to hexadecimal
        std::cout << "Hexadecimal base: " << std::hex << 42 << std::endl; // prints 2a

    // Octal base: std::oct sets the output format to octal
        std::cout << "Octal base: " << std::oct << 42 << std::endl; // prints 52

    // Decimal base: std::dec sets the output format back to decimal (default)
        std::cout << "Decimal base: " << std::dec << 42 << std::endl; // prints 42

    // Show base prefix: std::showbase adds the base prefix (0x for hex, 0 for octal)
        std::cout << "Show base prefix: " << std::showbase;
        std::cout << "Hexadecimal base: " << std::hex << 42 << std::endl; // prints 0x2a
        std::cout << "Octal base: " << std::oct << 42 << std::endl; // prints 052

        bool flag = true;

    // Default bool output: The default output for bool values is 1 for true and 0 for false
        std::cout << "Default bool output: " << flag << std::endl; // prints 1

    // Alphanumeric bool output: std::boolalpha changes the output of bool values to alphanumeric (true or false)
        std::cout << "Alphanumeric bool output: " << std::boolalpha << flag << std::endl; // prints true

    newLine();

















// File I/O Example

// The library #include <fstream> is used
// Always close the file after you are done!
// Read more here:  https://en.cppreference.com/w/cpp/io/basic_fstream
//                  https://cplusplus.com/doc/tutorial/files/
// Writing to a file
    std::ofstream outputFile("output.txt"); // Create an output file stream object and open the file "output.txt"
    if (outputFile.is_open()) { // Check if the file was opened successfully
        outputFile << "Hello, World!" << std::endl; // Write the text "Hello, World!" to the file
        outputFile << "Hello, C++!" << std::endl;
        outputFile.close(); // Close the file
        std::cout << "File written successfully." << std::endl; // Print a success message
    } else {
        std::cerr << "Failed to open the file." << std::endl; // Print an error message if the file could not be opened
    }

// Reading from a file
    std::ifstream inputFile("output.txt"); // Create an input file stream object and open the file "input.txt"
    if (inputFile.is_open()) { // Check if the file was opened successfully
        std::string line{};
        // can also use !inputFile.eof(), indicating end of the file,
        // Read more here:
        // https://en.cppreference.com/w/cpp/io/basic_fstream
        //while(!inputFile.eof()){
        while (std::getline(inputFile, line)) { // Read each line from the file and store it in the variable 'line'
            // std::getline(inputFile, line)
            std::cout << line << std::endl; // Print the line to the console
        }
        inputFile.close(); // Close the file
    } else {
        std::cerr << "Failed to open the file." << std::endl; // Print an error message if the file could not be opened
    }

    return 0;
}
