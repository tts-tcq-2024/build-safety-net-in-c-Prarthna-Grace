#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  generateSoundex("Robert", soundex);
  ASSERT_STREQ(soundex,"A200");
 
 // ASSERT_STREQ("Robert", "R163");

}
