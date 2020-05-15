#ifndef PCA_H
#define PCA_H
#include "Eigen/Dense"

namespace CHNJAR003
{

    class PCA
    {
    private:
        /* data */
    public:
        PCA();
        ~PCA();
        void readInputData(std::string filename);
        void computeCovarianceMatrix();
        void computeEigenValues();
        void computeEigenVectors();
        void computeTotalVariance();
    };

} // namespace CHNJAR003

#endif