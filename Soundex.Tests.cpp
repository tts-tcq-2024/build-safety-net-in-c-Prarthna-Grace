#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  generateSoundex("Robert", soundex);
  ASSERT_STREQ(soundex,"R163");
 
 // ASSERT_STREQ("Robert", "R163");

}

TEST(SoudexTestSuite, RetainsFirstCharacter) {
  char soundex[5];  
  generateSoundex("aeiouyhw", soundex);
  ASSERT_STREQ(soundex,"A000");
}

TEST(SoudexTestSuite, PadsWithZerosIfLengthIsLessThanFour) {
  char soundex[5];
  generateSoundex("a", soundex);
  ASSERT_STREQ(soundex,"A000");
  generateSoundex("ab", soundex);
  ASSERT_STREQ(soundex,"A100");
}

