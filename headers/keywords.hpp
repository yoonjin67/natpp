#include<unordered_map>
#include<regex>
#include<iostream>
#ifndef KEYWORDS_H
#define KEYWORDS_H
#endif

namespace keywords {
    extern std::vector<std::pair<std::regex, std::string>> replacements;
}
std::string remove_comments(const std::string& code);
std::string parse(const std:: string& code);
std::string replaceFileExtension(const std::string& filename, const std::string& newExtension);
bool checkFileExtension(const std::string& filename, const std::string& targetExtension);
