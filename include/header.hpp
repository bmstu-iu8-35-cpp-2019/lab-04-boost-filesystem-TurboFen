// Copyright 2019 TurboFen <TurboFenix@yandex.ru>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <iostream>
#include <boost/filesystem.hpp>
#include <fstream>
#include <string>
#include <utility>
#include <vector>

using boost::filesystem::path;
using boost::filesystem::directory_entry;
using boost::filesystem::directory_iterator;


struct File {
    std::string broker;
    std::string account;
    std::string l_date;
    size_t num;
    File(std::string, std::string);
};

bool CheckData(int, int, int);

void check_files(path&, std::vector<File>&);
std::ostream& operator<<(std::ostream&, const File&);
int main_special(int args, char* argv[]);

#endif // INCLUDE_HEADER_HPP_
