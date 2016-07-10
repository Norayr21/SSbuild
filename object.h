#ifndef header
#define header
#include<iostream>
#include<string>
#include<vector>
#include<queue>


bool find(const std::string &, const std::string &);


class node
{
public:
	node(std::string command, std::string input_file, std::string output_file) :
		m_command(command),
		m_input_file(input_file),
		m_output_file(output_file)
	{}
	~node()
	{
		for (int i = 0; i < m_nods.size(); ++i)
			delete m_nods[i];
	}


	std::string m_command;
	std::string m_input_file;
	std::string m_output_file;

	std::vector<node*> m_nods;
};


class object
{
private:
	node* m_root;
	void create_graph_helper(node*&, node);
	void print_in_level_helper(node*);
	

public:
	object() :
		m_root(nullptr)
	{}
	~object()
	{
		delete m_root;
	}


	void create_graph(const std::vector<node>&);
	void print_in_level();
};



#endif