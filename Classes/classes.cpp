#include <iostream>
#include <string>

using namespace std;

/*CLASSES*/

/*concrete types -- behave like built in types*/
/* representation is part of definition */

/*complex --  "classical user-defined aritmetic type"*/
class complex{
    double re, im; //two doubles

public:
    complex(double r, double i) :re{r}, im{i} {} //construct from two scalars
    complex(double r) :re{r}, im{0} {} //construct from two scalars
    complex() :re{0}, im{0} {}
    
    double real() const { return re; }
    void real(double d) { re=d; }
    double imag() const { return im; }

};

class Vector {
private:
    double * elem;
    int sz;

public:
    Vector(int s) :elem{new double[s]}, sz{s}
    {
        for(int i = 0; i != s; ++i) {
            elem[i] = 0;
        }
    }

    ~Vector() {
        delete[] elem;
        cout << "vector deleted" << endl;
    }

    double& operator[](int i);
    int size() const {
        return sz;
    }
};


/*abstract types*/
/*representation is not part of definiton*/
class Animal {
public: 
    virtual string says() { return "?"; }
    virtual ~Animal();
};

class Dog :public Animal  {
    public: string says() { return "Woof"; }
    ~Dog();
};

/* allows me to dynamically initialize animal*/

/*casting*/

class Point {
int x, y, z;
public:
    Point(int inX, int inY, int inZ) :x{inX}, y{inY}, z{inZ} {}
    void print() { 
        cout << x << endl;
        cout << y << endl;
        cout << z << endl;
    }
};

int main(){
    Point p{1,2,3};
    p.print();
}