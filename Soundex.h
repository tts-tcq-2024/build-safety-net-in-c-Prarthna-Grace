#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

char getSoundexCode(char c);
void null_check(const char *name, char *soundex);
void first_letter(char *name, char *soundex);
void appendSoundexCode(const char *name, char *soundex, int *sIndex, char *prevCode, int len);
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

void first_letter(char *name, char *soundex)
{
    // Keep the first letter unchanged
    soundex[0] = toupper(name[0]);  
}

void appendSoundexCode(const char *name, char *soundex, int *sIndex, char *prevCode, int len) {
    while(i<4) {
        char currentCode = getSoundexCode(name[i]);
        char nextCode = (i + 1 < len) ? getSoundexCode(name[i + 1]) : '0';

        //Handling vowels in between adjacent codes
        if (currentCode=='7' && *prevCode == nextCode) {
            *prevCode = currentCode;
            i++;
        }
        // Add current code if it should be included
        if (currentCode != '0' && currentCode != *prevCode) {
            soundex[(*sIndex)++] = currentCode;
            *prevCode = currentCode;
            i++;
        }
    }
}

void zero_Padding(char *soundex) {
    int len = strlen(soundex); /* len - current length of the soundex code */
    for (int i = 1; i < len && *sIndex < 4; i++) {
        soundex[len++] = '0';
    }
    soundex[4] = '\0';
}

void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);   
    null_check(name, soundex); 
    int sIndex = 1;
    char prevCode = getSoundexCode(name[0]);
    appendSoundexCode(name, soundex, &sIndex, &prevCode, len);
    zero_Padding(soundex);
}

#endif // SOUNDEX_H
