#ifndef header
#define header
#include<iostream>
#include<string>
#include<vector>
#include<set>



class node
{
public:
	node(std::string command, std::string input_file, std::string output_file) :
		m_command(command),
		m_output_list(output_file)
	{
		std::string str;

		for (int i = 0; i < input_file.size(); ++i)
		{
			if (input_file[i] != ' ')
				str.push_back(input_file[i]);
			else
			{
				m_input_list.insert(str);
				str.clear();
			}
		}

		if (str.size())
			m_input_list.insert(str);

	}
	~node()
	{
		for (int i = 0; i < m_nods.size(); ++i)
			delete m_nods[i];
	}


	std::string m_command;
	std::set<std::string> m_input_list;
	std::string m_output_list;

	std::vector<node*> m_nods;
};


class object
{
public:
	object() {}
	~object()
	{
		for (int i = 0; i < m_root.size(); ++i)
			delete m_root[i];
	}


	void create_dependecies_tree(std::vector<node>&);
	void print_dependecies();



private:
	std::vector<node*> m_root;
	void print_dependecies_helper(node*);
	void create_dependecies_tree_helper(node*&, node);
	void control_commands(std::vector<node> &);

};



#endif