%{
#include <stdio.h>
#include "y.tab.h"
%}

%%
[a-zA-Z][0-9a-zA-Z]*   { return ID; }
[0-9]+                 { return DIG; }
[ \t]+                 { /* Do nothing for spaces and tabs */ }
.                      { return yytext[0]; }
\n                     { return 0; }
%%

int yywrap() {
    return 1;
}
