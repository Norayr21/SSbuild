#include"object.h"



int main()
{
	node command1("g++ -c main.cpp header.h", "main.cpp header.h", "main.o");
	node command2("g++ -c header.cpp header.h", "header.cpp header.h", "header.o");
	node command3("g++ main.o header.o -o main", "main.o header.o", "main");


	std::vector<node> ob;
	ob.push_back(command3);
	ob.push_back(command1);
	
	ob.push_back(command2);
	
	object tree;
	tree.create_dependecies_tree(ob);
	tree.print_dependecies();


	return 0;
}

//
//#include <iostream>
//#include <ctime>
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <cerrno>
//#include <cstring>
//
//int main()
//{
//	struct stat fileInfo;
//
//	if (stat("D:\\1.txt", &fileInfo) != 0)
//	{  // Use stat( ) to get the info
//		return(EXIT_FAILURE);
//	}
//
//
//	std::cout << "Created       : " <<
//		std::ctime(&fileInfo.st_ctime);         // Creation time
//
//
//	std::cout << "Modified      : " <<
//		std::ctime(&fileInfo.st_mtime);         // Last mod time
//
//	return 0;
//}
