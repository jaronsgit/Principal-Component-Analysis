#ifndef PCA_H
#define PCA_H
#include "Eigen/Dense"
#include <vector>

namespace CHNJAR003
{

    class PCA
    {
    private:
        std::vector<double> januaryData;
        std::vector<double> julyData;

    public:
        PCA();
        ~PCA();
        void readInputData(std::string fileName);
        void computeCovarianceMatrix();
        void computeEigenValues();
        void computeEigenVectors();
        void computeTotalVariance();
    };

} // namespace CHNJAR003

#endif