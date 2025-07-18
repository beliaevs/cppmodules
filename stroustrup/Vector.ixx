export module Vector;

import std;

export class Vector {
public:
    Vector() = default;
    explicit Vector(int s);
    Vector(const Vector& other);
    Vector& operator=(const Vector&);
    Vector(Vector&& other);
    Vector& operator=(Vector&& other);
    ~Vector();

    double& operator[](int i);
    double operator[](int i) const;
    int size() const;
    friend std::ostream& operator<<(std::ostream& os, const Vector& vec);

private:
    double* elem = nullptr; // elem points to an array of sz doubles
    int sz = 0;
};

Vector::Vector(int s)
    :elem{ new double[s] }, sz{ s } // initialize members
{
}

Vector::Vector(const Vector& other) : elem{ new double[other.sz] }, sz{ other.sz }
{
    for (int i = 0; i != 0; ++i)
        elem[i] = other.elem[i];
}

Vector::Vector(Vector&& other) : elem{ other.elem }, sz{ other.sz }
{
    other.elem = nullptr;
    other.sz = 0;
}

Vector& Vector::operator=(const Vector& rhs)
{
    if (elem != rhs.elem)
    {
        delete[] elem;
        elem = new double[rhs.sz];
        sz = rhs.sz;
        for (int i = 0; i != sz; ++i)
            elem[i] = rhs.elem[i];
    }
        
    return *this;
}

Vector& Vector::operator=(Vector&& rhs)
{
    if (elem != rhs.elem)
    {
        delete[] elem;
        elem = rhs.elem;
        sz = rhs.sz;
        rhs.elem = nullptr;
        rhs.sz = 0;
    }
    return *this;
}

Vector::~Vector()
{
    delete[] elem;
}

double& Vector::operator[](int i)
{
    return elem[i];
}

double Vector::operator[](int i) const
{
    return elem[i];
}

int Vector::size() const
{
    return sz;
}

export bool operator==(const Vector& v1, const Vector& v2)
{
    if (v1.size() != v2.size())
        return false;
    for (int i = 0; i < v1.size(); ++i)
        if (v1[i] != v2[i])
            return false;
    return true;
}

void print(const Vector& vec, std::ostream& os)
{
    os << '[';
    if (vec.size() > 0)
        os << vec[0];
    for (int i = 1; i < vec.size(); ++i)
        os << ", " << vec[i];

    os << ']';
}

export std::ostream& operator<<(std::ostream& os, const Vector& vec)
{
    print(vec, os);
    return os;
}