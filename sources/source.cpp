// Copyright 2019 TurboFen <TurboFenix@yandex.ru>

#include "header.hpp"


File::File(std::string pam, std::string filename) :
    broker(pam),
    account(filename.substr(8, 8)),
    l_date(filename.substr(17, 8)),
    num(1) {}

bool CheckData(int year, int month, int day)
{
    bool pam = false;
    if (year < 1970 || year > 2019)
    {
        pam = true;
    }
    if (month < 0 || month > 12 && pam == true) {
        pam = true;
    }
    if (day < 0 && pam == true) {
        pam = true;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11 && pam == true) {
        if (day > 30) pam = true;
    }else if (month == 2) {
        if (year % 4 == 0) {
            if (day > 29) pam = true;
        }else {
            if (day > 28) pam = true;
        }
    }else {
        if (day > 31) pam = true;
    }
    if (pam == true)
    {
        return true;
    }else {
        return false;
    }
}
void check_files(const path& p, std::vector<File>& pam)
{
    if (!exists(p))
    {
        exit(10);
    }
    for (auto & x : directory_iterator{ p })
    {
        if (is_regular_file(x.path())) {
            std::string filename = x.path().filename().string();
            if (x.path().extension() == ".old.txt")
            {
                continue;
            }
            if (filename.substr(0, 8) != "balance_")
            {
                continue;
            }
            if (filename.substr(25, 33) == ".old.txt")
            {
                continue;
            }
            for (size_t i = 8; i < 16; i++) {
                if (filename[i] < '0' || filename[i] > '9')
                {
                    continue;
                }
            }
            if (filename[16] != '_') {
                continue;
            }
            for (size_t i = 17; i < 25; i++) {
                if (filename[i] < '0' || filename[i] > '9') {
                    continue;
                }
            }
            if (filename[25] != '.') {
                continue;
            }
            int day = 10 * (filename[23] - 48) + (filename[24] - 48);
            int month = 10 * (filename[21] - 48) + (filename[22] - 48);
            int year = 1000 * (filename[17] - 48) + 10 * (filename[18] - 48) +
                10 * (filename[19] - 48) + (filename[20] - 48);
            if (CheckData(year, month, day))
            {
                continue;
            }
            std::cout << p.filename().string() << " " << filename << std::endl;
            File new_file(p.filename().string(), filename);
            bool inserted = false;



            for (auto& pos : pam) {
                if (pos.broker == new_file.broker) {
                    if (pos.account == new_file.account) {
                        pos.num++;
                        pos.l_date = pos.l_date > new_file.l_date
                            ? pos.l_date : new_file.l_date;
                        inserted = true;
                    }
                }
            }
            if (!inserted) {
                pam.push_back(new_file);
            }
        }
        if (is_directory(x.path()))
        {
            check_files(x.path(), pam);
        }
    }
}
std::ostream& operator<<(std::ostream& out, const File& file) {
    out << "broker:" << file.broker
        << " account:" << file.account
        << " files:" << file.num
        << " lastdate:" << file.l_date;
    return out;
}
int main_special(int args, char* argv[])
{
    std::vector<File> files;
    if (args == 1)
    {
        const boost::filesystem::path p(boost::filesystem::current_path());
        check_files(p, files);
    }else {
        const boost::filesystem::path p(argv[1]);
        check_files(p, files);
    }
    for (auto pos : files) std::cout << std::endl << pos;
    return 0;
}
