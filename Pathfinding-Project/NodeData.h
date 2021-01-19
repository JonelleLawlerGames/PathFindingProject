#pragma once
#include  <string>

// ---------------------------------------------------------------------
//  Name:           NodeData
//  Description:    A simple struct to encapsulate all the node data.
//                  Add or remove fields as required.               
// ---------------------------------------------------------------------
struct NodeData
{
	std::string m_name;
	int m_cost; 

	// Node positions
	int m_xPos;
	int m_yPos;

	// Heuristic value
	int m_h = { 0 }; // distance to goal
	int m_g = { 0 }; // cost to goal 
};


