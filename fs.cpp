#include <Windows.h>
#include <iostream>
#include <filesystem>

using dir_it = std::filesystem::directory_iterator;

static void usage(const wchar_t* name) {
    std::wcout << "Usage: ./" << name << " [directory]\n"; 
}

void print_console(const std::wstring_view str) {
    WriteConsoleW(
            GetStdHandle(STD_OUTPUT_HANDLE), 
            str.data(), 
            str.size(), 
            nullptr, 
            nullptr
        );
        putwchar('\n');
}

int wmain(int argc, wchar_t** argv) {
    if (argc < 2) {
        usage(argv[0]);
        return 1;
    }
    std::wstring dir_name = argv[1];
    std::filesystem::path path {dir_name};
    if (!std::filesystem::exists(path)) {
        std::wcerr << dir_name << " doesn't exist\n";
        return 1;
    }
    for (const auto& dir_entry: dir_it{path}) {
        if (dir_entry.path() == path) continue;
        print_console(dir_entry.path().native());
    }
}