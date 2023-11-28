#define _CRT_SECURE_NO_WARNINGS 

#include "function.h"
#include <iostream>

void filterAndWriteToFile(const std::string& inputFilename, const std::string& outputFilename) {
    
    std::FILE* inputFile;
    if (fopen_s(&inputFile, inputFilename.c_str(), "r") != 0) {
        std::cerr << "Error opening file: " << inputFilename << std::endl;
        return;
    }

    
    std::FILE* outputFile;
    if (fopen_s(&outputFile, outputFilename.c_str(), "w") != 0) {
        std::cerr << "Error opening file: " << outputFilename << std::endl;
        std::fclose(inputFile);
        return;
    }

   
    char word[100]; 
    while (std::fscanf(inputFile, "%99s", word) == 1) {
        if (std::strlen(word) >= 7) {
            std::fprintf(outputFile, "%s\n", word);
        }
    }
    std::fclose(inputFile);
    std::fclose(outputFile);

    std::cout << "Filtered words have been written to " << outputFilename << std::endl;
}
