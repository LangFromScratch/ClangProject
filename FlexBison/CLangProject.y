%{
#include "../CLangProject/proc.h"
#define YYDEBUG 1
extern int yylex(void);
extern char *yytext;
int yyerror(char const *str){
    extern int gLine;
    fprintf(stderr,"%s, line: %d, near %s\n",str, gLine, yytext);
    return 0;
}
%}
%code requires {
#include "../CLangProject/proc.h"
}
%union {
    clg::Expression* pExpression;
    clg::Statement* pStatement;
    clg::StatementList* pStatementList;
    clg::Declaration* pDeclaration;
    clg::DeclarationList* pDeclarationList;
    clg::ParameterList* pParameterList;
    clg::Root* pRoot;
}
%token IDENTIFIER INT_LITERAL DMP  INT_TYPE SEMICOLON 
%token LC RC LP RP
%type <pExpression> expression intliteral_expression identifier_expression postfix_expression
%type <pStatementList> statement_list
%type <pStatement>  dump_statement expression_statement compound_statement statement
%type <pDeclaration> declaration
%type <pDeclarationList> declaration_list
%type <pRoot> root
%type <pParameterList> parameter_list
%%
root
    : declaration_list
    {
        $$ = clg::StackMachine::get()->addRootDeclarationList($1);
    }
    ;
declaration_list
    : declaration
    {
        $$ = clg::StackMachine::get()->createDeclarationList($1);
    }
    | declaration_list declaration
    {
        $$ = clg::StackMachine::get()->createDeclarationList($1,$2);
    }
    ;
declaration
    : INT_TYPE identifier_expression LP parameter_list RP compound_statement
    {
        $$ = clg::StackMachine::get()->createIntFunctionDeclaration($2,$6);
    }
    ;
parameter_list
    : /*empty*/
    {
        $$ = clg::StackMachine::get()->createParameterList();
    }
    ;
statement_list
    : statement
    {
        $$ = clg::StackMachine::get()->createStatementList($1);
    }
    | statement_list statement
    {
        $$ = clg::StackMachine::get()->createStatementList($1,$2);
    }
    ;
statement
    : dump_statement
    | compound_statement
    | expression_statement
    ;
expression_statement
    : expression SEMICOLON
    {
        $$ = clg::StackMachine::get()->createExpressionStm($1);
    }
    ;
dump_statement
    :DMP expression SEMICOLON
    {
        $$ = clg::StackMachine::get()->createDumpStm($2);
    }
    ;
compound_statement
    : LC RC
    {
        $$ = clg::StackMachine::get()->createCompoundStatement();
    }
    | LC statement_list RC
    {
        $$ = clg::StackMachine::get()->createCompoundStatement($2);
    }
    ;
expression
    :intliteral_expression
    |identifier_expression
    |postfix_expression 
    ;
postfix_expression
    : identifier_expression LP  RP
    {
        $$ = clg::StackMachine::get()->createFunctionCallExp($1);
    }
    ;
identifier_expression
    : IDENTIFIER
    {
        $$ = clg::StackMachine::get()->createIdentifierExp(yytext);
    }
    ;
intliteral_expression
    : INT_LITERAL
    {
       $$ = clg::StackMachine::get()->createIntLiteralExp(yytext);
    }
    ;
%%


/*
int main(void)
{
    extern int yyparse(void);
    extern FILE *yyin;

    yyin = stdin;
    if (yyparse()) {
        fprintf(stderr, "Error ! Error ! Error !\n");
        exit(1);
    }
}
*/