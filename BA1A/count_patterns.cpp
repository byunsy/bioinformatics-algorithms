#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//  ===========================================================================
//  DESCRIPTION:
//  The code below is based on the exercise problem from the textbook,
//  Bioinformatics Algorithms: An Active Learning Approach 2nd Edition,
//  by Phillip Compeau and Pavel Pevzner. The problem can also be found
//  at rosalind.info (BI1A).
//  ===========================================================================

// Counts the number of times a pattern appears in a given text
int PatternCount(string text, string pattern) {
    // Create a counter
    int count = 0;

    // Loop through and check patterns in a given line of text.
    for (int i = 0; i <= text.length() - pattern.length(); i++) {
        string sub = text.substr(i, pattern.length());
        if (sub.compare(pattern) == 0) {
            count++;
        }
    }
    return count;
}  // End of PatternCount

//  ===========================================================================
//  MAIN PROGRAM
//  ===========================================================================
int main(int argc, char* argv[]) {
    // Error check for command line arguments
    if (argc < 2) {
        cout << "Too few command line arguments\n"
             << "Usage: ./program_name input_file_name\n";
    } else if (argc > 2) {
        cout << "Too many command line arguments\n"
             << "Usage: ./program_name input_file_name\n";
    }

    // Construct ifstream object and open a file from argv
    ifstream inputTextFile;
    inputTextFile.open(argv[1], ifstream::in);

    // Error check in opening input file
    if (!inputTextFile) {
        cout << "Error: cannot open input file.\n";
        exit(1);
    }

    // Store sequence and pattern in new variables
    string sequence, pattern;
    inputTextFile >> sequence >> pattern;

    // Perform PatternCount
    int occur = PatternCount(sequence, pattern);

    cout << "\n*****Pattern Count Results*****\n\n"
         << "Input sequence : " << sequence << "\n"
         << "Input pattern  : " << pattern << "\n\n"
         << "The pattern appeared " << occur
         << " times in the given sequence.\n\n"
         << "End of Result.\n\n";

    return 0;
}  // End of Main
