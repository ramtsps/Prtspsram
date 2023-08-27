%{
#include "y.tab.h"
%}
%%
[a-zA-Z]   { return LET; }
[0-9]     { return DIG; }
.         { return yytext[0]; }
\n        { return 0; }
%%

int yywrap() {
    return 1;
}
