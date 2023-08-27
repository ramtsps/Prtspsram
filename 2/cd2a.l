%{
#include<stdio.h>
%}
%%
if|else|while|int|switch|for {printf("%s is a keyword",yytext);}
[a-z|A-Z]([a-z|A-Z]|[0-9])* {printf("%s is an identifier",yytext);}
[0-9]* {printf("%s is a number",yytext);}
%%
int main()
{
yylex();
return 0;
}
int yywrap()
{
}