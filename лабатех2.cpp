#include <iostream>
#include <memory>

using namespace std;

// Declaration of static variables to count instances
static int vectCount = 0;
static int matrCount = 0;

class Vector {
public:
    int dimension;
    unique_ptr<double[]> elements;
    int id;
    static int count;

    Vector(int dimension) : dimension(dimension), elements(new double[dimension]), id(++vectCount) {
        cout << "Vector #" << id << " created." << endl;
    }

    ~Vector() {
        cout << "Vector #" << id << " destroyed." << endl;
    }

    Vector(const Vector& v) : dimension(v.dimension), elements(new double[v.dimension]), id(++vectCount) {
        for (int i = 0; i < dimension; ++i) {
            elements[i] = v.elements[i];
        }
        cout << "Vector #" << id << " created by copying." << endl;
    }

    Vector& operator=(const Vector& v) {
        if (this == &v) return *this;
        dimension = v.dimension;
        elements = unique_ptr<double[]>(new double[dimension]);
        for (int i = 0; i < dimension; ++i) {
            elements[i] = v.elements[i];
        }
        cout << "Vector #" << id << " assigned." << endl;
        return *this;
    }

    Vector operator+(const Vector& v) const {
        Vector result(dimension);
        for (int i = 0; i < dimension; ++i) {
            result.elements[i] = elements[i] + v.elements[i];
        }
        return result;
    }

    // Add other operators (v-v, -v, v*v, k*v) similarly
};

// Initialization of static variable
int Vector::count = 0;

class Matrix {
    // Similar description for the matrix class, including operators (m+m, m-m, -m, m*m, k*m, m=m, m*v)
};

int main() {
    // Usage scenario for vectors and matrices
    Vector v1(3); // Creating a vector
    Vector v2(3); // Creating another vector
    // Demonstrating operations on vectors and matrices
    return 0;
}
