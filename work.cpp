#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    stringstream ss(sentence);
    string word;
   
    // Update total words
    int totalWords = 0;
    string longestWord = "";
    map<string, int> freq;
    set<string> uniqueWords;

    while (ss >> word) {
        totalWords++;

        // Update longest word
        if (word.length() > longestWord.length()) {
            longestWord = word;
        }

        // Update frequency
        freq[word]++;

        // Store unique words
        uniqueWords.insert(word);
    }

    // Find most frequent word
    vector<string> mostFrequentWords;
int maxFreq = 0;

for (auto &p : freq)
{
    if (p.second > maxFreq)
    {
        maxFreq = p.second;
        mostFrequentWords.clear();
        mostFrequentWords.push_back(p.first);
    } 
    else if (p.second == maxFreq)
    {
        mostFrequentWords.push_back(p.first);
    }
    
}
    cout << "\nTotal words: " << totalWords << endl;
    cout << "Longest word: " << longestWord << endl;
    cout << "Unique words: " << uniqueWords.size() << endl;
    cout << "Most frequent word(s): ";
for (auto &w : mostFrequentWords)
{
    cout << w << " ";
}
cout << "(appears " << maxFreq << " times)" << endl;

    return 0;
}