#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

// Define and initialize the Soundex codes array
static char soundexCodes[256];

// Function to initialize the Soundex codes array
void initializeSoundexCodes() {
    // Initialize all characters to default Soundex code '0'
    for (int i = 0; i < 256; i++) {
        soundexCodes[i] = '0';
    }

    // Set specific characters
    soundexCodes['A'] = '0'; soundexCodes['E'] = '0';
    soundexCodes['I'] = '0'; soundexCodes['O'] = '0';
    soundexCodes['U'] = '0';
    
    soundexCodes['B'] = '1'; soundexCodes['F'] = '1';
    soundexCodes['P'] = '1'; soundexCodes['V'] = '1';
    
    soundexCodes['C'] = '2'; soundexCodes['G'] = '2';
    soundexCodes['J'] = '2'; soundexCodes['K'] = '2';
    soundexCodes['Q'] = '2'; soundexCodes['S'] = '2';
    soundexCodes['X'] = '2'; soundexCodes['Z'] = '2';
    
    soundexCodes['D'] = '3'; soundexCodes['T'] = '3';
    
    soundexCodes['L'] = '4';
    
    soundexCodes['M'] = '5'; soundexCodes['N'] = '5';
    
    soundexCodes['R'] = '6';
    
    soundexCodes['H'] = '0'; soundexCodes['W'] = '0';
    soundexCodes[' '] = '0'; // Default for spaces
}


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

// Helper function to handle vowel skipping
int shouldSkipVowel(char currentChar, char prevCode, char nextCode) {
    return isVowel(currentChar) && (prevCode == nextCode);
}

void appendSoundexCode(const char *name, char *soundex, int *sIndex, char *prevCode, int len) {
    for (int i = 1; i < len && *sIndex < 4; i++) {
        char currentCode = getSoundexCode(name[i]);
        char nextCode = (i + 1 < len) ? getSoundexCode(name[i + 1]) : '0';

        if (isVowel(name[i]) && *prevCode == nextCode) {
            *prevCode = currentCode;
            continue;
        }

        if (shouldAddCode(*prevCode, currentCode)) {
            soundex[(*sIndex)++] = currentCode;
            *prevCode = currentCode;
        }
    }
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
    char prevCode = getSoundexCode(name[0]);

    appendSoundexCode(name, soundex, &sIndex, &prevCode, len);
   
    while (sIndex < 4) {
        soundex[sIndex++] = '0';  // Pad with zeros if needed
    }

    soundex[4] = '\0';  // Null-terminate the string
}

#endif // SOUNDEX_H
