#pragma once

#include <string>
#include <vector>
#include <unordered_map>

namespace optimizer {

    // A road is a directed connection FROM one intersection TO another
    // we store it from the perspective of the source node

    struct Intersection {
        int id;
        std::string name;
    };

    struct Road {
        int to_id; // ID of the intersection this road leads to
        float distance_km; // Distance in kilometers
    };

    class City {
        public: 
            // Constructor: every city needs a name
            explicit City(std::string& name); // why explicit? to avoid implicit conversions from string to City

            // Add an intersection to the city
            void addIntersection(int id, const std::string& name);

            // Add a road between two intersections 
            void addRoad(int from_id, int to_id, float distance_km);

            // Print the full map to the console (const: doesn't modify anything)
            void printMap() const;

            // Getters
            const std::string& getName() const;
            const std::unordered_map<int, std::vector<Road>>& getAdjacency() const;
            const std::unordered_map<int, Intersection>& getIntersections() const;
            
        private: // Callers can read the data but not modify it directly, they must use the public methods
            std::string m_name; // Name of the city
            std::unordered_map<int, Intersection> m_intersections; // Map of intersections by ID id -> Intersection
            std::unordered_map<int, std::vector<Road>> m_adjacency; // Adjacency list to represent the graph id -> list of roads
    };
} // namespace optimizer