#include "randomnumbergenerator.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

RandomNumberGenerator::RandomNumberGenerator( int minVal ,int  maxVal):minVal_(minVal), maxVal_(maxVal) {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // 设置随机数种子为当前时间,并确定随机数生成的范围
}
void RandomNumberGenerator::generateRandomNumbers() {
    random_x=std::rand() % (maxVal_ - minVal_ + 1) + minVal_;
    random_y=std::rand() % (maxVal_ - minVal_ + 1) + minVal_;
}//生成随机坐标
