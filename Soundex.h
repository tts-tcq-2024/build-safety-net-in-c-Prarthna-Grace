#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

// Lookup array for Soundex codes
static const char soundexCodes[256] = {
  {
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'},
        {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
};

// Default to '0' for characters not explicitly listed
static const char defaultSoundexCode = '0';

// Returns the Soundex code for a given character
char getSoundexCode(char c) {
    return soundexCodes[toupper(c)];
}

int isVowel(char c) {
    c = toupper(c);
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

// Checks if the current character should be added to the Soundex code
int shouldAddCode(char prevCode, char currentCode) {
    // Skip zero codes and adjacent same codes
    return (currentCode != '0' && currentCode != prevCode);
}

void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    
    // Check for NULL or empty string
    if (name == NULL || name[0] == '\0') {
        soundex[0] = '\0';  // Return an empty Soundex 
        return;
    }
    
    // Keep the first letter unchanged
    soundex[0] = toupper(name[0]);  
    int sIndex = 1;

    // Track previous code
    char prevCode = getSoundexCode(name[0]);  
    for (int i = 1; i < len && sIndex < 4; i++) {
        char currentChar = name[i];
        char currentCode = getSoundexCode(currentChar);

        // Handle the case where a vowel is between two characters with the same code
        if (i + 1 < len) {
            char nextChar = name[i + 1];
            char nextCode = getSoundexCode(nextChar);
            if (prevCode == nextCode && isVowel(currentChar)) {
                i++;  // Skip the vowel
                continue;
            }
        }

        // Decide whether to add the current code based on previous code
        if (shouldAddCode(prevCode, currentCode)) {
            soundex[sIndex++] = currentCode;
            prevCode = currentCode;
        }
    }
    
    while (sIndex < 4) {
        soundex[sIndex++] = '0';  // Pad with zeros if needed
    }

    soundex[4] = '\0';  // Null-terminate the string
}

#endif // SOUNDEX_H
