#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

char getSoundexCode(char c);
void null_check(const char *name, char *soundex);
void addCodeifValid(char currentCode, char prevCode, char *soundex, int *sIndex);
void appendSoundexCode(const char *name, char *soundex, int *sIndex, int len);
void zero_Padding(char *soundex);

// Define the mapping for Soundex codes
const char soundexMapping[26] = {
    '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', // A-J
    '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', // K-T
    '0', '1', '0', '2', '0', '2'  // U-Z
};
 
// Function to get the Soundex code for a character
char getSoundexCode(char c) {
    c = toupper(c);
    if (c >= 'A' && c <= 'Z') {
        return soundexMapping[c - 'A']; // Map letter to code
    }
    return '0'; // For non-alphabet characters
}

// Check for NULL or empty string
void null_check(const char *name, char *soundex)
{
if (name == NULL || name[0] == '\0') {
    soundex[0] = '\0';  // Return an empty Soundex 
    return;
}
}

void addCodeifValid(char currentCode, char prevCode, char *soundex, int *sIndex) {
    if (currentCode != '0' && currentCode != prevCode) { // Check if the code should be added
        soundex[(*sIndex)++] = currentCode;
    }
}

//Function to fill the extra spaces with zeros.
void zero_Padding(char *soundex, int *sIndex) {
    while(*sIndex < 4) {
        soundex[*sIndex++] = '0';
    }
    soundex[4] = '\0';
}

void appendSoundexCode(const char *name, char *soundex, int *sIndex, int len) {
    for (int i = 1; i < len && *sIndex < 4; i++) {
        char currentCode = getSoundexCode(name[i]);
        addCodeifValid(currentCode, soundex[*sIndex - 1], soundex, sIndex);
    }
}

void generateSoundex(const char *name, char *soundex) {
    soundex[0] = toupper(name[0]); // Set the first letter of the Soundex code
    int len = strlen(name);   
    null_check(name, soundex); 
    int sIndex = 1;
    appendSoundexCode(name, soundex, &sIndex, len);
    zero_Padding(soundex,&sIndex);
}

#endif // SOUNDEX_H
