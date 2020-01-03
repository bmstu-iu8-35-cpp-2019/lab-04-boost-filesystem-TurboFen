// Copyright 2019 TurboFen <TurboFenix@yandex.ru>

#include <gtest/gtest.h>
#include <header.hpp>

TEST(TestProg, EmptyTest) {
  char* argv[] = {"../misc/ftp"};
  EXPECT_EQ(main_special(1, argv[]), 0);
}
