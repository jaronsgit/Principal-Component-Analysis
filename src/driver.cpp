#include "../include/PCA.h"

int main(int argc, char *argv[])
{
    CHNJAR003::PCA temp;
    temp.readInputData("./AvgRainfall_mm.txt");
    temp.calculateCovarianceMatrix();
}