#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  generateSoundex("ab", soundex);
  ASSERT_STREQ(soundex,"A100");
 
 // ASSERT_STREQ("Robert", "A200");

}
