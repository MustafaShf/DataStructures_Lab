#include <iostream>
using namespace std;

class Polynomial {
private:
    int numTerms;
    int *coeff;
    int *exp;

public:
    
    Polynomial(int n, int c[], int e[]) : numTerms(n) {
        coeff = new int[numTerms];
        exp = new int[numTerms];
        for (int i = 0; i < numTerms; ++i) {
            coeff[i] = c[i];
            exp[i] = e[i];
        }
    }

    
    Polynomial(const Polynomial& other) {
        numTerms = other.numTerms;
        coeff = new int[numTerms];
        exp = new int[numTerms];
        for (int i = 0; i < numTerms; ++i) {
            coeff[i] = other.coeff[i];
            exp[i] = other.exp[i];
        }
    }

    // Copy Assignment Operator
    Polynomial& operator=(const Polynomial& other) {
        if (this != &other) {
            delete[] coeff;
            delete[] exp;

            numTerms = other.numTerms;
            coeff = new int[numTerms];
            exp = new int[numTerms];
            for (int i = 0; i < numTerms; ++i) {
                coeff[i] = other.coeff[i];
                exp[i] = other.exp[i];
            }
        }
        return *this;
    }

    // Destructor
    ~Polynomial() {
        delete[] coeff;
        delete[] exp;
    }

   
    friend ostream& operator<<(ostream& os, const Polynomial& poly) {
        for (int i = 0; i < poly.numTerms; ++i) {
            if (i != 0 && poly.coeff[i] > 0) os << "+";
            os << poly.coeff[i];
            if (poly.exp[i] != 0) os << "x^" << poly.exp[i];
        }
        return os;
    }

    
    Polynomial operator+(const Polynomial& other) const {
        int *newCoeff = new int[numTerms + other.numTerms];
        int *newExp = new int[numTerms + other.numTerms];
        int k = 0;

        
        for (int i = 0; i < numTerms; ++i) {
            newCoeff[k] = coeff[i];
            newExp[k] = exp[i];
            ++k;
        }

       
        for (int j = 0; j < other.numTerms; ++j) {
            bool found = false;
            for (int i = 0; i < k; ++i) {
                if (newExp[i] == other.exp[j]) {
                    newCoeff[i] += other.coeff[j];
                    found = true;
                    break;
                }
            }
            if (!found) {
                newCoeff[k] = other.coeff[j];
                newExp[k] = other.exp[j];
                ++k;
            }
        }

        return Polynomial(k, newCoeff, newExp);
    }

   
    Polynomial operator+(int val) const {
        int *newCoeff = new int[numTerms];
        for (int i = 0; i < numTerms; ++i) {
            newCoeff[i] = coeff[i];
        }
        newCoeff[numTerms - 1] += val;
        return Polynomial(numTerms, newCoeff, exp);
    }

    
    bool operator!=(const Polynomial& other) const {
        if (numTerms != other.numTerms) return true;
        for (int i = 0; i < numTerms; ++i) {
            if (coeff[i] != other.coeff[i] || exp[i] != other.exp[i]) return true;
        }
        return false;
    }

    Polynomial& operator++() {
        for (int i = 0; i < numTerms; ++i) {
            coeff[i]++;
        }
        return *this;
    }

    Polynomial operator++(int) {
        Polynomial temp = *this;
        ++(*this);
        return temp;
    }

    operator bool() const {
        return !(numTerms == 1 && coeff[0] == 0 && exp[0] == 0);
    }
};

// Main function to test the Polynomial class
int main() {
    int coeff_P1[] = {1, 2, 5}; 
    int exp_P1[] = {4, 2, 0};   
    int coeff_P2[] = {4, 3};    
    int exp_P2[] = {6, 2};      

    Polynomial P1(3, coeff_P1, exp_P1); 
    Polynomial P2(2, coeff_P2, exp_P2); 

    cout << "P1 = " << P1 << endl;
    cout << "P2 = " << P2 << endl;

    if (!P1)
        cout << "P1 is zero" << endl;
    if (P1 != P2)
        cout << "P1 is Not Equal to P2" << endl;

    cout << ++P1 << endl;
    cout << P1 << endl;
    cout << P1++ << endl;
    cout << P1 << endl;

    Polynomial P3 = P1 + P2; 
    cout << "P3 = " << P3 << endl;

    P3 = P1 + 2; 
    cout << "P3 = " << P3 << endl;

    return 0;
}
