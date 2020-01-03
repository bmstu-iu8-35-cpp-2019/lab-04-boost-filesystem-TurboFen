// Copyright 2019 TurboFen <TurboFenix@yandex.ru>

#include <gtest/gtest.h>
#include <header.hpp>

TEST(TestProg, EmptyTest) {
  char* argv[] = {"Test"};
  EXPECT_EQ(main_special(1, argv[]), 0);
  char* argv2[] = {"Test", "../misc/ftp"};
  EXPECT_EQ(main_special(2, argv2[]), 0);
}
