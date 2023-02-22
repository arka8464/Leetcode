class Solution {
    bool detectCycle(vector<vector<int>>& graph, vector<int>& state, int node) {

	state[node] = 1;

	for(auto& adjnode : graph[node]) {
		if(state[adjnode] == 0) {
			if(detectCycle(graph, state, adjnode)) {
				state[node] = 3;
				return true;
			}
		}
		else if(state[adjnode] != 2) {
			state[node] = 3;
			return true;
		}
	}

	state[node] = 2;
	return false;
}

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

	vector<int> state(n, 0);

	for(int i=0; i<n; i++) {
		if(state[i] == 0) {
			detectCycle(graph, state, i);
		}
	}

	vector<int> safeNodes;

	for(int i=0; i<n; i++) {
		if(state[i] == 2) {
			safeNodes.push_back(i);
		}
	}

	return safeNodes;
    }
};