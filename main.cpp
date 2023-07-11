#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <limits>

// Function to check if a string represents an integer
bool isInteger(const std::string& input) {
    std::stringstream ss(input);
    int number;
    return (ss >> number) && ss.eof();
}

// Example using string streams
void stringStreamsExample() {
    double pi = 3.1415926535; // Full value of pi with 10 decimal places
    // String Streams Example

    // String Streams Example

    int number1 = 42; // Initialize an integer variable 'number1' with the value 42

    std::stringstream ss; // Create a string stream object 'ss'

// Insert values into the string stream
    ss << "The pi is: " << number1 << ", and pi is approximately: " << pi;

    std::string result = ss.str(); // Get the string value from the string stream using 'str()' method

    std::cout << "Result is: " << result << std::endl; // Print the resulting string to the console
}

// Example of validating an integer input using a loop
void validateIntegerInput() {
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

}

// Example using ostringstream
void ostringstreamExample() {
    double pi = 3.1415926535;
    int number2 = 42;
    /// Now another example using ostringstream,
    std::cout << "\nNow another example using ostringstream\n";
    std::ostringstream oss; // Create an ostringstream object

    std::string name = "John Doe";

    // Insert values into the ostringstream
    oss << "Number: " << number2 << ", Pi: " << pi << ", Name: " << name;

    std::string result1 = oss.str(); // Get the resulting string from the ostringstream

    std::cout << result1 << std::endl; // Print the resulting string
}

// Example of validating an integer input using a do-while loop
void validateIntegerInputDoWhile() {
    std::string inputVal;
    bool validInput = false;

    do {
        std::cout << "Validator of integer.\n";
        std::cout << "Enter an integer: ";
        std::cin >> inputVal;

        if (isInteger(inputVal)) {
            std::cout << "Valid integer input." << std::endl;
            validInput = true;
        } else {
            std::cout << "Invalid input. Not an integer." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (!validInput);
}

// Example of I/O operations
void ioExample() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;
    std::cout << "You entered: " << num << std::endl;
}
/*
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


// Example of stream manipulators

void streamManipulatorsExample() {
    double pi = 3.1415926535;
    int num = 42;

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
}

// Example of file I/O operations
void fileIOExample() {

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

}



int main() {



    stringStreamsExample();
    validateIntegerInput();
    ostringstreamExample();
    validateIntegerInputDoWhile();
    ioExample();
    streamManipulatorsExample();
    fileIOExample();




    return 0;
}
