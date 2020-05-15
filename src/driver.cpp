#include "../include/PCA.h"
#include <iostream>
int main(int argc, char *argv[])
{
    CHNJAR003::PCA temp;
    temp.readInputData("./AvgRainfall_mm.txt");
    temp.calculateCovarianceMatrix();
    temp.calculateEigenvaluesAndVectors();
    temp.calculateTotalVariance();
    std::cout << temp;
}