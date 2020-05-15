#include "../include/PCA.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <vector>
namespace CHNJAR003
{
    PCA::PCA(void)
    {
    }
    PCA::~PCA(void)
    {
    }
    void PCA::readInputData(std::string fileName)
    {

        std::string line;
        std::ifstream dataFile(fileName);

        std::cout << fileName << std::endl;

        std::vector<std::string> data;

        int lineCount = 0;
        if (dataFile.is_open())
        {
            while (getline(dataFile, line))
            {

                if (lineCount % 3 != 0)
                {
                    if (lineCount % 3 == 1)
                    {
                        //std::cout << "Jan: " << line << std::endl;
                        januaryData.push_back(std::stod(line));
                    }
                    else
                    {
                        //std::cout << "July: " << line << std::endl;
                        julyData.push_back(std::stod(line));
                    }

                    data.push_back(line);
                }
                ++lineCount;
            }
            dataFile.close();

            for (int i = 0; i < januaryData.size(); ++i)
            {
                dataset.push_back(Eigen::Vector2d(januaryData[i], julyData[i]));
            }
        }
        else
        {
            std::cout << "Could not open data file for reading." << std::endl;
        }
        //std::copy(januaryData.begin(), januaryData.end(), std::ostream_iterator<double>(std::cout, ", "));
        //std::cout << std::endl << std::endl;
        //std::copy(julyData.begin(), julyData.end(), std::ostream_iterator<double>(std::cout, ", "));
    }

    void PCA::calculateCovarianceMatrix()
    {
        Eigen::Vector2d mean(0.0, 0.0);

        //std::cout << "original data:\n";
        for (auto const &dataPoint : dataset)
        {
            mean += dataPoint;
            //std::cout << dataPoint << std::endl;
        }

        int numDataPoints = dataset.size();
        mean /= numDataPoints;

        Eigen::MatrixXd meanSubtractedMatrix(2, numDataPoints);

        for (int i = 0; i < numDataPoints; ++i)
        {
            meanSubtractedMatrix.col(i) = (dataset[i] - mean);
        }

        //std::cout << meanSubtractedMatrix * meanSubtractedMatrix.transpose() / (numDataPoints - 1) << std::endl;
    }
} // namespace CHNJAR003