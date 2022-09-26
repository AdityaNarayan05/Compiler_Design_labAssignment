%%
^[0-9]* printf("DIGIT");
^[^0-9]|[0-9]*[a-zA-Z] printf("Not Digit");
end return 0;
%%
int yywrap(){}
int main(int argc,char **argv){
    yylex();
    return 0;
}