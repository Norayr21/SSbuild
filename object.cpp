#include "object.h"

bool find(const std::string &input_file, const std::string &output_file) 
{
	for (int i = 0, j = 0; i < input_file.size(); ++i)
	{
		if (input_file[i] == output_file[j])
			++j;
		else
			j = 0;

		if (j == output_file.size())
			return true;
	}

	return false;
}

void object::create_graph_helper(node *& newroot, node ob)
{
	if (find(newroot->m_input_file, ob.m_output_file))
		newroot->m_nods.push_back(new node(ob));


	for (int i = 0; i < newroot->m_nods.size(); ++i)
		create_graph_helper(newroot->m_nods[i], ob);
}

void object::create_graph(const std::vector<node>& vec)
{
	m_root = new node(vec[vec.size() - 1]);

	for (int i = vec.size() - 2; i >= 0; --i)
		create_graph_helper(m_root, vec[i]);
}

void object::print_in_level_helper(node * newroot)
{
	std::cout << newroot->m_command << '\n';
	if (newroot->m_nods.size() == 0)
		std::cout << "Does not have dependency\n";
	else
	{
		std::cout << "Have dependency : \n";
		for (int i = 0; i < newroot->m_nods.size(); ++i)
		{
			std::cout << i + 1 << ")  command     -> " << newroot->m_nods[i]->m_command << '\n';
			std::cout << "    input_file  -> " << newroot->m_nods[i]->m_input_file << '\n';
			std::cout << "    output_file -> " << newroot->m_nods[i]->m_output_file << "\n\n";

		}
	}

	std::cout << "\n\n";
	for (int i = 0; i < newroot->m_nods.size(); ++i)
		print_in_level_helper(newroot->m_nods[i]);
}

void object::print_in_level()
{
	if (m_root == nullptr)
		return;

	print_in_level_helper(m_root);
}
