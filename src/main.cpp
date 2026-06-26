#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

struct Intersection{
    int id;
    std::string name;
};

int main() {
    Intersection inter1 = {1, "Huhnerpostenn"};
    Intersection inter2 = {2, "haakestrasse"};

    std::vector<Intersection> intersections;
    intersections.push_back(inter1);
    intersections.push_back(inter2);

    for (const auto& item : intersections) {
        std::cout << "Intersection ID: " << item.id 
                  << ", Name: " << item.name 
                  << "\n ";
    }

    return 0;
}