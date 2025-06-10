#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include "headers/keywords.hpp"

// Removes single-line (//) and multi-line (/* */) comments.
std::string remove_comments(const std::string& code) {
    std::string noMultiLine = std::regex_replace(code, std::regex(R"(/\*[\s\S]*?\*/)"), "");
    std::string noSingleLine = std::regex_replace(noMultiLine, std::regex(R"(//[^\n]*)"), "");
    return noSingleLine;
}

// Replaces DSL keywords with C++ equivalents iteratively.
std::string parse(const std::string& code) {
    std::string result = code;
    bool changed_in_pass;
    int max_passes = 100;
    int current_pass = 0;

    do {
        changed_in_pass = false;
        // Apply all replacement rules.
        for (const auto& pair : keywords::replacements) {
            std::string new_content = std::regex_replace(result, pair.first, pair.second, std::regex_constants::format_default);
            
            // Update result if content changed.
            if (new_content != result) {
                result = new_content;
                changed_in_pass = true;
            }
        }
        current_pass++;
    } while (changed_in_pass && current_pass < max_passes);

    // Warn if max passes reached.
    if (current_pass >= max_passes) {
        std::cerr << "Warning: Maximum replacement passes reached. Some NatPP keywords might not be fully translated." << std::endl;
    }

    return result;
}

// Checks if a filename has a specific extension.
bool checkFileExtension(const std::string& filename, const std::string& targetExtension) {
    size_t dotPos = filename.rfind('.');
    if (dotPos == std::string::npos || dotPos == filename.length() - 1) {
        return false;
    }
    std::string actualExtension = filename.substr(dotPos + 1);
    return actualExtension == targetExtension;
}

// Replaces the extension of a filename.
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
