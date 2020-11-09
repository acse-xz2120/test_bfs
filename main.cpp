#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <time.h>
#include "Graph.h"
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


void read_graph_file(std::ifstream& file, Graph &g)
{
  std::string buffer;
  int idx = 0;
  while(!file.eof())
  {
    buffer.clear();
    std::getline(file, buffer);
    std::stringstream parse(buffer);
    std::string pair, skip;
    while(std::getline(std::getline(parse, skip, '('), pair, ')')) {
        std::string delimiter = ",";
        std::string token1 = pair.substr(0, pair.find(delimiter));
        std::string token2 = pair.substr(pair.find(delimiter)+1, pair.length()-1);
		int a = std::stoi(token1);
		int b = std::stoi(token2);
		g.addEdge(a, b);
		g.addEdge(b, a);
    }
  }
} 

int main(int argc,char *argv[])
{  
	Graph g(100000);
    std::ifstream f(argv[1]);
    read_graph_file(f, g);
	// g.getAdj();
	freopen("ans.txt", "w", stdout);
	// clock_t start = clock();
	g.BAGPBFS(0);
	// clock_t end = clock();
	// cout << "Process time: " << (end - start) << " ms" << endl;
}