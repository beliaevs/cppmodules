import std;
import Vector;

void print(const Vector& vec, std::ostream& os)
{
    os << '[';
    if (vec.size() > 0)
        os << vec[0];
    for (int i = 1; i != vec.size(); ++i)
        os << ", " << vec[i];

    os << ']';
}

int main()
{
    Vector v(10);

    for (int i = 0; i != v.size(); ++i)
        v[i] = 1. / (i + 1.);

    print(v, std::cout);
    return 0;
}