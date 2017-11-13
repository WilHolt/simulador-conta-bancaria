#include "dataframe.h"

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
	db.container.clear();
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
	db.colunas =cont;


	//ADICIONAR CONTAINER

	std::string field2;
	std::string buffer2;
	//int i=0;
	int contador=0;

	while(in>>buffer2){
		std::vector<std::string> aux;
		std::stringstream input2(buffer2);
		while (std::getline(input2, field2, db.separador)) {
			aux.push_back(field2);
			contador++;
		}
		db.container.push_back(aux);
	}
	/*while(!in.eof()){
	std::vector<std::string> aux;
	std::getline(in, buffer2);
	contador++;
	std::istringstream input2(buffer2);
	while (getline(input2, field2, db.separador)) {
	aux.push_back(field2);
	std::cout<<aux[i]<<"|";
	i++;
}
if(i>0){
db.container.push_back(aux);
}
}*/
db.linhas=contador;

std::cout<<db.linhas<<"\n";
std::cout<<db.header.size()<<"\n";

return in;
}

std::ostream & operator<< (std::ostream & output, const DataFrame & db) {
	//mostrar header
	for(size_t i = 0; i < db.header.size(); i++) {
		output.width();
		output << db.header[i] << '|';
	}
	//mostrar container
	for(auto& row:db.container){
		std::cout<<"\n";
		size_t it=0;
		for(auto& col:row){
			it++;

			std::cout<<col<<"|";
		}
		std::cout << '\n';
	}

	return output;
}

size_t DataFrame::getposcolbyname(std::string v_name ){
	std::vector<std::string>::iterator it;
	int i=0;
	if(!header.empty()){
		for(it =header.begin(); it != header.end(); it++){
			i++;
			std::cout<<*it;
			if(v_name.compare(*it) == 0){

				return i;
			}
		}

	}else { return 0;}
}
