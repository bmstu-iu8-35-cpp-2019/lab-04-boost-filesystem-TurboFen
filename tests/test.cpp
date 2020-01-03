// Copyright 2019 TurboFen <TurboFenix@yandex.ru>

#include <gtest/gtest.h>
#include <header.hpp>

TEST(TestProg, EmptyTest) {
  std::vector<File> files;
  int ar = 2;
  char tmp1[] = "Test";
  char tmp2[] = "..//misc//ftp";
  char* argv[] = {tmp1, tmp2};
  EXPECT_EQ(main_special(ar, argv), 0);
}
