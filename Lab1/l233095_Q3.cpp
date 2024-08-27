#include <iostream>
using namespace std;

// Base class Calculator with pure virtual functions
class Calculator {
public:
    virtual void add() = 0;
    virtual void subtract() = 0;
    virtual void multiply() = 0;
    virtual void divide() = 0;
    virtual ~Calculator() {} // Virtual destructor
};

// Struct for complex numbers
struct ComplexNum {
    int real;
    int img;
    ComplexNum(int r = 0, int i = 0) : real(r), img(i) {}
};

// Derived class for simple number calculations
class SimpleNumbers : public Calculator {
private:
    int a, b;

public:
    SimpleNumbers(int x, int y) : a(x), b(y) {}

    void add() override {
        cout << "Simple Addition: " << a << " + " << b << " = " << (a + b) << endl;
    }

    void subtract() override {
        cout << "Simple Subtraction: " << a << " - " << b << " = " << (a - b) << endl;
    }

    void multiply() override {
        cout << "Simple Multiplication: " << a << " * " << b << " = " << (a * b) << endl;
    }

    void divide() override {
        if (b != 0) {
            cout << "Simple Division: " << a << " / " << b << " = " << (a / b) << endl;
        } else {
            cout << "Division by zero error!" << endl;
        }
    }
};

// Derived class for complex number calculations
class ComplexNumbers : public Calculator {
private:
    ComplexNum a, b;

public:
    ComplexNumbers(ComplexNum x, ComplexNum y) : a(x), b(y) {}

    void add() override {
        ComplexNum result(a.real + b.real, a.img + b.img);
        cout << "Complex Addition: (" << a.real << " + " << a.img << "i) + ("
             << b.real << " + " << b.img << "i) = (" << result.real << " + " << result.img << "i)" << endl;
    }

    void subtract() override {
        ComplexNum result(a.real - b.real, a.img - b.img);
        cout << "Complex Subtraction: (" << a.real << " + " << a.img << "i) - ("
             << b.real << " + " << b.img << "i) = (" << result.real << " + " << result.img << "i)" << endl;
    }

    void multiply() override {
        ComplexNum result(a.real * b.real - a.img * b.img, a.img * b.real + a.real * b.img);
        cout << "Complex Multiplication: (" << a.real << " + " << a.img << "i) * ("
             << b.real << " + " << b.img << "i) = (" << result.real << " + " << result.img << "i)" << endl;
    }

    void divide() override {
        int denominator = b.real * b.real + b.img * b.img;
        if (denominator != 0) {
            ComplexNum result((a.real * b.real + a.img * b.img) / denominator,
                              (a.img * b.real - a.real * b.img) / denominator);
            cout << "Complex Division: (" << a.real << " + " << a.img << "i) / ("
                 << b.real << " + " << b.img << "i) = (" << result.real << " + " << result.img << "i)" << endl;
        } else {
            cout << "Division by zero error!" << endl;
        }
    }
};

int main() {
    Calculator* calculator = nullptr;
    char choice;
    cout << "Choose type of calculator (s for Simple, c for Complex): ";
    cin >> choice;

    if (choice == 's') {
        int x, y;
        cout << "Enter two integers: ";
        cin >> x >> y;
        calculator = new SimpleNumbers(x, y);
    } else if (choice == 'c') {
        int real1, img1, real2, img2;
        cout << "Enter first complex number (real and imaginary part): ";
        cin >> real1 >> img1;
        cout << "Enter second complex number (real and imaginary part): ";
        cin >> real2 >> img2;
        calculator = new ComplexNumbers(ComplexNum(real1, img1), ComplexNum(real2, img2));
    } else {
        cout << "Invalid choice!" << endl;
        return 1;
    }

    calculator->add();
    calculator->subtract();
    calculator->multiply();
    calculator->divide();

    delete calculator;
    return 0;
}
