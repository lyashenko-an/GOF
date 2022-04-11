/*
Iterator
Вспомните курс “Сложные моменты С++” :)
Реализовать паттерн итератор, с помощью которого можно будет проитерироваться по
контейнеру с объектами (одного любого класса) в оба направления (возьмите
контейнеры - список, массив, вектор, дек).
(Дополнительно) Попробуйте улучшить вашу реализацию, чтобы не было четкой
привязки к классу объектов, хранящихся в контейнерах.

*/

#ifndef DZ_3_2_H_INCLUDED
#define DZ_3_2_H_INCLUDED

#include <list>
#include <array>
#include <vector>
#include <deque>


template <class T>

    class Iterator
        {
        protected:
            int Index;

        public:
            Iterator() : Index{} {};

            virtual ~Iterator(){};

            void first ()
                {
                    Index = 0;
                }

            void next ()
                {
                    Index++;
                }

            void prev ()
                {
                    Index--;
                }

            const Iterator &operator++(){this -> next(); return *this;}
            const Iterator &operator--(){this -> prev(); return *this;}

        };


template <class T>

    class listIterator : public Iterator <T>
        {
        private:
            std::list<T> *list_1;

        public:
            listIterator(const std::list<T> *list): Iterator<T>(), list_1{list}{};

            void done() override
                {
                 return this -> Index >= list_1.size();
                }

            void check_Range() override
                {
                if(done())
                    {
                    throw std::out_of_range("Out of range");
                    }
                else
                    {
                    auto it{list_1.begin()};
                    std::advance(it, this -> Index);
                    return *it;
                    }
                }
        };

template <class T>

    class vectorIterator : public Iterator<T>
        {
        private:
            std::vector<T> *vect;

        public:
            vectorIterator(std::vector<T> *vekt) : Iterator<T>{} , vect{ vekt }{}

            void done() override
                {
                 return this -> Index >= vect.size();
                }

            void check_Range() override
                {
                if(done())
                    {
                    return this -> Index >= vect.size();
                    }
                else
                    {
                    return vect -> at(this -> Index);
                    }
                }

        };

template <class T, size_t SIZE_myArr>
    class arrayIterator : public Iterator<T>
        {
        private:
            std::array<T, SIZE_myArr> *myArr;

        public:
            arrayIterator(std::array<T, SIZE_myArr> *myArr) : Iterator<T>{}, myArr{myArr}{}

            void done() override
                {
                 return this -> Index >= myArr.size();
                }

            void check_Range() override
                {
                if(done())
                    {
                    return this -> Index >= myArr.size();
                    }
                else
                    {
                    return this -> myArr -> at(this -> Index);
                    }
                }
        };

template <class T>
    class dequeIterator : public Iterator<T>
        {
        private:
            std::deque<T> *_deq;

        public:
            dequeIterator(std::deque<T> *deq) : Iterator<T>{}, _deq{ deq } {}

            void done() override
                {
                 return this -> Index >= _deq.size();
                }

            void check_Range() override
                {
                if(done())
                    {
                    return this -> Index >= _deq.size();
                    }
                else
                    {
                    return _deq -> at(this -> Index);
                    }
                }
        };

#endif // DZ_3_2_H_INCLUDED
