#include <Windows.h>
#include <filesystem>

using dir_it = std::filesystem::directory_iterator;

void print_console(const std::wstring_view& str) {
    WriteConsoleW(
            GetStdHandle(STD_OUTPUT_HANDLE), 
            str.data(), 
            str.size(), 
            nullptr, 
            nullptr
        );
        putwchar('\n');
}

int wmain() {
    std::filesystem::path path {L"C:\\Users\\user1\\Documents\\Warcraft III"};
    for (const auto& dir_entry: dir_it{path}) {
        if (dir_entry.path() == path) continue;
        print_console(dir_entry.path().native());
    }
}