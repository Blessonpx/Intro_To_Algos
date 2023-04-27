#include <iostream>

class Dummy {
private:
    int value;

public:
    Dummy(int v) {
        value = v;
    }

    int getValue() {
        return value;
    }

    void setValue(int v) {
        value = v;
    }
};

int main() {
    // Create an instance of the Dummy class
    Dummy d(5);

    // Get the value of the Dummy instance using the getValue method
    std::cout << "The value of d is: " << d.getValue() << std::endl;

    // Set the value of the Dummy instance using the setValue method
    d.setValue(10);

    // Get the new value of the Dummy instance using the getValue method
    std::cout << "The new value of d is: " << d.getValue() << std::endl;

    return 0;
}
