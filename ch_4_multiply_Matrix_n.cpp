#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

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

    matrix<double> a(2,3);
    a(0,0)=1;a(0,1)=2;a(0,2)=3;
    a(1,0)=4;a(1,1)=5;a(1,2)=6;


    matrix<double> b(3,2);
    b(0,0)=7;b(0,1)=8;
    b(1,0)=9;b(1,1)=10;
    b(2,0)=11;b(2,1)=12;

    matrix<double> c = matrix_multiply(a,b);

    std::cout << "Matrix a: " << std::endl;
    std::cout << a << std::endl;

    std::cout << "Matrix b: " << std::endl;
    std::cout << b << std::endl;

    std::cout << "Matrix c: " << std::endl;
    std::cout << c << std::endl;


}