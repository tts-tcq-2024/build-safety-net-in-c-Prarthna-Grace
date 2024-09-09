#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

char getSoundexCode(char c) {
    c = toupper(c);
    
    if (strchr("BFPV", c)) return '1';
    if (strchr("CGJKQSXZ", c)) return '2';
    if (strchr("DT", c)) return '3';
    if (c == 'L') return '4';
    if (strchr("MN", c)) return '5';
    if (c == 'R') return '6';
    if (strchr("AEIOU", c)) return '7';
    return '0';  // ( W, H and other characters)
    
}

// Checks if the current character should be added to the Soundex code
int shouldAddCode(char prevCode, char currentCode, int position) {
    if (currentCode == '0') return 0; // Skip zero codes
    return (currentCode != prevCode); // Add if different from previous
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
        if (currentCode == '7'&& i+1 < len) {  
                char nextCode = getSoundexCode(name[i + 1]);
                if (prevCode == nextCode) {
                    soundex[sIndex++] = currentCode;
                    prevCode = currentCode;
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
