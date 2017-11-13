#include "dataframe.h"
#include <fstream>

int main(){
	std::ofstream outfile;
	std::ifstream input;
	input.open("./data/data.csv");
	//ize_t linhasaux= getLinhas(input);
	DataFrame db(0,0);
	input>>db;
	//std::vector<std::string> c_name;

	//db.leitura(input);
	//imprimir(db);
	//std::cout << "At delta.csv: " << std::endl;
	std::ofstream output;
	std::cout<<db;
	//std::cout << output << '\n';

return 0;
}
