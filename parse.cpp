#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include "headers/keywords.hpp"

// Removes both single-line (//) and multi-line (/* */) comments from the input code

std::string remove_comments(const std::string& code) {
    // Remove multi-line comments
    std::string noMultiLine = std::regex_replace(code, std::regex(R"(/\*[\s\S]*?\*/)"), "");
    // Remove single-line comments
    std::string noSingleLine = std::regex_replace(noMultiLine, std::regex(R"(//[^\n]*)"), "");
    return noSingleLine;
}


// Replaces DSL keywords with C++ equivalents based on the keywords::replacements map
std::string parse(const std::string& code) {
    std::string result = code;
    for (const auto& [pattern, replacement] : keywords::replacements) {
        result = std::regex_replace(
                result,
               std::regex(pattern),
               replacement,
               std::regex_constants::format_default
        );
    }
    return result;
}

// Checks if a given filename has the specified extension
bool checkFileExtension(const std::string& filename, const std::string& targetExtension) {
    size_t dotPos = filename.rfind('.');
    if (dotPos == std::string::npos || dotPos == filename.length() - 1) {
        return false;
    }
    std::string actualExtension = filename.substr(dotPos + 1);
    return actualExtension == targetExtension;
}

// Replaces the extension of a filename with a new one
std::string replaceFileExtension(const std::string& filename, const std::string& newExtension) {
    size_t dotPos = filename.rfind('.');
    std::string cleanNewExt = (newExtension.empty() || newExtension[0] == '.') 
                              ? newExtension 
                              : "." + newExtension;

    if (dotPos == std::string::npos || dotPos == filename.length() - 1) {
        return filename + cleanNewExt;
    }

    std::string baseName = filename.substr(0, dotPos);
    return baseName + cleanNewExt;
}

