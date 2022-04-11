
//strategy

/*
Представьте, что вы разрабатываете текстовый редактор и вам необходимо
реализовать деление текста на строки (перенос строк). Это удобный функционал,
когда текст оказывается слишком длинным и приходится постоянно выполнять
горизонтальную прокрутку, чтобы его читать. Для выполнения данной задачи было
представлено 3 алгоритма:
● Деление текста на строки в зависимости от ширины клиентского окна
● Деление текста на строки указанной ширины (передается в качестве параметра)
● Автоматическое деление текста по предложениям (учитываются знаки
препинания .!?)
Реализуйте паттерн стратегия, чтобы иметь возможность выбирать нужный алгоритм
деления на предложения.
Сами методы DivideBy... реализовывать не обязательно. Главное сам паттерн. Но если
хочется, то можно)
*/


#ifndef DZ_3_1_H_INCLUDED
#define DZ_3_1_H_INCLUDED

#pragma once

#include <iostream>
#include <fstream>

class Strategy
        {
        protected:
            Strategy(){};

        public:
            virtual void Divide()
                {
                std::cout << "All OK" << std::endl;
                }
        virtual ~Strategy(){};

        };
    class ScreenStr : public Strategy           // изменение строки под размер окна
        {
        public:
            ScreenStr() : Strategy(){};
            void Divide() override
                {
                Strategy::Divide();
                std::cout << "Resize text width windows" << std::endl;
                }
        };

    class ScreenWW : public Strategy            // задаем ширину окна
        {
        public:
            ScreenWW() : Strategy(){};
            void Divide() override
                {
                int a;
                std::cout << "input width sreen" << std::endl;
                std::cin >> a;
                Strategy::Divide();
            }
        };
    class ScreenRS : public Strategy            // режем строки на части в зависимости от ширины окна
        {
        public:
            ScreenRS():Strategy(){};
            void Divide() override
                {
                std::cout << "Resize text" << std::endl;
                }
        };

enum class DivideMethod
    {
    ByScreenWidth,
    ByUserWidth,
    BySentence
    };

class ITextWork
    {
    public:
        virtual void Divide(DivideMethod) = 0;

        virtual void setStr(Strategy*) = 0;
        virtual void useStr() = 0;

        virtual ~ITextWork(){};
    };

class TextEditor: public ITextWork
    {
    private:
        size_t EditorWidth;
        std::string all_text;
        Strategy *_strategy;
    public:
        TextEditor(){};
        TextEditor(const std::string &text) : all_text(text) {};
        TextEditor(std::ifstream& file)
            {
            std::string line;
            if (file.is_open())
                {
                while (getline(file, line))
                    {
                    all_text+=line;
                    }
                }
            }

    void PrintText() const
        {
        std::cout << all_text << std::endl;
        }

    void Divide(DivideMethod method) override
        {
        switch (method)
            {
            case DivideMethod::ByScreenWidth:
            DivideByScreenWidth();
            break;

            case DivideMethod::BySentence:
            DivideBySentence();
            break;

            case DivideMethod::ByUserWidth:
            DivideByUserWidth(100);
            break;

            default:
            DivideByScreenWidth();
            }
        }

    void DivideByScreenWidth()
        {
        std::cout << "DivideByScreenWidth by screen width = " << EditorWidth << std::endl;
        }

    void DivideBySentence()
        {
        std::cout << "Divided by Sentences" << std::endl;
        }

    void DivideByUserWidth(int userWidth)
        {
        std::cout << "DivideByScreenWidth by screen width = " << userWidth << std::endl;
        }
    void setStr(Strategy *strategy) override
        {
            _strategy = strategy;
        }
    void useStr() override
        {
         _strategy -> Divide();
        }
    };



#endif // DZ_3_1_H_INCLUDED
