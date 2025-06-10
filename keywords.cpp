// keywords.cpp
#include "headers/keywords.hpp"
#include <vector>   // For std::vector
#include <string>   // For std::string
#include <regex>    // For std::regex
#include <utility>  // For std::pair

namespace keywords {
    // Defines the 'From' keyword transformation. Handles nested namespaces and templates.
    // Example: `type From namespace @` -> `namespace::type`

        const std::pair<std::regex, std::string> from_keyword_rule =
        {std::regex(R"(\b([\w*&_]+(?:<[\w<>,&*\s\[\]().~^|!=%+\-/?]+>)*)\s+From\s+((?:[\w*&_]+::)*[\w*&_]+)\s*)"), "$2::$1 "};
    // Ordered list of NatPP to C++ replacement rules. Order is critical.
        std::vector<std::pair<std::regex, std::string>> replacements = {
        // --- Order is crucial! ---
        
        // 1. 'From' keyword: Applied first for complex type/namespace resolution.
        from_keyword_rule,

        // 2. Block delimiters: Transform 'Then' and 'Okay' to C++ braces.
        {std::regex(R"(\bThen\b)"), "{"},
        {std::regex(R"(\bOkay\b)"), "}"},

        // 3. Import statements: Convert to C++ #include directives.
        {std::regex(R"(ImportCode\s*<([^>]+)>)"), "#include <$1>"},
        {std::regex(R"(ImportCodeLocal\s*\"([^\"]+)\")"), "#include \"$1\""},
        {std::regex(R"(ImportCode\s+([^\s<>\"']+))"), "#include <$1>"},
        
        // 4. Define macros: Simple text replacement for constants.
        {std::regex(R"(\bDefine\s+(\w+)\s+([^\n]+))"), "#define $1 $2"},

        // 5. ForEach loop: Transform to C++ range-based for loop.
        {std::regex(R"(\bForEach\s*\(\s*(?:([\w*&_]+)\s+)?([\w*&_]+)\s+In\s+([^\)]+)\s*\))"), "for ($1 $2 : $3)"},
        
        // 6. Control flow: Convert conditional and loop keywords.
        {std::regex(R"(\bIf\b)"), "if"},
        {std::regex(R"(\bElse\b)"), "else"}, 
        {std::regex(R"(\bWhile\b)"), "while" },
        {std::regex(R"(\bFor\s*\(\s*Start\s*([^\n]+?)\s*CheckIf\s*([^\n]+?)\s*Task\s*([^\n]+?)\s*\))"), "for ($1; $2; $3)"},

        // 7. Operators: Convert NatPP operators to C++ equivalents.
        {std::regex(R"(\bIs\b)"), "="}, 
        {std::regex(R"(\bAnd\b)"), "&&"},
        {std::regex(R"(\bOr\b)"), "||"},
        {std::regex(R"(\bNot\b)"), "!"}, 

        {std::regex(R"(\bStrictAnd\b)"), "&"},
        {std::regex(R"(\bStrictOr\b)"), "|"}, 
        {std::regex(R"(\bReverseBit\b)"), "~"},
        {std::regex(R"(\bMoveLeft\b)"), "<<"},
        {std::regex(R"(\bMoveRight\b)"), ">>"},
        {std::regex(R"(\bXor\b)"), "^"},

        // Comparison operators.
        {std::regex(R"(\bUnder\b)"), "<"},
        {std::regex(R"(\bExceed\b)"), ">"},
        {std::regex(R"(\bEqual\b)"), "==" },
        {std::regex(R"(\bNotEqual\b)"), "!=" },
        {std::regex(R"(\bBelow\b)"), "<=" },
        {std::regex(R"(\bOver\b)"),">="},
        
        // Other functions and keywords.
        {std::regex(R"(\bCheckCasesIn\b)"), "switch"},
        {std::regex(R"(\bContinue\b)"), "continue"},
        {std::regex(R"(\bBreak\b)"), "break"},
        {std::regex(R"(\bIncrementNow\b)"), "++"},
        {std::regex(R"(\bDecrementNow\b)"), "--"},
        {std::regex(R"(\bFormattedPrint\b)"), "printf"},
        {std::regex(R"(\bFormattedScan\b)"), "scanf"},
        {std::regex(R"(\bReturn\b)"), "return"}, 

        // 8. Type qualifiers: Applied last to ensure correct placement.
        {std::regex(R"(\bCONST\b)"), "const "}, 
        {std::regex(R"(\bVOLATILE\b)"), "volatile "},
        {std::regex(R"(\bRESTRICT\b)"), "restrict "},
        {std::regex(R"(\bREGISTER\b)"), "register "},
        {std::regex(R"(\bTHREADLOCAL\b)"), "thread_local "},
        {std::regex(R"(\bMUTABLE\b)"), "mutable "}, 
    };
}
