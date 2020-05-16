#ifndef PCA_H
#define PCA_H
#include "Eigen/Dense"
#include <vector>

namespace CHNJAR003
{

    class PCA
    {
    private:
        std::vector<double> januaryData;      //Stores the January column of rainfall values - read from textfile
        std::vector<double> julyData;         //Stores the July column of rainfall values - read from textfile
        std::vector<Eigen::Vector2d> dataset; //Stores the 2D data points of the dataset - (January, July) rainfall in mm

        Eigen::Matrix2d covarianceMatrix;                   //Stores the calculated covariance matrix
        std::vector<double> componentEigenvalues;           //Stores the calculated real-valued eigenvalues of the covariance matrix
        std::vector<Eigen::Vector2d> componentEigenvectors; //Stores the calculated real-valued eigenvectors of the covariance matrix
        std::vector<double> explainedVariance;              //Stores the calculated amount of variace "explained" by each principal component
        double totVariance;

    public:
        PCA();
        ~PCA();
        void readInputData(std::string fileName);
        void calculateCovarianceMatrix();
        void calculateEigenvaluesAndVectors();
        void calculateTotalVariance();
        void calculateExplainedVariance();

        friend std::ostream &operator<<(std::ostream &os, const PCA &pca); //Overloaded output operator
    };

} // namespace CHNJAR003

#endif