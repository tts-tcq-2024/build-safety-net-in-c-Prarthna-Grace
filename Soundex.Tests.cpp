#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  generateSoundex("Robert", soundex);
  ASSERT_STREQ(soundex,"R163");
  
  generateSoundex("Euler", soundex);
  ASSERT_STREQ(soundex,"E460");

  generateSoundex("A", soundex);
  ASSERT_STREQ(soundex,"A000");

  generateSoundex(" ", soundex);
  ASSERT_STREQ(soundex,"0000");
 
 // ASSERT_STREQ("Robert", "R163");

}
