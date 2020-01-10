#include "Parser.h"
#include "Lexer.h"
#include <sstream>

// std::vector<std::string> split2(const std::string &s, char delimiter) {
// 	std::vector<std::string> tokens;
// 	std::string token;
// 	std::istringstream tokenStream(s);
// 	while (std::getline(tokenStream, token, delimiter)) {
// 		tokens.push_back(token);
// 	}
// 	return tokens;
// }

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
////int n=0;
////	auto c = new ConnectClientCommand("127.0.0.1", "5402");
////	c->execute("");
////	std::cin >> n;
////  	cout << "are th same:" << (typeid(*c) == typeid(ConnectClientCommand)) << endl;
//	std::string t = "0.0,0.0,0.0\n0.0,69.0,0.0";
//	std::string t2 = "\n0.0,0.0,0.0\n0.0,73.0,0.0\n";
//	std::vector<std::string> sub_n = split2(t, '\n');
//	std::vector<std::string> sub_n2 = split2(t2, '\n');
//	for (int kI = 0; kI < sub_n2.size(); ++kI) {
//		std::cout<< "arg: " << sub_n2[kI] << std::endl;
//
//	}
//

	return 0;
}
