#include<iostream>
#include<string>
#include<fstream>
#include<iterator>
#include "headers/keywords.hpp"


int main(int argc, char **argv) {
    if(argc==1) return 0;
    for(int i = 1; i < argc; i++) {
        std::string filename(argv[i]);
        std::string target("natpp");
        if(checkFileExtension(filename, target) == false) {
            continue;
        }
        std::ifstream inputFile(filename);
        if (!inputFile) {
            std::cerr << "Failed to open input.dsl.c" << std::endl;
            return 1;
        }

        std::string code((std::istreambuf_iterator<char>(inputFile)),
                         std::istreambuf_iterator<char>());
        inputFile.close();

        std::string rawcode    = remove_comments(code);
        std::string transpiled = parse(rawcode);
        
        std::cout << transpiled;


        std::ofstream outputFile(replaceFileExtension(filename, "cpp"));
        if (!outputFile) {
            std::cerr << "Failed to open output.cpp" << std::endl;
            return 1;
        }

        outputFile << transpiled;
        outputFile.close();

    }
    std::cout << "Transpilation completed.\n";
    return 0;
}
