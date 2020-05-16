# C++ Assignment 5: Principal Component Analysis

The project includes PCA.h, PCA.cpp, driver.cpp, the Eigen (3.3.7) header files as well as a Makefile.

PCA.h contains all the header declarations for the PCA class, which is responsible for performing reading in the data set and performing the necessary operations to produce the required results.

PCA.cpp contains the method definitions for the PCA class.

driver.cpp is the program calls the necessary PCA class methods and writes the results to the results.txt files.

## How to use the program

The program directory structure is as follows:

Assignment5_CHNJAR003
bin - contains the output executables
build - contains the object files (emptied on "make clean")
include - contains all the project header files
src - contains the application source files

### The structure of the command line execution is as follows:

NB: make use of the "make run" command to execute the program and produce the results.

NB: the executable is located in the bin directory

```bash
./bin/pca
```

Navigate to the folder in Terminal and utilise the provided Makefile to compile the program source code using:

```bash
make
```

The following command can be used to run the executable with the dataset and write the results to "results.txt", which will be created in the main assignment directory:

```bash
make run
```

Use the following command to remove the binary files and executable from the build and bin folders respectively:

```bash
make clean
```

## Authors

**CHNJAR003**
The assignment makes use of the Eigen (3.3.7) template library for linear algebra
