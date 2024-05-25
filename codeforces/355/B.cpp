// This is a basic program on C++
//
// Try to modify and run it and check out
// the output in the terminal below.
//
// Happy coding! :-)
#include <vector>
#include <iostream>

int main() {
    int ticket1, ticket2, ticket3, ticket4;
    std::cin >> ticket1 >> ticket2 >> ticket3 >> ticket4;
    int numberOfBus, numberOfTrolley;
    std::cin >> numberOfBus >> numberOfTrolley;

    std::vector<int> busesTrips{};
    std::vector<int> trolleyTrips{};

    for (int i{0}; i < numberOfBus; i++){
        int input{};
        std::cin >> input;

        busesTrips.push_back(input);
        
    }
    for (int i{0}; i < numberOfTrolley; i++){
        int input;
        std::cin >> input;

        trolleyTrips.push_back(input);
        
    }

    int total{0};
    int busesCostTemp1{0};

    std::vector<int> busesIfTicket1{};
    
    for (int i{0}; i < busesTrips.size(); i++){
        busesIfTicket1.push_back(busesTrips[i] * ticket1);
        
    }
    for (int i{0}; i < busesTrips.size(); i++){
        if (busesIfTicket1[i] > ticket2){
            busesCostTemp1 += ticket2;
        }
        else{
            busesCostTemp1 += busesIfTicket1[i];
        }
    }

    if (busesCostTemp1 > ticket3){
        busesCostTemp1 = ticket3;
    }

    int trolleyCostTemp1{0};
    std::vector<int> trolleyIfTicket1{};

    for (int i{0}; i < trolleyTrips.size(); i++){
        trolleyIfTicket1.push_back(trolleyTrips[i] * ticket1);
    }

    for (int i{0}; i < trolleyTrips.size(); i++){
        if (trolleyIfTicket1[i] > ticket2){
            trolleyCostTemp1 += ticket2;
        }
        else{
            trolleyCostTemp1 += trolleyIfTicket1[i];
        }
    }

    if (busesCostTemp1 > ticket3){
        busesCostTemp1 = ticket3;
    }
    if (trolleyCostTemp1 > ticket3){
        trolleyCostTemp1 = ticket3;
    }

    total = trolleyCostTemp1 + busesCostTemp1;

    if (trolleyCostTemp1 + busesCostTemp1 > ticket4){
        total = ticket4;
    }

    std::cout << total;
}

