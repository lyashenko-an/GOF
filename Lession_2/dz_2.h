/*
Как видите, на каждый тип пиццы создается свой собственный класс. И в целом это
неплохо. Но выбор конкретного класса для создания экземпляра усложняет функцию
orderPizza() и не позволяет закрыть её для изменений.

Реализуйте паттерн “абстрактная фабрика” который позволит создавать пиццу не привязываясь к её типу,
чтобы внутри функции orderPizza() не создавались конкретные экземпляры классов
с пиццами
*/

#ifndef DZ_2_H_INCLUDED
#define DZ_2_H_INCLUDED

#pragma once
#include <iostream>

class Pizza
    {
    public:
        virtual void prepare(std::string){};
        virtual void bake() {};
        virtual void cut() {};
        virtual void box() {};

    };

class CheesePizza:public Pizza{};
class GreekPizza:public Pizza{};
class PepperoniPizza:public Pizza{};

class pizzaFab
    {
    public:
        virtual Pizza *pizzaVk() = 0;
        virtual ~pizzaFab(){};
    };

class pizzaFabCP : public pizzaFab
    {
    public:
       Pizza *pizzaVk() override
            {
            return new CheesePizza;
            }
    };

class pizzaFabGP : public pizzaFab
    {
    public:
        Pizza *pizzaVk() override
            {
                return new GreekPizza;
            }
    };

class pizzaFabPP : public pizzaFab
    {
    public:
        Pizza *pizzaVk() override
            {
                return new PepperoniPizza;
            }
    };

Pizza *orderPizza(std::string &type)
    {
    Pizza *pizza {nullptr};
    pizzaFab *pF {nullptr};
    if (type == "cheese")
        {
        pF = new pizzaFabCP;
        }
    else
        if (type == "greek")
        {
        pF = new pizzaFabGP;
        }
    else
        if (type == "pepperoni")
        {
        pF = new pizzaFabPP;
        }
    pizza = pF -> pizzaVk();
    pizza -> prepare(type);

    return pizza;
    }



#endif // DZ_2_H_INCLUDED
