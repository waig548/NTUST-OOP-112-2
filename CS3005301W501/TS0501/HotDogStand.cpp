#include "HotDogStand.h"

#include <iostream>
int HotDogStand::totalSellAmount = 0;

HotDogStand::HotDogStand(): HotDogStand(nullptr) {
}

HotDogStand::HotDogStand(const char* id): HotDogStand::HotDogStand(id, 0) {
}

HotDogStand::HotDogStand(const char* id, int amount) {
    standId = new char[std::strlen(id) + 1]{0};
    std::memcpy(standId, id, std::strlen(id));
    hotDogSellAmount = amount;
    totalSellAmount += amount;
}

HotDogStand::~HotDogStand() {
    delete[] standId;
}

void HotDogStand::justSold() {
    hotDogSellAmount++;
    totalSellAmount++;
}

void HotDogStand::print() {
    std::cout << standId << " " << hotDogSellAmount << std::endl;
}

int HotDogStand::thisStandSoldAmount() {
    return hotDogSellAmount;
}

int HotDogStand::allStandSoldAmount() {
    return totalSellAmount;
}
