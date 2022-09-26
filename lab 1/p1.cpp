#include<bits/stdc++.h>  
using namespace std;
 
int isKeyword(char word[]){
   char keywords[32][10] = {"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};
   int i, flag = 0;
   for(i = 0; i < 32; ++i){
      if(strcmp(keywords[i], word) == 0){
         flag = 1;
         break;
      }
   }
   return flag;
}

int main(){
   char ch, word[15], operators[] = "+-*/%=";
   ifstream fin("file.txt");
   int i,j=0;
   if(!fin.is_open()){
      cout<<"error while opening the file\n";
      exit(0);
   }
   
   while(!fin.eof()){
      ch = fin.get(); 
      for(i = 0; i < 6; ++i){
         if(ch == operators[i])
            cout<<ch<<" is operator\n";
      }
      if (isalnum(ch)){
         word[j++] = ch;
      } else if ((ch == ' ' || ch == '\n') && (j != 0)){
         word[j] = '\0';
         j = 0;
         
         if(isKeyword(word) == 1)
            cout<<word<<" is keyword\n";
         else
            cout<<word<<" is identifier\n";
      }
   }
   fin.close();
    return 0;
}