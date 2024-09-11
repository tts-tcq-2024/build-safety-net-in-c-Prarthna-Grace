#include <gtest/gtest.h>
#include <cstring>
#include "Soundex.h"  // Include your Soundex header file

class SoundexTest : public ::testing::TestWithParam<std::tuple<std::string, std::string>> {
};

TEST_P(SoundexTest, CorrectSoundexEncoding) {
    auto [input, expected] = GetParam();
    char result[MAX_CODE_LENGTH + 1];
    generateSoundex(input.c_str(), result);
    EXPECT_EQ(expected, std::string(result));
}

INSTANTIATE_TEST_SUITE_P(
    SoundexTests,
    SoundexTest,
    ::testing::Values(
        std::make_tuple("A", "A000"),         // test soundex to pad with zeros for single character
        std::make_tuple("Rohit", "R300"),     // test soundex to replace consonants with digit code  
        std::make_tuple("A1CDFe", "A231"),    // test soundex to check Non alphabetic character 
        std::make_tuple("B[", "B000"),        // test soundex to handle special character 
        std::make_tuple("1234", "000"),       // test soundex to handle Numerics 
        std::make_tuple("@@[shr12n", "S650"), // test soundex to find first valid alphabetic character
        std::make_tuple("12shr3n", "S650"),   // test soundex to handle Numerics 
        std::make_tuple("Abfp", "A100"),      // test soundex to replace adjacent same digit code only once
        std::make_tuple("BShZ", "B200"),      // test soundex to replace characters with the same number separated by "h", "w" or "y" are coded as a single number
        std::make_tuple("", "")               //test soundex for empty
    )
);
