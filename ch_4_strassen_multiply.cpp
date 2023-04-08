#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>
#include <boost/numeric/ublas/io.hpp>

using namespace boost::numeric::ublas;

matrix<double> strassen_multiply(matrix<double>& a,matrix<double>& b){
    int n=a.size1();
    matrix<double> c(n,n);
    if(n==1){
        c(0,0)=a(0,0)*b(0,0);
    }else{
        int m=n/2;
        matrix<double> a11 = subrange(a,0,m,0,m);
        matrix<double> a12 = subrange(a,0,m,m,n);
        matrix<double> a21 = subrange(a,m,n,0,m);
        matrix<double> a22 = subrange(a,m,n,m,n);

        matrix<double> b11 = subrange(b,0,m,0,m);
        matrix<double> b12 = subrange(b,0,m,m,n);
        matrix<double> b21 = subrange(b,m,n,0,m);
        matrix<double> b22 = subrange(b,m,n,m,n);

        matrix<double> s1 = b12 - b22;
        matrix<double> s2 = a11 + a12;
        matrix<double> s3 = a21 + a22;
        matrix<double> s4 = b21 - b11;
        matrix<double> s5 = a11 + a22;
        matrix<double> s6 = b11 + b22;
        matrix<double> s7 = a12 - a22;
        matrix<double> s8 = b21 + b22;
        matrix<double> s9 = a11 - a21;
        matrix<double> s10 = b11 + b12;

        matrix<double> p1 = strassen_multiply(a11, s1);
        matrix<double> p2 = strassen_multiply(s2, b22);
        matrix<double> p3 = strassen_multiply(s3, b11);
        matrix<double> p4 = strassen_multiply(a22, s4);
        matrix<double> p5 = strassen_multiply(s5, s6);
        matrix<double> p6 = strassen_multiply(s7, s8);
        matrix<double> p7 = strassen_multiply(s9, s10);

        matrix<double> c11 = p5 + p4 - p2 + p6;
        matrix<double> c12 = p1 + p2;
        matrix<double> c21 = p3 + p4;
        matrix<double> c22 = p5 + p1 - p3 - p7;

        subrange(c, 0, m, 0, m) = c11;
        subrange(c, 0, m, m, n) = c12;
        subrange(c, m, n, 0, m) = c21;
        subrange(c, m, n, m, n) = c22;

    }
    return c;
}

int main(){

    // matrix<double> b(3,3);
    // b(0,0)=7;b(0,1)=8;b(0,2)=8;
    // b(1,0)=9;b(1,1)=10;b(1,2)=10;
    // b(2,0)=11;b(2,1)=12;b(2,2)=12;

    // matrix<double> c(3,3);
    // c(0,0)=7;c(0,1)=8;c(0,2)=8;
    // c(1,0)=9;c(1,1)=10;c(1,2)=10;
    // c(2,0)=11;c(2,1)=12;c(2,2)=12;
    matrix<double> a(2,3);
    a(0,0)=1;a(0,1)=2;a(0,2)=3;
    a(1,0)=4;a(1,1)=5;a(1,2)=6;


    matrix<double> b(3,2);
    b(0,0)=7;b(0,1)=8;
    b(1,0)=9;b(1,1)=10;
    b(2,0)=11;b(2,1)=12;

    matrix<double> d = strassen_multiply(a,b);

    std::cout << "Matrix a: " << std::endl;
    std::cout << a << std::endl;

    std::cout << "Matrix b: " << std::endl;
    std::cout << b << std::endl;

    std::cout << "Matrix d: " << std::endl;
    std::cout << d << std::endl;

    return 0;
}