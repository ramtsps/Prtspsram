%{
#include "cd5.tab.h" // Include the parser header file before defining token names
%}
%%
[ \t\n] /* Ignore whitespace */
"for" { return FOR; }
"while" { return WHILE; }
"if" { return IF; }
"else" { return ELSE; }
"(" { return LPAREN; }
")" { return RPAREN; }
"{" { return LBRACE; }
"}" { return RBRACE; }
";" { return SEMICOLON; }
[0-9]+ { return NUMBER; }
[a-zA-Z_][a-zA-Z0-9_]* { return IDENTIFIER; }
. { return yytext[0]; } // Any other character is returned as is
%%
int yywrap() {
    return 1; // Indicate that there are no more input files to process
}