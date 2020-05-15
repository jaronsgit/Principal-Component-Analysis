#ifndef PCA_H
#define PCA_H
#include "Eigen/Dense"
#include <vector>

namespace CHNJAR003
{

    class PCA
    {
    private:
        std::vector<Eigen::Vector2d> dataset;
        Eigen::Matrix2d covarianceMatrix;
        std::vector<double> januaryData;
        std::vector<double> julyData;

    public:
        PCA();
        ~PCA();
        void readInputData(std::string fileName);
        void calculateCovarianceMatrix();
        void computeEigenValues();
        void computeEigenVectors();
        void computeTotalVariance();
    };

} // namespace CHNJAR003

#endif