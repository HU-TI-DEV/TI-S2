#include <iostream>
#include <string>

class led {
private:
    int pincount;
    std::string color;

public:
    led(int pincount, std::string color) : pincount(pincount), color(color) {};
    void print()
    {
        std::cout << "LED        with pincount " << pincount << " and color " << color << std::endl;
    }
};

class transistor {
private:
    int pincount;
    std::string type;

public:
    transistor(int pincount, std::string type) : pincount(pincount), type(type) {};
    void print()
    {
        std::cout << "Transistor with pincount " << pincount << " and  type " << type << std::endl;
    }
};

int main()
{
    led my_led(2, "yellow");
    transistor my_pnp(3, "BC308C");

    std::cout << "Overerving: Electronika" << std::endl;
    my_led.print();
    my_pnp.print();
}
