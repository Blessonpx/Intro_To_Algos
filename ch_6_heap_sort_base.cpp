#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <iostream>
#include <string>


using namespace boost::numeric::ublas;

int getParent(matrix<double>& a,int i){
    if(i<1){
        return -1;
    }else {
        return i/2;
    }
}

int getLeft(matrix<double>& a,int i){
    
    if(2*i>a.size1()){
        return -1;
    }else {
        return 2*i;
    }
}

int getRight(matrix<double>& a,int i){
    
    if((2*i-1)>a.size1()){
        return -1;
    }else {
        return 2*i-1;
    }
}

int main(){
    // Create Matrix
    matrix<double> a(1,4);
    a(0,0)=1;a(0,1)=2;a(0,2)=3;a(0,3)=4;
    
    std::cout << "###############Base Test############### " << std::endl;
    // Before Swapping
    std::cout << "Matrix a before : " << std::endl;
    std::cout << a << std::endl;

    int tmp=0;
    tmp=a(0,0);
    a(0,0)=a(0,3);
    a(0,3)=tmp;
    // After Swapping
    std::cout << "Matrix a after : " << std::endl;
    std::cout << a << std::endl;

    std::cout << "###############Left-Right-Parent for Matrix############### " << std::endl;
    for(int i=0;i<a.size2();i++){
        std::cout << a(0,i)<<"::Parent-"<< getParent(a,i)
        <<"::Left-"<<(getLeft(a,i)>-1?std::to_string(a(0,getLeft(a,i))).c_str():"NA")
        <<"::Right-"<<(getRight(a,i)>-1?std::to_string(a(0,getRight(a,i))).c_str():"NA")<< std::endl;
    }

    return 0;
}