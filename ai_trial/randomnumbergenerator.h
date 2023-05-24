#ifndef RANDOMNUMBERGENERATOR_H
#define RANDOMNUMBERGENERATOR_H
#include <iostream>
#include <cstdlib>
#include <ctime>

class RandomNumberGenerator
{public:
    RandomNumberGenerator(int minVal, int maxVal);
    void generateRandomNumbers();
private:
    int minVal_; // 最小值
    int maxVal_; // 最大值
    int random_x;
    int random_y;
public:
    RandomNumberGenerator();
};

#endif // RANDOMNUMBERGENERATOR_H
