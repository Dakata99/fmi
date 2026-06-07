#include <iostream>

class Bus;

class Car
{
private:
    double speed;
public:
    Car(const double sp = 0):speed(sp){}
    
    void setSpeed(const double sp)
    {
        speed = sp;
    }
    double getSpeed()const
    {
        return speed;
    }
    friend bool speed_greater(const Car& car, const Bus& bus);
};

class Bus
{
private:
    double speed;
public:
    Bus(const double sp = 0):speed(sp){}
    void setSpeed(const double sp)
    {
        speed = sp;
    }
    double getSpeed()const
    {
        return speed;
    }
    friend bool speed_greater(const Bus& bus, const Car& car)
    {
        return bus.getSpeed() >= car.getSpeed();
    }
};

bool speed_greater(const Car& car, const Bus& bus)
{
    return car.getSpeed() >= bus.getSpeed();
}

int main()
{
    Car c;
    c.setSpeed(32);

    Bus b;
    b.setSpeed(43);

    std::cout << std::boolalpha << speed_greater(b, c) << std::endl;
    return 0;
}



