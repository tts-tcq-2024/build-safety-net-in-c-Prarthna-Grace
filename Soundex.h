#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

char getSoundexCode(char c) {
    c = toupper(c);
    switch (c) {
        case 'H': case 'W': return '7';  // Ignored characters
        case 'B': case 'F': case 'P': case 'V': return '1';
        case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
        case 'D': case 'T': return '3';
        case 'L': return '4';
        case 'M': case 'N': return '5';
        case 'R': return '6';
        default: return '0';  // For vowels (A, E, I, O, U)
    }
}

void generateSoundex(const char *name, char *soundex) {
    soundex[0] = toupper(name[0]);  // Keep the first letter unchanged
    int sIndex = 1;
    int len = strlen(name);

    char prevCode = getSoundexCode(name[0]);  // Track previous code
    for (int i = 1; i < len && sIndex < 4; i++) {
        char currentChar = name[i];
        char currentCode = getSoundexCode(currentChar);

        if (currentCode == '0') {  // Skip vowels, but continue to next
            prevCode = '0';  // Reset prevCode since vowels separate similar codes
            continue;
        }

        if (currentCode == '7') {  // If H or W, check the next character but don’t add
            continue;
        }

        if (currentCode != prevCode) {  // If the current code differs from the previous, add it
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
