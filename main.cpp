#include "Parser.h"
#include "Lexer.h"
int main(int argc, char **argv) {
	using namespace std;
//	cout << "work?" << endl;
	auto lex = 	new Lexer();
//	cout << "work2" << endl;

	auto l = lex->lexer(argv[1]);
//	cout << "work3" << endl;

	Parser *par = new Parser(l);
//	cout << "work4" << endl;

	par->execute();
//	cout << "work5" << endl;

	delete lex;
	delete par;
//int n=0;
//	auto c = new ConnectClientCommand("127.0.0.1", "5402");
//	c->execute("");
//	std::cin >> n;
//  	cout << "are th same:" << (typeid(*c) == typeid(ConnectClientCommand)) << endl;
	return 0;
}
