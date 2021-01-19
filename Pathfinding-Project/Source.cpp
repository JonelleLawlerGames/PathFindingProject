// Program to show the principals of generating a 2D grid using the neighbours algorithm
// as described here: https://royvanrijn.com/blog/2019/01/longest-path/

// Name: Jonelle Lawler
// Student ID: C00205084

#include <iostream>
#include<fstream>
#include<string>
#include"NodeData.h"
#include"Graph.h"
#include"GraphNode.h"
#include"GraphArc.h"

typedef GraphArc<NodeData, int> Arc;
typedef GraphNode<NodeData, int> Node;

void visit(Node* node)
{
	std::cout << "Visiting node: " << node->m_data.m_name << std::endl; 
}

int main()
{
	// Graph that can hold 30 nodes
	Graph<NodeData, int> graph(30);

	// Get node data
	NodeData nodeData;
	int nodeIndex = 0;
	std::ifstream myfile;

	// Create each node, and assign a name (nodeLabel) from the text file
	myfile.open("nodes.txt");
	while (myfile >> nodeData.m_name >> nodeData.m_xPos >> nodeData.m_yPos)
	{
		graph.addNode(nodeData, nodeIndex++);
	}

	myfile.close();


	// Wire up the graph by creating arcs between nodes.
	myfile.open("arcs.txt");
	std::string from, to; // these variables were ints in the example given from a previous lab. 
	int weight;
	int nodeFrom;
	int nodeTo; 


	// this function adds the nodes to the graph
	while (myfile >> from >> to >> weight)
	{
		for (int i = 0; i < 30; i++) // 30 is the size of the graph
		{
			
			if (graph.nodeIndex(i)->m_data.m_name == from)
			{
				nodeFrom = i;
				break;
			}
		}

		for (int i = 0; i < 30; i++)
		{
			if (graph.nodeIndex(i)->m_data.m_name == to)
			{
				nodeTo = i; 
				break;
			}
		}
		//std::cout << "Weight: " << weight << "From " << nodeFrom << "to " << nodeTo << std::endl;
		graph.addArc(nodeFrom, nodeTo, weight); // where node from and node to represent paths and weight is their cost 
	}
	
	myfile.close();

	// This is going to be the path from one node to another
	std::vector<Node*> path;

	// Call a* function - start, dest, visit function, record path
	graph.aStar(graph.nodeIndex(0), graph.nodeIndex(29), visit, path);

	
	std::cout << "Path: " << std::endl;
	
	// Start and end of path vector to loop through 
	auto beginIter = path.begin();
	auto endIter = path.end() - 1;

	// Output path 
	for (; endIter != beginIter; endIter--)
	{
		std::cout << (*endIter)->m_data.m_name << std::endl;
	}

	system("Pause");
}