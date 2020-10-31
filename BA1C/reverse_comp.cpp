#include <stdio.h>
#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <set>
#include <string>

//  ===========================================================================
//  DESCRIPTION:
//  The code below is based on the exercise problem from the textbook,
//  Bioinformatics Algorithms: An Active Learning Approach 2nd Edition,
//  by Phillip Compeau and Pavel Pevzner. The problem can also be found
//  at rosalind.info (BA1C).
//  ===========================================================================

char atgc_complement(char nucleotide) {
    // If A or a, complement is T
    if (nucleotide == 'A' || nucleotide == 'a') {
        nucleotide = 'T';
        return nucleotide;
    }
    // If T or t, complement is A
    else if (nucleotide == 'T' || nucleotide == 't') {
        nucleotide = 'A';
        return nucleotide;
    }
    // If G or g, complement is C
    else if (nucleotide == 'G' || nucleotide == 'g') {
        nucleotide = 'C';
        return nucleotide;
    }
    // If C or c, complement is G
    else if (nucleotide == 'C' || nucleotide == 'c') {
        nucleotide = 'G';
        return nucleotide;
    }
}

std::string ReverseComplement(std::string text, int start, int end) {
    // If text length is odd, then the middle char won't be swapped
    // so first find the complement for that middle char
    if (end % 2 == 0) {
        text[end / 2] = atgc_complement(text[end / 2]);
    }

    // swap and find complement for the rest of the characters
    while (start < end) {
        // Save in a temporary variable
        char temp = text[end];

        // Swap character while finding its complement
        text[end] = atgc_complement(text[start]);
        text[start] = atgc_complement(temp);

        // Update index
        start++;
        end--;
    }

    return text;
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
    std::string sequence;
    inputTextFile >> sequence;
    int size = sequence.length();

    std::string new_seq = ReverseComplement(sequence, 0, size - 1);

    std::cout << "\n*****Reverse Complement Results*****\n\n"
              << "Original sequence : " << sequence << "\n\n"
              << "Reverse Complement: " << new_seq << "\n\n";

    return 0;
}