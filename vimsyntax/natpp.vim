" Vim syntax file for NatPP
" Language: NatPP (Natural Programming Preprocessor)
" Maintainer: Gemini AI
" Last Updated: 2025-06-10

" Only load if not already loaded, and explicitly source cpp syntax first
if exists("b:current_syntax")
  finish
endif

" Source the C++ syntax file. This will load all standard C++ highlighting.
" This assumes Vim can find your standard C++ syntax file (usually it can).
runtime! syntax/cpp.vim

" Now, we'll add NatPP-specific highlights on top of the C++ syntax.
" Ensure future syntax commands don't conflict with current syntax.
syntax include @cppTop syntax/cpp.vim

" Ignore case for keyword matching for NatPP-specific keywords
syn case ignore

" Define comments (NatPP uses same as C++, so cpp.vim already handles this, but redefine if needed)
" Redefining these might cause conflicts or duplicates if cpp.vim also defines them similarly.
" For simplicity and to avoid issues, we'll assume cpp.vim handles generic comments.
" If NatPP comments differ, explicitly define them here and ensure their regions don't clash.

" Highlight TODOs, FIXMEs, etc., within comments (cpp.vim usually has this too)
syn keyword natppTodo FIXME TODO XXX containedin=natppCommentGroup " Use containedin for existing comment groups if you want

" Define strings (cpp.vim usually handles this)
" syn region natppString start=/"/ skip=/\\"/ end=/"/ contains=natppEscape
" syn match  natppEscape "\\["vabfnrt]" contained

" Define numbers (cpp.vim usually handles this)
" syn match natppNumber "\<[0-9]\+\(\.[0-9]\+\)\?\>"

" --- NatPP Specific Keywords ---

" Keywords: Logical and Bitwise Operators
syn keyword natppOperator Is And Or Not StrictAnd StrictOr ReverseBit MoveLeft MoveRight Xor

" Keywords: Comparison Operators
syn keyword natppOperator Under Exceed Equal NotEqual Below Over

" Keywords: Code Block Delimiters
syn keyword natppBlock Then Okay

" Keywords: Control Flow
syn keyword natppControl CheckCasesIn Continue Break If Else While For ForEach From

" Keywords: Preprocessing and I/O
syn keyword natppIO FormattedPrint FormattedScan Define ImportCode ImportCodeLocal Return

" Link NatPP highlight groups to standard Vim highlight groups.
" This ensures they adopt the colors of your current Vim color scheme.
" You might want to link to slightly different groups or define new ones for distinct colors.
hi def link natppOperator Operator
hi def link natppBlock Statement
hi def link natppControl Conditional
hi def link natppIO Preproc

" Set this buffer's syntax name to 'natpp' to prevent re-sourcing cpp.vim if already done.
" However, for a 'layered' approach, filetype will be cpp.
" let b:current_syntax = "natpp" " Removed for layered approach.

" For better integration, let's ensure NatPP keywords are highlighted.
" If they are overlapping with C++ keywords, you might need to adjust their linking.
