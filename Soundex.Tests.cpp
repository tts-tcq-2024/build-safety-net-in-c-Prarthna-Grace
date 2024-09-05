#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  generateSoundex("AX", soundex);
  generateSoundex("ball", soundex);
  generateSoundex("cows", soundex);
  generateSoundex("darkchocolate", soundex);
  generateSoundex("batman", soundex);
 
 // ASSERT_STREQ("Robert", "A200");

}
