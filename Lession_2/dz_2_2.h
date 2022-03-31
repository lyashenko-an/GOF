/*
�� ������ ������� ������� � ��� ������������ �������� ���� ������������
��������. �� ������� ����������� �����, � ������� ���������� ����� ��� �������
��������� ���� ��������.
�� � ���� ����� �������� ��� ��������� ������� (�������, ������, ������� ������)
��� �������� ����� ��� ������. ���������� �� ���������, ������� ��� ������ ����
�������� � ������� ���������� �������. � ���������� ������ ������ ��������
������� ���������. �������� ����, ��� ��������� ��������� ������ ��� �������
�������� ������� ���� - �� �������. � ��� ��� �� ������ ������ ���������!
���������� ������� ��������� � ������� �������� ����� ����� ������� ���� �
����� �������� �������.
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
    { // �������;
    public:
        double cost() const override
            {
            return 5.5;
            }
            std::string getDescription() const override
                {
                return getDescription() + "�������";
                }
    };

class DarkRoast: public Beverage
    { // ������ �������
    public:
        double cost() const override
            {
            return 6.0;
            }
            std::string getDescription() const override
                {
                return getDescription() + "������ �������";
                }
    };

class Decaf: public Beverage
    { // ��� �������
    public:
        double cost() const override
            {
            return 7.3;
            }
            std::string getDescription() const override
                {
                return getDescription() + "��� �������";
                }
    };

class Espresso: public Beverage
    { // ��������
    public:
        double cost() const override
            {
            return 3.5;
            }
            std::string getDescription() const override
                {
                return getDescription() + "��������";
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
 //�������, ������, ������� ������
class Chocolad : public Beverage
    {
    private:
        double choco_price {0.5};
        int sugar;

    public:
        Chocolad(Beverage *beverage, int sugar = 0) : Decorator(beverage), sugar(sugar){};

    };

#endif // DZ_2_2_H_INCLUDED
