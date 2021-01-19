#pragma once
#include"NodeData.h"
#include"GraphNode.h"
#include"GraphArc.h"


template<class NodeType, class ArcType>
class CostCompare
{
public:
	bool operator()(GraphNode<NodeType, ArcType>* n1, GraphNode<NodeType, ArcType>* n2)
	{
		// For heuristics
		return(( n1->m_data.m_h + n1->m_data.m_g) > (n2->m_data.m_h + n2->m_data.m_g)); 
	}
};
