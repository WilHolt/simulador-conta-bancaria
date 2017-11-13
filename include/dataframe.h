#ifndef _DATAFRAME_H
#define _DATAFRAME_H

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <sstream>
#include <fstream>
#include <algorithm>

class DataFrame{
public:
	std::vector< std::string > header;
	std::vector<std::vector<std::string> > container;
	size_t linhas;
	size_t colunas;
	char separador = ',';
public:
		size_t getposcolbyname(std::string v_name);
	DataFrame(size_t linhas, size_t colunas){
		header.resize(linhas);
		container.resize(linhas);
		for(size_t it = 0; it < linhas; it++){
			container[it].resize(colunas);
		}
	}


	friend std::istream& operator>> (std::istream& in, DataFrame& db);
	friend std::ostream & operator<< (std::ostream & output, const DataFrame & db);
};

size_t getLinhas(std::istream& in);
#endif
