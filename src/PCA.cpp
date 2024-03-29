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

                        januaryData.push_back(std::stod(line));
                    }
                    else
                    {

                        julyData.push_back(std::stod(line));
                    }

                    data.push_back(line);
                }
                ++lineCount;
            }
            dataFile.close();

            //Store the data as two-dimensional data points
            for (int i = 0; i < januaryData.size(); ++i)
            {
                dataset.push_back(Eigen::Vector2d(januaryData[i], julyData[i]));
            }
        }
        else
        {
            std::cout << "Could not open data file for reading." << std::endl;
        }
    }

    void PCA::calculateCovarianceMatrix()
    {
        Eigen::Vector2d mean(0.0, 0.0); //Mean 2D data point - first value holds Jan mean and second holds July mean

        for (auto const &dataPoint : dataset)
        {
            mean += dataPoint;
        }

        int numDataPoints = dataset.size();
        mean /= numDataPoints;

        Eigen::MatrixXd meanSubtractedMatrix(2, numDataPoints); //2 rows and 64 columns in the case of this dataset - make calculation easier to follow

        for (int i = 0; i < numDataPoints; ++i)
        {
            meanSubtractedMatrix.col(i) = dataset[i] - mean;
        }

        covarianceMatrix = meanSubtractedMatrix * meanSubtractedMatrix.transpose() / (numDataPoints - 1);
    }

    void PCA::calculateEigenvaluesAndVectors(void)
    {
        Eigen::EigenSolver<Eigen::MatrixXd> eigenSolver(covarianceMatrix);

        componentEigenvalues.push_back(eigenSolver.eigenvalues().real()[0]);
        componentEigenvalues.push_back(eigenSolver.eigenvalues().real()[1]);

        componentEigenvectors.push_back(eigenSolver.eigenvectors().real().col(0));
        componentEigenvectors.push_back(eigenSolver.eigenvectors().real().col(1));
    }

    void PCA::calculateTotalVariance(void)
    {
        totVariance = covarianceMatrix(0, 0) + covarianceMatrix(1, 1); //Sum of the variances of the features along the diagonal of the covariance matrix
    }

    void PCA::calculateExplainedVariance(void)
    {
        double PC1Eigenval = std::max(componentEigenvalues[0], componentEigenvalues[1]);
        double PC2Eigenval = std::min(componentEigenvalues[0], componentEigenvalues[1]);

        explainedVariance.push_back((PC1Eigenval / totVariance) * 100);
        explainedVariance.push_back((PC2Eigenval / totVariance) * 100);
    }

    std::ostream &operator<<(std::ostream &os, const PCA &pca)
    {

        os << "1. What are the Eigenvalues for the principal components 1 and 2?\n\n";
        os << "Eigenvalue 1:\t" << pca.componentEigenvalues[0] << std::endl;
        os << "Eigenvalue 2:\t" << pca.componentEigenvalues[1] << std::endl;
        os << "\n2. What are the Eigenvectors for the principal components 1 and 2 (showing July and January component values for each)?\n\n";
        os << "Eigenvector 1:\n"
           << pca.componentEigenvectors[0] << std::endl;
        os << "Eigenvector 2:\n"
           << pca.componentEigenvectors[1] << std::endl;
        os << "\n3. Compute the values for the covariance matrix.\n\n";
        os << "Covariance matrix:\n"
           << pca.covarianceMatrix << std::endl;
        os << "\n4. What is the total variance?\n\n";
        os << pca.totVariance << std::endl;
        os << "\n5. What proportion (as a percentage) of total variance do principal components 1 and 2 \"explain\"?\n\n";
        os << "Principal Component 1 explains: " << pca.explainedVariance[0] << "%\n";
        os << "Principal Component 2 explains: " << pca.explainedVariance[1] << "%\n";
        return os;
    }
} // namespace CHNJAR003