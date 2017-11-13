#include "dataframe.h"
#include <fstream>

int main(){
	DataFrame db(0,0);
	std::ofstream outfile;
	std::ifstream input;
	input.open("./data/delta.csv");
	std::string nome ("1");
	size_t posicao = db.getposcolbyname(nome);
	std::cout << "posição: " << posicao<<"\n";

	input>>db;

	std::ofstream output;
	std::cout<<db;


return 0;
}
