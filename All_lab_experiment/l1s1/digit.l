%%
 if { printf("\n Keywords\n"); }
 else { printf("\n keywords\n"); }
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
int main(int argC,char *argV[]){
    yylex();
    return 0 ;
}
