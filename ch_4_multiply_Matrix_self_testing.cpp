#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <iostream>
#include <random>


using namespace boost::numeric::ublas;

matrix<double> matrix_multiply(matrix<double>& a,matrix<double>& b){
    int m=a.size1();
    int n=b.size2();
    matrix<double> c(m,n);

    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            double sum=0.0;
            for(int k=0;k<a.size2();k++){
                sum+=a(i,k)*b(k,j);
            }
            c(i,j)=sum;
        }
    }
    return c ;
}


int main(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(1.0, 10.0);
    const int n = 10; // size of matrix
    matrix<double> a(n, n);
    matrix<double> b(n, n);
    matrix<double> c(n, n);
    // initialize matrices with random values
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a(i, j) = dis(gen);
            b(i, j) = dis(gen);
        }
    }
    // compute matrix product using matrix_multiply function
    c = matrix_multiply(a, b);
    // compute matrix product using nested loops (for testing)
    matrix<double> d(n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double sum = 0.0;
            for (int k = 0; k < n; k++) {
                sum += a(i, k) * b(k, j);
            }
            d(i, j) = sum;
        }
    }
    // check if matrix product computed using matrix_multiply function is equal to the one computed using nested loops
    bool is_equal = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (std::abs(c(i, j) - d(i, j)) > 1e-10) { // check if element differs by more than 1e-10
                is_equal = false;
                break;
            }
        }
        if (!is_equal) {
            break;
        }
    }
    if (is_equal) {
        std::cout << "Matrix multiplication test passed!" << std::endl;
    } else {
        std::cout << "Matrix multiplication test failed!" << std::endl;
    }
    return 0;
}