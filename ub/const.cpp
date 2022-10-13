void f(int x);
bool g(int x)
{
    const int y = x;
    f(y);
    return x == y;
}
