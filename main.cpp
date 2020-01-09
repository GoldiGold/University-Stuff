#include "Parser.h"
#include "Lexer.h"
int main(int argc, char** argv) {
  using namespace std;
  auto lex = new Lexer();
  auto l = lex->lexer(argv[1]);
  Parser* par = new Parser(l);
  par->execute();
  delete lex;
  delete par;
  return 0;
}
