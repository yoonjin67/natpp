
# NatPP(Nat++): A Lightweight DSL to C/C++ Transpiler (and its language)

This project defines a minimal domain-specific language (DSL) that gets transpiled into C/C++ code using simple regular expression replacements. This language focuses on a naturality, which is not enough in most of the Programming languages. And C++ is regarded as unnatural. This is why this language implemented with a bare-bone regular expression.

## Description

The DSL provides human-readable or alternative keywords for common C/C++ constructs. Using this DSL, you can write code with more "natural" language constructs which are later converted to valid C/C++ using a small regex-based transpiler.

---

## Language Specification

File extension is `*.natpp`.
Below are the supported DSL keywords and their corresponding C/C++ equivalents:

### Logical and Bitwise Operators
| DSL Keyword     | C/C++ Equivalent |
|------------------|------------------|
| `Is`             | `=`              |
| `And`            | `&&`             |
| `Or`             | `||`             |
| `Not`            | `!`              |
| `StrictAnd`      | `&`              |
| `StrictOr`       | `|`             |
| `ReverseBit`     | `~`              |
| `MoveLeft`       | `<<`             |
| `MoveRight`      | `>>`             |
| `Xor`            | `^`              |
----------------
C++ Redirection and bit shift has unified into MoveLeft, MoveRight.
This gives visual, and integrated insight.

### Comparison Operators
| DSL Keyword     | C/C++ Equivalent |
|------------------|------------------|
| `Under`          | `<`              |
| `Exceed`         | `>`              |
| `Equal`          | `==`             |
| `NotEqual`       | `!=`             |
| `Below`          | `<=`             |
| `Over`           | `>=`             |

### Code Block Delimiters
| DSL Keyword     | C/C++ Equivalent |
|------------------|------------------|
| `Then`           | `{`              |
| `Okay`           | `}`              |

### Control Flow
| DSL Keyword             | C/C++ Equivalent         |
|--------------------------|--------------------------|
| `CheckCasesIn`           | `switch`                |
| `Continue`               | `continue`              |
| `Break`                  | `break`                 |
| `If`                     | `if`                    |
| `Else`                   | `else`                  |
| `While`                  | `while`                 |
| `For(Start A CheckIf B Task C)` | `for (A; B; C)`  |
| `ForEach(Item x In y)`   | `for (Item x : y)`      |
| `member From namespace`  | `namespace::member` |

### Preprocessing and I/O
| DSL Keyword                        | C/C++ Equivalent      |
|------------------------------------|------------------------|
| `FormattedPrint`                   | `printf`              |
| `FormattedScan`                    | `scanf`               |
| `Define`                           | `#define`             |
| `Return`                           | `return`              |
| `ImportCode iostream`              | `#include <iostream>` |
| `ImportCodeLocal myfile.h`         | `#include "myfile.h"` |

---

## Example

DSL:

```dsl
ImportCode iostream
Define PI 3.14

x Is 10;
If (x Exceed 0) Then
    FormattedPrint("Positive\n");
Okay
```

Transpiled C++:

```cpp
#include <iostream>
#define PI 3.14

x = 10;
if (x > 0) {
    printf("Positive\n");
}
```

---

## How to Use

Run this script:
```bash
./build.sh
```
Then, binary named `codeconverter` is generated.

`./codeconverter filaname.natpp` to transpile into C++.

---

## License

MIT License
