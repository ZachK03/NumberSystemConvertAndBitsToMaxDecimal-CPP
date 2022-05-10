#include <iostream>
#include <vector>
#include <string>
#include <math.h>

// Function that returns nothing and takes an int numOfBits.
// Converts the number of bits to maximum decimal value.
void GetMaxNumberForBits(int numOfBits);

// My own functions for getting user input and displaying text.
void CreateHeaderText(std::string text);
void CreateDividerText();
void CreateErrorText(std::string text);
bool GetBoolUserInput(std::string text);

int main() {
    //Introduction console output
    std::cout << "\n\n";
    CreateHeaderText("=-= Convert To Binary, Decimal, and Hex =-=");
    std::cout << "\n\n";

    //Do while loop to run the program forever until the user decides otherwise.
    //Also declaring the int outside of this loop to prevent multiple declarations.
    bool isRunning = true;
    int numOfBits;
    do {
        //Reset numOfBits to 0, just in case.
        numOfBits = 0;

        //Ask user if they'd like to convert bytes to bits.
        if(GetBoolUserInput("Convert bytes to bits first? Y/N\n")) {

            //Get user input for number of bytes.
            std::cout << "How many bytes? ";
            std::cin >> numOfBits;

            // 1 byte is 8 bits. Take the number of bytes and multiply it by 8 to get number of bits.
            numOfBits = numOfBits * 8;
        } else {

            //Get user input for number of bits.
            std::cout << "How many bits? ";
            std::cin >> numOfBits;
        };
        
        //Call function to compute max number.
        GetMaxNumberForBits(numOfBits);

        //Ask user if they'd like to use the program again.
        if(!(GetBoolUserInput("Would you like to use this again? Y/N\n"))) {
            //If no, change the variable to false to exit the loop.
            isRunning = false;
        }
    } while (isRunning);

    //Return 0 to indicate nothing went wrong.
    return 0;
}

void GetMaxNumberForBits(int numOfBits) {
    //Need an unsigned long long to prevent the issue where an excessively large int becomes a negative number.
    //Had issues when processing 32 bits that it would return -1 as the values were far too large for an int to handle.
    //This is due to the int needing to handle both positive and negatives, given their limited memory space you can't get very high with positive or negative numbers.
    unsigned long long valueReturn = 0;

    //For numOfBits - 1 to 0 add 2 to the power of i to the return value
    for (int i = (numOfBits - 1); i >= 0; i--) {
        valueReturn += std::pow(2,i);
    }

    //Tell user result
    std::cout << "Max decimal number for " << numOfBits << " bits is: " << valueReturn << ".\n";
}


//Not related to the program

void CreateHeaderText(std::string text) {
    for (int i = 0; i < text.size(); i++) {
        std::cout << "=";
    }
    std::cout << "\n" << text << "\n";
    for (int i = 0; i < text.size(); i++) {
        std::cout << "=";
    }
    std::cout << "\n";
}

void CreateDividerText() {
    for (int i = 0; i < 20; i++) {
        std::cout << "=";
    }
    std::cout << "\n";
}

void CreateErrorText(std::string text) {
    std::string errorText = "[ERROR] : ";
    errorText += text;
    CreateHeaderText(errorText);
}

bool GetBoolUserInput(std::string text) {
    char input;
    while (toupper(input) != 'Y' && toupper(input) != 'N') {
        std::cout << text;
        std::cin >> input;
    }
    if(toupper(input) == 'Y') {
        return true;
    } else {
        return false;
    }
}

