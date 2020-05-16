#include "../include/PCA.h"
#include <iostream>
#include <fstream>
int main(int argc, char *argv[])
{
    CHNJAR003::PCA analyser;
    analyser.readInputData("./AvgRainfall_mm.txt");
    analyser.calculateCovarianceMatrix();
    analyser.calculateEigenvaluesAndVectors();
    analyser.calculateTotalVariance();
    analyser.calculateExplainedVariance();
    std::cout << analyser;

    std::cout << "Writing results to \"results.txt\".\n";
    std::ofstream resultsFile;
    resultsFile.open("results.txt");
    resultsFile << analyser;
    resultsFile.close();
    std::cout << "Results successfuly written to \"results.txt\".";
    return 0;
}