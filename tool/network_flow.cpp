struct Edge;
struct Node {
	vector<Edge*> edgesOut, edgesIn ;
	bool visited;
	bool source;
	bool sink;
};
struct Edge {
	Node * a, * b;
	int capacity;
	int flow;
};
vector<Node*> nodepool;
vector<Edge*> edgepool;
Node * addNode(bool source = false, bool sink = false) {
	Node * o = new Node;
	o->visited = false;
	o->source = source;
	o->sink = sink;
	nodepool.push_back(o);
	return o;
}
Edge * getEdge(Node * a, Node * b) {
	int n = a->edgesOut.size();
	for (int i=0; i<n; i++) {
		if (a->edgesOut[i]->b == b) return a->edgesOut[i];
	}
	return NULL;
}
Edge * addEdge(Node * a, Node * b, int c = 1) {
	Edge * e = new Edge;
	e->a = a;
	e->b = b;
	e->capacity = c;
	e->flow = 0;
	a->edgesOut.push_back(e);
	b->edgesIn.push_back(e);
	edgepool.push_back(e);
	return e;
}
vector<Edge * > path;
vector<bool> reverseFlag;
int pathLength;
bool extendedPath(Node * node, int depth) {
	if (node->sink == true) {
		pathLength = depth;
		return true;
	}
	node->visited = true;
	int l1,l2;
	l1 = node->edgesOut.size();
	l2 = node->edgesIn.size();
	reverseFlag[depth] = false;
	for (int i=0; i<l1; i++) {
		Edge * y = node->edgesOut[i];
		if (y->b->visited) continue;
		if (y->flow == y->capacity) continue;
		path[depth] = y;
		if (extendedPath(y->b, depth+1)) return true;
	}
	reverseFlag[depth] = true;
	for (int i=0; i<l2; i++) {
		Edge * y = node->edgesIn[i];
		if (y->a->visited) continue;
		if (y->flow == 0) continue;
		path[depth] = y;
		if (extendedPath(y->a, depth+1)) return true;
	}
	return false;
}
int extending() {
	int m = 1000000;
	for (int i=0; i<pathLength; i++) {
		int t;
		if (reverseFlag[i]) {
			t = path[i]->flow;
		}
		else {
			t = path[i]->capacity - path[i]->flow;
		}
		if (t<m) m = t;
	}
	assert(m!=0 && m!=1000000);
	for (int i=0; i<pathLength; i++) {
		if (reverseFlag[i]) {
			path[i]->flow -= m;
		}
		else {
			path[i]->flow += m;
		}
	}
	return m;
}
void initnetwork() {
	for (int i=0; i<nodepool.size(); i++) delete nodepool[i];
	for (int i=0; i<edgepool.size(); i++) delete edgepool[i];
	nodepool.clear();
	edgepool.clear();
}
int maxFlow() {
	int n = nodepool.size();
	path.resize(n);
	reverseFlag.resize(n);
	int flow = 0;
	while(true) {
		for (int i=0; i<n; i++) {
			nodepool[i]->visited = false;
		}
		bool found = false;
		for (int i=0; i<n; i++) {
			if (! nodepool[i]->source || nodepool[i]->visited) continue;
			if (extendedPath( nodepool[i], 0)) {
				found = true;
				break;
			}
		}
		if (!found) break;
		flow += extending();
	}
	return flow;
}