#include <iostream>
#include <vector>
#include <limits>

struct Car {
    std::string size;
    int seats;
    int cost;
};

void findOptimalCost(int seatRequirement) {
    std::vector<Car> cars = {
        {"Small", 5, 5000},
        {"Medium", 10, 8000},
        {"Large", 15, 12000}
    };

    int minCost = std::numeric_limits<int>::max();
    std::vector<std::pair<std::string, int>> optimalCombination;

    for (int large = 0; large <= seatRequirement / cars[2].seats + 1; ++large) {
        for (int medium = 0; medium <= seatRequirement / cars[1].seats + 1; ++medium) {
            for (int small = 0; small <= seatRequirement / cars[0].seats + 1; ++small) {
                int totalSeats = large * cars[2].seats + medium * cars[1].seats + small * cars[0].seats;
                int totalCost = large * cars[2].cost + medium * cars[1].cost + small * cars[0].cost;

                if (totalSeats >= seatRequirement && totalCost < minCost) {
                    minCost = totalCost;
                    optimalCombination = {
                        {"L", large},
                        {"M", medium},
                        {"S", small}
                    };
                }
            }
        }
    }

    if (minCost == std::numeric_limits<int>::max()) {
        std::cout << "No valid combination found to fulfill the seat requirement." << std::endl;
    } else {
        for (const auto& combo : optimalCombination) {
            if (combo.second > 0) {
                std::cout << combo.first << " x " << combo.second << std::endl;
            }
        }
        std::cout << "Total = PHP " << minCost << std::endl;
    }
}

int main() {
    int seatRequirement;
    std::cout << "Please input number (seat): ";
    std::cin >> seatRequirement;

    findOptimalCost(seatRequirement);

    return 0;
}
