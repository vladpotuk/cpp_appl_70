#include "function.h"

int main() {
    const std::string inputFilename = "input.txt";
    const std::string outputFilename = "output.txt";

    filterAndWriteToFile(inputFilename, outputFilename);

    return 0;
}
