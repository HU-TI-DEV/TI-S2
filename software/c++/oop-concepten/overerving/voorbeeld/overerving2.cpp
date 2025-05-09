#include <iostream>
#include <string>

enum tcode {
    tc_unknown,
    tc_led,
    tc_transistor,
    tc_diode,
    tc_module
};

class component {
private:
    int pincount;
    tcode typecode;

public:
    component(int pincount, tcode typecode) : pincount(pincount), typecode(typecode) { /* DEBUG print_basics() */ };
    void print_basics()
    {
        std::cout << "component  with pincount " << pincount << " and typecode " << typecode << std::endl;
    }
};

class led : public component {
private:
    std::string color;

public:
    led(int pincount, std::string color) : component(pincount, tc_led), color(color) {};
    void print()
    {
        std::cout << "LED        with color " << color << std::endl;
        print_basics();
    }
};

class transistor : public component {
private:
    std::string type;

public:
    transistor(int pincount, std::string type) : component(pincount, tc_transistor), type(type) {};
    void print()
    {
        std::cout << "Transistor with  type " << type << std::endl;
        print_basics();
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
