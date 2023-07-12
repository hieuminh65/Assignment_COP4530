#include "Graph.hpp"
#include <queue>
#include <limits>

Graph::Graph() {
}

Graph::~Graph() {
}

void Graph::addVertex(std::string label) {
  vertices.insert(label);
  adjacencyList[label] = std::vector<std::pair<std::string, unsigned long>>();
}

void Graph::removeVertex(std::string label) {
  vertices.erase(label);
  adjacencyList.erase(label);
  for (auto &pair : adjacencyList) {
    pair.second.erase(std::remove_if(pair.second.begin(), pair.second.end(),
                                     [label](const std::pair<std::string, unsigned long> &edge) {
                                       return edge.first == label;
                                     }),
                      pair.second.end());
  }
}

void Graph::addEdge(std::string label1, std::string label2, unsigned long weight) {
  adjacencyList[label1].push_back(std::make_pair(label2, weight));
  adjacencyList[label2].push_back(std::make_pair(label1, weight));
}

void Graph::removeEdge(std::string label1, std::string label2) {
  adjacencyList[label1].erase(std::remove_if(adjacencyList[label1].begin(), adjacencyList[label1].end(),
                                             [label2](const std::pair<std::string, unsigned long> &edge) {
                                               return edge.first == label2;
                                             }),
                              adjacencyList[label1].end());
  adjacencyList[label2].erase(std::remove_if(adjacencyList[label2].begin(), adjacencyList[label2].end(),
                                             [label1](const std::pair<std::string, unsigned long> &edge) {
                                               return edge.first == label1;
                                             }),
                              adjacencyList[label2].end());
}

unsigned long Graph::shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path) {
  // Implementation of Dijkstra's algorithm
  std::unordered_map<std::string, unsigned long> distances;
  std::unordered_map<std::string, std::string> previous;
//   std::priority_queue<std::pair<unsigned long, std::string>, std::vector<std::pair<unsigned long, std::string>>, std::greater<>> queue;
std::priority_queue<std::pair<unsigned long, std::string>, std::vector<std::pair<unsigned long, std::string>>, std::greater<std::pair<unsigned long, std::string>>> queue;

  for (const std::string &vertex : vertices) {
    if (vertex == startLabel) {
      distances[vertex] = 0;
    } else {
      distances[vertex] = std::numeric_limits<unsigned long>::max();
    }
    queue.push(std::make_pair(distances[vertex], vertex));
  }

  while (!queue.empty()) {
    std::string smallest = queue.top().second;
    queue.pop();
    if (smallest == endLabel) {
      while (previous.find(smallest) != previous.end()) {
        path.push_back(smallest);
        smallest = previous[smallest];
      }
      std::reverse(path.begin(), path.end());
      return distances[endLabel];
    }
    if (distances[smallest] == std::numeric_limits<unsigned long>::max()) {
      break;
    }
    for (const auto &neighbor : adjacencyList[smallest]) {
      unsigned long alt = distances[smallest] + neighbor.second;
      if (alt < distances[neighbor.first]) {
        distances[neighbor.first] = alt;
        previous[neighbor.first] = smallest;
        queue.push(std::make_pair(alt, neighbor.first));
      }
    }
  }
  return std::numeric_limits<unsigned long>::max();
}
