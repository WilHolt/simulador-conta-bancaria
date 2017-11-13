#include "dataframe.h"
//tamanho do header para saber tamanho de colunas

/*std::istream& DataFrame::leitura(std::istream& in){
std::vector<std::string> vect;
std::string line, field;
if(!in.good()){
std::cerr << "Stream not open!!\n";
return in;
}
if(header.empty()){
std::string linha_header;
std::getline(in, linha_header);
std::istringstream input(linha_header);
while(std::getline(input, field, separador)){
header.push_back(std::make_pair(field, "null"));
}
colunas = header.size();
}

}*/
/*std::ostream & operator<< (std::ostream & output, DataFrame& db){
for(size_t i = 0; i < db.header.size(); i++){
output.width(10);
output << db.header[i].first << db.separador;
}
output << std::endl;

return output;
}*/

size_t getLinhas(std::istream& in){
	size_t linhas=0;
	while (in.eof()== false) {
		std::string buffer;
		std::getline(in, buffer);
		linhas++;
	}
	return linhas;
}

std::istream& operator>> (std::istream& in, DataFrame& db){
	db.header.clear();

	std::string field;
	std::string buffer;
	std::getline(in, buffer);
	std::istringstream input(buffer);
	int cont=0;
	//ADICIONAR HEADER
	while(std::getline(input, field, db.separador)){
		db.header.push_back(field);
		//std::cout<<db.header[cont]<<' ';
		cont++;
	}
	db.colunas = db.header.size();


	//ADICIONAR CONTAINER
	std::vector<std::string> aux;
	std::string field2;
	std::string buffer2;
	int i=0;
	while(std::getline(in, buffer2)){
		std::istringstream input2(buffer2);
		//std::cout << "\n" << '\n';
		while (getline(input2, field2, db.separador)) {

			aux.push_back(field2);
			//std::cout<<aux[i]<<"|";
			i++;
		}
		db.container.push_back(aux);
	}
	//std::cout<<i;
	db.linhas=i;
	return in;
}

std::ostream & operator<< (std::ostream & output, const DataFrame & db) {
	for(size_t i = 0; i < db.header.size(); i++) {
		output.width(2);
		output << db.header[i] << '|';
	}
	for(size_t i = 0; i < db.container.size(); i++){
		output<<"\n";
		for(size_t j = 0; j < db.container[i].size(); j++){
			output.width(2);
			if(j==db.colunas){std::cout<<"\n";}
			output <<db.container[i][j] << "|";
		}
		output<<"\n";
	}

	return output;
}
