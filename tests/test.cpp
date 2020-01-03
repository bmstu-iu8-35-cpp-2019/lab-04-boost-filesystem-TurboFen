// Copyright 2019 TurboFen <TurboFenix@yandex.ru>

#include <gtest/gtest.h>
#include <header.hpp>

TEST(TestProg, EmptyTest) {
  std::vector<File> files;
  char* argv[] = new char[2]();
  argv[1] = "..//misc//ftp";
  EXPECT_EQ(main_function(2, argv), 0);
}
