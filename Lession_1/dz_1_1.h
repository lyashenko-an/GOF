#ifndef DZ_1_H_INCLUDED
#define DZ_1_H_INCLUDED

#pragma once
#include <iostream>
#include <map>
#include <ctime>

//Step 1----------------------------------------------------------------------------------------

class ChocolateBoiler
    {
    private:
        ChocolateBoiler(){_empty = true; _boiled = false;}
        bool _empty;
        bool _boiled;
        static ChocolateBoiler *_uniqueInstance;

    public:
        //ChocolateBoiler(){_empty = true; _boiled = false;}
        bool isEmpty() const { return _empty; }
        bool isBoiled() const{ return _boiled; }

        void fill()
            {
            if (isEmpty())
                {
                _empty = false;
                _boiled = false;
                }
            }

        void drain()
            {
            if (!isEmpty() && isBoiled())
                {
                _empty = true;
                }
            }
        void boil()
            {
            if (!isEmpty() && !isBoiled())
                {
                _boiled = true;
                }
            }

        static ChocolateBoiler *GetInstance()
            {
            if (_uniqueInstance == nullptr)
                {
                _uniqueInstance = new ChocolateBoiler();
                }
            return _uniqueInstance;
            }

    virtual ~ChocolateBoiler();
    };

    ChocolateBoiler *ChocolateBoiler::_uniqueInstance = nullptr;

    ChocolateBoiler::~ChocolateBoiler()
        {
        delete _uniqueInstance;
        }


//Step 2 -------------------------------------------------------------------------------------------

class ISellSystem
    {
    public:
        virtual void changePrice(std::string, float) = 0;
        virtual void sellProduct(std::string) = 0;
        virtual void addProduct(std::string, size_t) = 0;
    };

class Automaton: ISellSystem
    {
    private:
        std::string location;
        double recieved_money;
        double spent_money;
        std::map <std::string, float> goods_price;
        std::map <std::string, size_t> goods_count;

    public:
        Automaton(const std::string &location, double recievedMoney) :
        location(location), recieved_money(recievedMoney) {spent_money = 0.0;}

    void changePrice(std::string name, float newPrice) override
        {
        goods_price[name] = newPrice;
        }

    void sellProduct(std::string name)
        {
        if(goods_count[name] > 0)
            {
            recieved_money += goods_price[name];
            }
        else
            {
            std::cerr << "Not enough goods" << std::endl;
            }
        }

    void addProduct(std::string name, size_t count)
        {
        goods_count[name] += count;
        }

    double allMoneyReport() const
        {
        return recieved_money - spent_money;
        }

    const std::string& getLocationReport() const
        {
        return location;
        }

    std::map <std::string, size_t> goodsCountReport() const
        {
        return goods_count;
        };

    std::map <std::string, float> goodsPriceReport() const
        {
        return goods_price;
        };
    };

class autoProxy : public ISellSystem
    {
    private:
        std::time_t  logTime;
        Automaton *_automaton;
        std::string location;
        double allMoney;
        std::map <std::string, float> goods_price;
        std::map <std::string, size_t> goods_count;

        void updateData()
            {
            std::time_t currentTime{std::time(nullptr)};
            if ((currentTime - logTime) >= 3600)
                {
                location = _automaton -> getLocationReport();
                allMoney = _automaton -> allMoneyReport();
                goods_price = _automaton -> goodsPriceReport();
                goods_count = _automaton -> goodsCountReport();
                logTime = currentTime;
                }
            }
    public:
        autoProxy(const std::string &arg1, double arg2):
            _automaton{new Automaton(arg1, arg2)},
            logTime{},
            location {_automaton -> getLocationReport()},
            allMoney {_automaton -> allMoneyReport()},
            goods_price {_automaton -> goodsPriceReport()},
            goods_count {_automaton -> goodsCountReport()}
            {

            }
    };

#endif // DZ_1_H_INCLUDED
