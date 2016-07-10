#include"object.h"

int main()
{
	node command1("moc object.h -> moc_object.cpp", "object.h", "moc_object.cpp");
	node command2("moc header.h  -> moc_header.cpp", "header.h", "moc_header.cpp");

	node command3("g++ moc_header.cpp -o moc_header.o -c", "moc_header.cpp", "moc_header.o");
	node command4("g++ object.cpp -o object.o -c", "object.cpp", "object.o");
	node command5("g++ main.cpp -o main.o -c", "main.cpp", "main.o");
	node command6("g++ moc_object.cpp -o moc_object.o -c", "moc_object.cpp", "moc_object.o");

	node command7("g++ main.o object.o moc_object.o moc_header.o -o object.exe", "main.o object.o moc_object.o moc_header.o", "object.exe");



	std::vector<node>  vec;
	vec.push_back(command1);
	vec.push_back(command2);
	vec.push_back(command3);
	vec.push_back(command4);
	vec.push_back(command5);
	vec.push_back(command6);
	vec.push_back(command7);



	object ob;
	ob.create_graph(vec);
	ob.print_in_level();

	return 0;
}