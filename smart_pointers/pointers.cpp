#include<memory>
#include<iostream>

class Spy
{
    public:
    explicit Spy(int n): d_n(n) 
    {
        std::cout << "Spy::Spy(" << d_n << ")\n"; 
    }

    int get() const 
    { 
        return d_n; 
    }

    void show() const
    {
        std::cout << "Spy::show(" << d_n << ")\n";
    }

    ~Spy()
    {
        std::cout << "Spy::~Spy(" << d_n << ")\n";
    }
    private:
    int d_n;
};

using SpyPtr = std::unique_ptr<Spy>; 

void stealSpy(SpyPtr i_ptr)
{
    std::cout << "StealingSpy " << i_ptr->get() << "\n";
}

int main()
{
    {// unique_ptr storage and move
        std::cout << "unique_ptr storage and move\n";
        SpyPtr spyHolder = std::make_unique<Spy>(1);
        std::cout << "SpyHolder = " << spyHolder->get() << "\n";
        //spyHolder.reset(spyHolder.get()); // ouch! 
        spyHolder->show();
        //std::unique_ptr<Spy> otherHolder;
        //otherHolder = spyHolder; // prohibited
        //auto otherHolder = spyHolder; // prohibited
        auto otherHolder = std::move(spyHolder); // ok
        SpyPtr yetAnotherHolder;
        yetAnotherHolder = std::move(otherHolder); // ok
        yetAnotherHolder->show();
        stealSpy(std::move(yetAnotherHolder));
        // yetAnotherHolder->show(); // UB: yetAnotherHolder is in MovedFrom state
    }
    {
        // unique_ptr replacement
        std::cout << "unique_ptr replacement\n";
        auto spyHolder2 = std::make_unique<Spy>(2);
        auto spyHolder3 = std::make_unique<Spy>(3);

        spyHolder2->show();
        spyHolder2 = std::move(spyHolder3);
        spyHolder2->show();
    }
}