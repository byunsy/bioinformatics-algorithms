#include <stdio.h>
#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <set>
#include <string>

using namespace std;

//  ===========================================================================
//  DESCRIPTION:
//  The code below is based on the exercise problem from the textbook,
//  Bioinformatics Algorithms: An Active Learning Approach 2nd Edition,
//  by Phillip Compeau and Pavel Pevzner. The problem can also be found
//  at rosalind.info (BI1B).
//  ===========================================================================

//  NOTE:
//  When compiling, add "-std=c++11" at the end for std::stoi to work

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

// Finds the pattern that appears most frequently in a given text
void FrequentWords(string text, int k) {
    // Create an array to hold frequency values
    int numCount = text.length() - k + 1;
    int freq[numCount];

    // Variable for max value and a set for most-frequent kmers
    int max = 0;
    set<string> mostFrequent;

    // Loop through, perform PatternCount, and store in freq
    for (int i = 0; i < numCount; i++) {
        string pattern = text.substr(i, k);
        freq[i] = PatternCount(text, pattern);
        // Update max value
        if (freq[i] > max) {
            max = freq[i];
        }
    }
    // Loop through freq and insert most frequent kmers into the set
    for (int i = 0; i < numCount; i++) {
        if (freq[i] == max) {
            mostFrequent.insert(text.substr(i, k));
        }
    }

    cout << "The most frequent " << k << "-mer : ";

    // Create iterator and print all values in mostFrequent
    set<string>::iterator itr;
    for (itr = mostFrequent.begin(); itr != mostFrequent.end(); itr++) {
        cout << *itr << " ";
    }
    cout << "\nAppeared " << max << " times in the given text.\n\n"
         << "End of Result.\n\n";

}  // End of FrequentWords

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

    // Store sequence and kval in new variables
    string sequence, kval;
    inputTextFile >> sequence >> kval;
    int kNum = std::stoi(kval);

    cout << "\n*****Pattern Count Results*****\n\n"
         << "Input sequence : " << sequence << "\n"
         << "Input k : " << kval << "\n\n";

    // Perform FrequentWords
    FrequentWords(sequence, kNum);

    return 0;
}  // End of Main