#include <iostream>

class Singleton
{
private:
    /* data */
    Singleton(/* args */);
    ~Singleton();
public:
    static Singleton *instance();
};

Singleton::Singleton(/* args */)
{
}

Singleton::~Singleton()
{
}

Singleton *Singleton::instance()
{
    Singleton * instanceTemp = new Singleton();
    return instanceTemp;
}
