%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int yylex(); // Declare the lexer function
extern char* yytext;
extern FILE* yyin;
extern int yyparse();
extern int yylineno;
void yyerror(const char* msg) {
 fprintf(stderr, "Error at line %d: %s\n", yylineno, msg);
 exit(1);
}
%}
%union {
 char* str;
}
%token <str> IDENTIFIER
%token <str> NUMBER
%token FOR WHILE IF ELSE
%token <str> LPAREN RPAREN LBRACE RBRACE SEMICOLON
%left '+' '-'
%left '*' '/'
%start program
%%
program: statement
 | program statement
 ;
statement: for_loop
 | while_loop
 | if_else
 | IDENTIFIER '=' expr
 ;
for_loop: FOR LPAREN expr SEMICOLON expr SEMICOLON expr RPAREN LBRACE program RBRACE
 {
 // Action for for loop
 printf("For loop found.\n");
 }
 ;
while_loop: WHILE LPAREN expr RPAREN LBRACE program RBRACE
 {
 // Action for while loop
 printf("While loop found.\n");
 }
 ;
if_else: IF LPAREN expr RPAREN LBRACE program RBRACE
 {
 // Action for if statement
 printf("If statement found.\n");
 }
 | IF LPAREN expr RPAREN LBRACE program RBRACE ELSE LBRACE program RBRACE
 {
 // Action for if-else statement
 printf("If-else statement found.\n");
 }
 ;
expr: IDENTIFIER
 | NUMBER
 | expr '+' expr
 | expr '-' expr
 | expr '*' expr
 | expr '/' expr
 | LPAREN expr RPAREN
 ;
%%
int main() {
 yyin = fopen("input_code.c", "r"); // Replace "input_code.c" with the path to your input code file.
 if (!yyin) {
 fprintf(stderr, "Error opening input file.\n");
 return 1;
 }
 yyparse();
 fclose(yyin);
 return 0;
}
