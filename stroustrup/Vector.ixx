export module Vector;

export class Vector {
public:
    explicit Vector(int s);
    Vector(const Vector& other);
    Vector& operator=(const Vector&);
    Vector(Vector&& other);
    Vector& operator=(Vector&& other);
    ~Vector();

    double& operator[](int i);
    double operator[](int i) const;
    int size() const;
private:
    double* elem; // elem points to an array of sz doubles
    int sz;
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