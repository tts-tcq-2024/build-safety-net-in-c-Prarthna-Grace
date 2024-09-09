#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  generateSoundex("AX", soundex);
  generateSoundex("ba23", soundex);
  generateSoundex("cool", soundex);
  generateSoundex("darkchocolate", soundex);
 
 
 // ASSERT_STREQ("Robert", "A200");

}
