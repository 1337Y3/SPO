#include "Lexer.h"
#include "Parser.h"
#include "Interpreter.h"
#include "Stack_machine.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "ѕрактическое задание є4\n\n";
	std::cout << "¬ведите им€ *.txt файла \n(файл должен располагатьс€ в одной папке с программой)\n";
	std::string fname;
	std::cin >> fname;

	Lexer lexer;
	std::vector<token_pair> tokens = lexer.getTokens(fname);

	if (!tokens.empty())
	{
		std::cout << "\nЋексер не вы€вил ошибок.";

		Parser parser;
		bool correct = parser.checkSyntax(tokens);
		if (correct)
		{
			std::cout << "ѕарсер не вы€вил ошибок.\n\n";

			Interpreter interpreter;
			std::vector<token_pair> rpn = interpreter.get_reverse_polish_notation(tokens);

			Stack_machine stack_machine;
			std::vector<token_pair> exe = stack_machine.execute_program(rpn);

			for (int i = 0; i < exe.size(); ++i)
			{
				std::cout << std::left << std::setw(6) << exe[i].name << exe[i].value << "\n";
			}
		}
		else
		{
			std::cout << "\nѕарсер вы€вил ошибку.\n";
		}
	}
	else
	{
		std::cout << "\nЋексер вы€вил ошибку.\n";
	}

	
	//interpreter.get_reverse_polish_notation(tokens);

	//std::cout << "\n";
	//for (int i = 0; i < rpn.size(); ++i)
	//{
	//	//std::cout << std::left << std::setw(3) << i + 1 << rpn[i] << "\n";
	//}


	

	std::cout << "\n";
	system("pause");
	return 0;
}





/*std::cout << "\n\n–езультат работы лексера:\n\n";
for (int i = 0; i < tokens.size(); ++i)
{
std::cout << std::left << std::setw(18) << tokens[i].name << " " << tokens[i].value << "\n";
}*/