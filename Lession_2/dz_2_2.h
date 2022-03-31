/*
Вы решили открыть кофейню и вам понадобилось наладить учет производства
напитков. Вы создали абстрактный класс, в котором определили метод для расчета
стоимости всех напитков.
Но к кофе можно заказать еще различные добавки (шоколад, корица, взбитые сливки)
или наоборот взять без сахара. Дополнения не бесплатны, поэтому они должны быть
встроены в систему оформления заказов. А отсутствие сахара должно наоборот
снижать стоимость. Понятное дело, что создавать отдельные классы для каждого
варианта “сборки” кофе - не вариант. И тут нам на помощь придет декоратор!
Реализуйте паттерн декоратор с помощью которого можно будет сварить кофе с
любым составом добавок.
*/


#ifndef DZ_2_2_H_INCLUDED
#define DZ_2_2_H_INCLUDED

#pragma once

class Beverage
    {
    public:
        virtual std::string getDescription() const {return "Koffe";};
        virtual double cost() const = 0;
        virtual ~Beverage(){}
    };

class HouseBlend: public Beverage
    { // Молотый;
    public:
        double cost() const override
            {
            return 5.5;
            }
            std::string getDescription() const override
                {
                return getDescription() + "молотый";
                }
    };

class DarkRoast: public Beverage
    { // Темной обжарки
    public:
        double cost() const override
            {
            return 6.0;
            }
            std::string getDescription() const override
                {
                return getDescription() + "темной обжарки";
                }
    };

class Decaf: public Beverage
    { // Без кофеина
    public:
        double cost() const override
            {
            return 7.3;
            }
            std::string getDescription() const override
                {
                return getDescription() + "без кофеина";
                }
    };

class Espresso: public Beverage
    { // Эспрессо
    public:
        double cost() const override
            {
            return 3.5;
            }
            std::string getDescription() const override
                {
                return getDescription() + "Эспрессо";
                }
    };

class Decorator : public Beverage
        {
        private:
            Beverage *beverage;
        public:
            Decorator(Beverage *beverage) : beverage(beverage){};

            std::string getDescription() const override
                {
                return "+";
                }
        };
 //шоколад, корица, взбитые сливки
class Chocolad : public Beverage
    {
    private:
        double choco_price {0.5};
        int sugar;

    public:
        Chocolad(Beverage *beverage, int sugar = 0) : Decorator(beverage), sugar(sugar){};

    };

#endif // DZ_2_2_H_INCLUDED
