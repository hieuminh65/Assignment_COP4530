#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <vector>
#include <string>
#include <set>
#include "GraphBase.hpp"

class Graph : public GraphBase {
public:
  Graph();
  ~Graph();

  void addVertex(std::string label) override;
  void removeVertex(std::string label) override;
  void addEdge(std::string label1, std::string label2, unsigned long weight) override;
  void removeEdge(std::string label1, std::string label2) override;
  unsigned long shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path) override;

private:
  // Your data members here. For example, you could use an adjacency list to store the graph,
  // which could be a map from string labels to a list of pairs (representing edges and their weights).
  std::unordered_map<std::string, std::vector<std::pair<std::string, unsigned long>>> adjacencyList;
  std::set<std::string> vertices;
};

#endif
