#include <gtest/gtest.h>
#include "Soundex.h"
 
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
//AAA
  char soundex[5];
  generateSoundex("Robert", soundex);
  ASSERT_STREQ(soundex,"R163");
  generateSoundex("ac", soundex);
  ASSERT_STREQ(soundex,"A200");
  generateSoundex("ad", soundex);
  ASSERT_STREQ(soundex,"A300");
  generateSoundex("af", soundex);
  ASSERT_STREQ(soundex,"A100");
  generateSoundex("aEIOU", soundex);
  ASSERT_STREQ(soundex,"A100");
// ASSERT_STREQ("Robert", "R163");
 
}

