import std;
import Vector;

int main()
{
    Vector v(10);

    for (int i = 0; i != v.size(); ++i)
        v[i] = 1. / (i + 1.);

    Vector w = v;
    Vector x{ std::move(w) };
    std::cout << v << "\n";
    std::cout << w << "\n";
    return 0;
}