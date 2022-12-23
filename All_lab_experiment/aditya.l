%%
 ">" { printf("\n Relational Operators\n"); }
 "<" { printf("\n Relational Operators \n"); }
 "<=" { printf("\n Relational Operators \n"); }
 "=>" { printf("\n Relational Operators \n"); }
 "=" { printf("\n Relational Operators \n"); }
 "!=" { printf("\n Logical Operators \n"); }
 "&&" { printf("\n Logical Operators \n"); }
 "||" { printf("\n Logical Operators \n"); }
 "!" { printf("\n Logical Operators \n"); }
 "+" { printf("\n Arthmetic Operator\n"); }
 "-" { printf("\n Arthmetic Operator\n"); }
 "*" { printf("\n Arthmetic Operator\n"); }
 "/" { printf("\n Arthmetic Operator\n"); }
 "%" { printf("\n Arthmetic Operator\n"); }
%%

int yywrap(){ }
int main(){
    yylex();
    return 0 ;
 }