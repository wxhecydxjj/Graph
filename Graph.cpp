#include <iostream>
#include <string>
#include <stack>
#include <queue>


struct arcNode
{
	int num;
	arcNode *next;
};

template <class DataType>
struct vertexNode
{
	bool is_Visited;
	DataType d;
	arcNode *firstEdge;
};

template <class DataType>
class Graph
{
public:
	Graph(){};
	~Graph(){};
	Graph(DtaaType d[], int length, int arcNum);
	void DFSTraverse(int v, int length);    //深度优先遍历
	void BFSTraverse(int v, int length);    //广度优先遍历
private:
	vertexNode adjList[Maxsize];

};


//length为结点数目，arcNum为边的数目
template <class DataType>
Graph::Graph(DataType d[], int length, int arcNum)
{
	int i = 0, j, k;
	while (i<length)
	{
		adjList[i].d = d[i];
		adjList[i].firstEdge = NULL;
		i++;
	}

	for (i = 0; i < 2 * arcNum; i++)
	{
		cin >> j >> k;
		arcNode *s;
		s = new arcNode;
		s->num = k;
		s->next = adjList[j].firstEdge;
		adjList[j].firstEdge = s;
	}
}

template <class DataType>
void Graph::DFSTraverse(int v, int length)
{
	int k = 0;
	while (k<length)
	{
		adjList[k].is_Visited = false;
		k++;
	}
	stack<int> Stack;
	arcNode *p;
	Stack.push(v);
	adjList[v].is_Visited = true;
	/*
	当栈非空时：
	弹出栈顶元素并输出;
	对于已经弹出栈顶元素的所在的链表里的每个元素：
	如果没有被访问过，入栈
	*/
	while (!Stack.empty())
	{
		//temp变量用于a获取栈顶元素
		int temp = Stack.top();
		adjList[temp].d.Print();         //Print()为d的一个方法，用于输出
		Stack.pop();
		p = adjList[temp].firstEdge;
		while (p)
		{
			
			if (!adjList[p->num].is_Visited)
			{
				Stack.push(p->num);
				adjList[p->num].is_Visited = true;
			}
			p = p->next;
		}
	}
}

template <class DataType>
void Graph::BFSTraverse(int v, int length)
{
	int k = 0;
	while (k<length)
	{
		adjList[k].is_Visited = false;
		k++;
	}
	queue<int> Queue;
	arcNode *p;
	Queue.push(v);
	adjList[v].is_Visited = true;
	/*
	当队列非空时：
	对队首元素所在的链表里的每个元素：
	如果没有被访问，入队
	输出队首元素
	队首元素出队
	*/
	while (!Queue.empty())
	{
		//将队首元素的链表全部入队
		if (adjList[Queue.front()].firstEdge)
		{
			p = adjList[Queue.front()].firstEdge;
			while (p)
			{
				//如果没有被访问过，说明可以入队
				if (!adjList[p->num].is_Visited)
				{
					Queue.push(p->num);
					adjList[p->num].is_Visited = true;
				}
				p = p->next;
			}
		}

		//出队操作
		adjList[Queue.front()].d.Print();
		Queue.pop();
	}
}
