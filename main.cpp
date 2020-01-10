#include "Parser.h"
#include "Lexer.h"
#include <sstream>
//
//std::vector<std::string> split2(const std::string &s, char delimiter) {
//	std::vector<std::string> tokens;
//	std::string token;
//	std::istringstream tokenStream(s);
//	while (std::getline(tokenStream, token, delimiter)) {
//		tokens.push_back(token);
//	}
//	return tokens;
//}

int main(int argc, char **argv) {
	using namespace std;
	auto lex = 	new Lexer();

	auto l = lex->lexer(argv[argc - 1]);

	Parser *par = new Parser(l);

	par->execute();

	delete lex;
	delete par;
////int n=0;
////	auto c = new ConnectClientCommand("127.0.0.1", "5402");
////	c->execute("");
////	std::cin >> n;
////  	cout << "are th same:" << (typeid(*c) == typeid(ConnectClientCommand)) << endl;
//	std::string t = "0.0,0.0,0.0\n0.0,69.0,0.0";
//	std::string t2 = "\n0.0,0.0,0.0\n0.0,73.0,0.0\n";
//	std::string t3 = "";
//	std::vector<std::string> sub_n = split2(t, '\n');
//	std::vector<std::string> sub_n2 = split2(t2, '\n');
//	std::vector<std::string> sub3 = split2(t3, ',');
//	std::cout << sub3.size() << endl;
//	std::cout << stod(sub3[0]) << endl;
//
//	for (int kI = 0; kI < sub_n2.size(); ++kI) {
//		std::cout<< "arg: " << sub_n2[kI] << std::endl;
//
//	}
//

	return 0;
}
