#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

void initializeSoundexCodes();
char getSoundexCode(char c);
void null_check(const char *name, char *soundex);
void first_letter(char *name, char *soundex);
int isVowel(char c);
void appendSoundexCode(const char *name, char *soundex, int *sIndex, char *prevCode, int len);
void zero_Padding(char *soundex);

// Define and initialize the Soundex codes array
static char soundexCodes[256];

// Function to initialize the Soundex codes array
void initializeSoundexCodes() {
    // Initialize all characters to default Soundex code '0'
    for (int i = 0; i < 256; i++) {
        soundexCodes[i] = '0';
    }
    soundexCodes['B'] = soundexCodes['F'] = soundexCodes['P'] = soundexCodes['V'] = '1';
    soundexCodes['C'] = soundexCodes['G'] = soundexCodes['J'] = soundexCodes['K'] = '2';
    soundexCodes['Q'] = soundexCodes['S'] = soundexCodes['X'] = soundexCodes['Z'] = '2';
    soundexCodes['D'] = soundexCodes['T'] = '3';
    soundexCodes['L'] = '4';
    soundexCodes['M'] = soundexCodes['N'] = '5';
    soundexCodes['R'] = '6';
    // Vowels and others default to '0'
}

// Returns the Soundex code for a given character
char getSoundexCode(char c) {
    return soundexCodes[toupper(c)];
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

int isVowel(char c) {
    c = toupper(c);
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

// Checks if the current character should be added to the Soundex code
int shouldAddCode(char prevCode, char currentCode) {
    // Skip zero codes and adjacent same codes
    return (currentCode != '0' && currentCode != prevCode);
}

void appendSoundexCode(const char *name, char *soundex, int *sIndex, char *prevCode, int len) {
    for (int i = 1; i < len && *sIndex < 4; i++) {
        char currentCode = getSoundexCode(name[i]);
        char nextCode = (i + 1 < len) ? getSoundexCode(name[i + 1]) : '0';

        if (isVowel(name[i]) && *prevCode == nextCode) {
            *prevCode = currentCode;
        }

        if (shouldAddCode(*prevCode, currentCode)) {
            soundex[(*sIndex)++] = currentCode;
            *prevCode = currentCode;
        }
    }
}

void zero_Padding(char *soundex) {
    int len = strlen(soundex); /* len - current length of the soundex code */
    while(len < 4) {
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
    zero_padding(soundex);
}

#endif // SOUNDEX_H
