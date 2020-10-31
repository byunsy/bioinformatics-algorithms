#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fstream>
#include <iostream>
#include <set>

//  ===========================================================================
//  DESCRIPTION:
//  The code below is based on the exercise problem from the textbook,
//  Bioinformatics Algorithms: An Active Learning Approach 2nd Edition,
//  by Phillip Compeau and Pavel Pevzner. The problem can also be found
//  at rosalind.info (BI1B).
//  ===========================================================================

void pattern_match(std::string pattern, std::string sequence) {
    // Find length of given pattern
    int pattern_len = pattern.length();

    // Create variables for storing indices of most frequent pattern
    const int idx_list_size = 300;
    int idx_list[idx_list_size];
    int idx_counter = 0;

    // Slide through each substring of sequence
    for (int i = 0; i < sequence.length() - pattern_len + 1; i++) {
        std::string to_compare = sequence.substr(i, pattern_len);

        // If substring matches the pattern
        if (pattern.compare(to_compare) == 0) {
            // Store in the array
            idx_list[idx_counter] = i;
            idx_counter++;
        }
    }
    std::cout << "The given pattern, " << pattern << ", appeared "
              << idx_counter << " times in the following positions: ";

    for (int i = 0; i < idx_counter; i++) {
        std::cout << idx_list[i] << " ";
    }

    std::cout << "\n\nEnd of Result.\n\n";
}

//  ===========================================================================
//  MAIN PROGRAM
//  ===========================================================================
int main(int argc, char* argv[]) {
    // Error check for command line arguments
    if (argc < 2) {
        std::cout << "Too few command line arguments\n"
                  << "Usage: ./program_name input_file_name\n";
    } else if (argc > 2) {
        std::cout << "Too many command line arguments\n"
                  << "Usage: ./program_name input_file_name\n";
    }

    // Construct ifstream object and open a file from argv
    std::ifstream inputTextFile;
    inputTextFile.open(argv[1], std::ifstream::in);

    // Error check in opening input file
    if (!inputTextFile) {
        std::cout << "Error: cannot open input file.\n";
        exit(1);
    }

    // Store sequence and kval in new variables
    std::string pattern, sequence;
    inputTextFile >> pattern >> sequence;

    std::cout << "\n*****Pattern Match Results*****\n\n"
              << "Input pattern  : " << pattern << "\n"
              << "Input sequence : " << sequence << "\n\n";

    // Perform FrequentWords
    pattern_match(pattern, sequence);

    return 0;
}  // End of Main