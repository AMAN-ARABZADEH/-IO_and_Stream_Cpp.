#include <iostream>
#include <string>

// Most I/O and Stream used Libraries:
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>

struct City{
    std::string name;
    size_t population;
    double cost;
};

struct Country{
    std::string name;
    std::vector<City> cities;
};

struct Tours{
    std::string title;
    std::vector<Country> countries;
};


void printTours(const Tours& tours) {
    std::cout << "Title: " << tours.title << std::endl;

    for (const auto& country : tours.countries) {
        std::cout << "Country: " << country.name << std::endl;

        std::cout << std::left << std::setw(15) << "City" << std::setw(12) << "Population" << "Cost" << std::endl;
        std::cout << std::setfill('-') << std::setw(40) << "" << std::setfill(' ') << std::endl;

        for (const auto& city : country.cities) {
            std::cout << std::left << std::setw(15) << city.name << std::setw(12) << city.population
                      << std::fixed << std::setprecision(2) << city.cost << std::endl;
        }

        std::cout << std::endl;
    }
}

int main() {

    auto newLine = [](){
        std::cout << std::endl;
        std::cout << "Press Enter to continue: ";
        std::cin.get();
        std::cout << std::endl;
        std::cout << std::endl;
    };

    Tours tours;
    tours.title = "European Tour";

    Country country1;
    country1.name = "France";
    country1.cities = {{"Paris", 2200000, 120.50}, {"Nice", 340000, 80.75}, {"Marseille", 860000, 95.25}};

    Country country2;
    country2.name = "Italy";
    country2.cities = {{"Rome", 2870000, 110.80}, {"Florence", 382000, 95.50}, {"Venice", 260000, 105.25}};

    tours.countries = {country1, country2};

    printTours(tours);
    std::cout << std::endl;

    newLine();
    // I/O Example
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;
    std::cout << "You entered: " << num << std::endl;



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

        double pi = 3.1415926535; // Full value of pi with 10 decimal places

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
    std::ofstream outputFile("output.txt");
    if (outputFile.is_open()) {
        outputFile << "Hello, World!" << std::endl;
        outputFile.close();
        std::cout << "File written successfully." << std::endl;
    } else {
        std::cerr << "Failed to open the file." << std::endl;
    }

    std::ifstream inputFile("input.txt");
    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::cout << line << std::endl;
        }
        inputFile.close();
    } else {
        std::cerr << "Failed to open the file." << std::endl;
    }

    newLine();


    // String Streams Example
    int number1 = 42;
    std::stringstream ss;
    ss << "The pi is: " << number1 << ", and pi is approximately: " << pi;
    std::string result = ss.str();
    std::cout << result << std::endl;

    return 0;
}
