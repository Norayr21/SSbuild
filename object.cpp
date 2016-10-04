#include "object.h"



void object::create_dependecies_tree_helper(node *& newroot, node ob)
{
	for (int i = 0; i < newroot->m_nods.size(); ++i)
		create_dependecies_tree_helper(newroot->m_nods[i], ob);

	if (newroot->m_input_list.find(ob.m_output_list) != newroot->m_input_list.end())
		newroot->m_nods.push_back(new node(ob));
}


void object::create_dependecies_tree(std::vector<node>& vec)
{
	control_commands(vec);

	for (int i = 0; i < m_root.size(); ++i)
		for (int j = vec.size() - 1; j >= 0 ; --j)
			create_dependecies_tree_helper(m_root[i], vec[j]);
}


void object::print_dependecies_helper(node * newroot)
{
	std::cout << newroot->m_output_list<< " : ";

	for (int i = 0; i < newroot->m_nods.size(); ++i)
		std::cout  << newroot->m_nods[i]->m_output_list << " ";

	std::cout << "\n\n";

	for (int i = 0; i < newroot->m_nods.size(); ++i)
		print_dependecies_helper(newroot->m_nods[i]);
}


void object::print_dependecies()
{
	for (int i = 0; i < m_root.size(); ++i)
		print_dependecies_helper(m_root[i]);
}


void object::control_commands(std::vector<node>& vec)
{
	std::vector<node> files_1;  //cpp_files
	std::vector<node> files_2; //obj_files


	for (int i = 0; i < vec.size(); ++i)
	{
		bool flag = true;

		for (int j = 0; j < vec.size() && flag; ++j)
			if (i != j && vec[j].m_input_list.find(vec[i].m_output_list) != vec[j].m_input_list.end())
				flag = false;

		if (flag)
			m_root.push_back(new node(vec[i]));
	}


	for (int i = 0; i < m_root.size(); ++i)
	{
		for (int j = 0; j < vec.size(); ++j)
			if (m_root[i]->m_input_list.find(vec[j].m_output_list) != m_root[i]->m_input_list.end())
				files_2.push_back(vec[j]);
	}




	for (int i = 0; i < files_2.size(); ++i)
	{
		for (int j = 0; j < vec.size(); ++j)
			if (files_2[i].m_input_list.find(vec[j].m_output_list) != files_2[i].m_input_list.end())
				files_1.push_back(vec[j]);
	}


	vec.clear();

	for (int i = 0; i < files_1.size(); ++i)
		vec.push_back(files_1[i]);

	for (int i = 0; i < files_2.size(); ++i)
		vec.push_back(files_2[i]);

}