#include "headers/keywords.hpp" // Include your header that declares 'replacements'
#include <unordered_map>
#include <string>
namespace keywords {
    std::unordered_map<std::string, std::string> replacements = {
        {R"(\bIs\b)",  "="},
        {R"(\bAnd\b)", "&&"},
        {R"(\bOr\b)",  "||"},
        {R"(\bNot\b)", "!"}, 

        {R"(\bStrictAnd\b)", "&"},
        {R"(\bStrictOr\b)",  "&&"},
        {R"(\bReverseBit\b)", "~"},
        {R"(\bMoveLeft\b)",  "<<"},
        {R"(\bMoveRight\b)", ">>"},
        {R"(\bXor\b)", "^"},

        {R"(\bUnder\b)",  "<"},
        {R"(\bExceed\b)", ">"},
        {R"(\bEqual\b)",  "==" },
        {R"(\bNotEqual\b)", "!=" },
        {R"(\bBelow\b)",  "<=" },
        {R"(\Over\b)",">="},

        {R"(\bThen\b)", "{"},
        {R"(\bOkay\b)", "}"},

        {R"(\bCheckCasesIn\b)", "switch"},
        {R"(\bIncrementNow\b)", "++"},
        {R"(\bDecrementNow\b)", "--"},
        {R"(\bFormattedPrint\b)", "printf"},
        {R"(\bFormattedScan\b)", "scanf"},
        {R"(\bDefine\b)",         "#define"},
        {R"(\bReturn\b)",         "return"},
        {R"(ImportCode\s*<([^>]+)>)",          "#include <$1>"},
        {R"(ImportCodeLocal\s*\"([^\"]+)\")",  "#include \"$1\""},
        {R"(ImportCodeLocal\"([^\"]+)\")",     "#include \"$1\""},  
        {R"(ImportCode\s+([^\s<>\"']+))",      "#include <$1>"},
        {R"(\bIf\b)",             "if"},
        {R"(\bElse\b)",             "else"},
        {R"(\bWhile\b)",          "while" },
        {R"(\b([\w*&_]+(?:<[\w*&,_\s]+>)?(?:\s*[\w*&_]+)?)\s+From\s+((?:[\w<>,&*\s\[\]().~^|!=%+\-/?]+::)*[\w<>,&*\s\[\]().~^|!=%+\-/?]+)\s*@)", "$2::$1"},
        {R"(\bForEach\s*\(\s*Item\s+(\w+)\s+In\s+(\w+)\s*\))", "for (auto $1 : $2)"},
        {R"(\bFor\s*\(\s*Start\s*([^\n]+?)\s*CheckIf\s*([^\n]+?)\s*Task\s*([^\n]+?)\s*\))", "for ($1; $2; $3)"},
    };

}
