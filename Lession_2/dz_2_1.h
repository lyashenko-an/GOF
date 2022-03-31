/*
Реализуйте паттерн команда, чтобы можно было сохранять состояние лампочки и
проигрывать её мерцание как в прямом так и в обратном направлении.
*/

#ifndef DZ_2_1_H_INCLUDED
#define DZ_2_1_H_INCLUDED

#pragma once
#include <vector>

enum class Colors
    {
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    CYAN,
    BLUE,
    VIOLET,
    WHITE
    };

class Light
    {
    public:
        Light():state(false), color(Colors::WHITE){};

        void On()                                           //Включили лампочку
            {
            if(!state)
                {
                state = true;
                }
            }

        void Off()                                          //Выключили лампочку
            {
            if(state)
                {
                state = false;
                }
            }

        void changeColor(Colors newColor)                   //Сменили цвет
            {
            color = newColor;
            }

        bool getState() const                               //Текущее состояние
            {
            return state;
            }

    private:
    bool state;
    Colors color;
};

class Comm_Lights
    {
    protected:

        Light *light;
        Comm_Lights(Light *light) : light(light) {};

    public:

        virtual ~Comm_Lights(){};

        virtual void setcolor() = 0;

        virtual void on_light() = 0;
        virtual void off_light() = 0;



    };

class Set_Colors : public Comm_Lights
    {
    private:
        Colors *newcolor;

    public:
        Set_Colors(Light *light, Colors *newcolor) : Comm_Lights(light), newcolor(newcolor) {};

        void setcolor()
            {
            light ->changeColor(*newcolor);
            }
    };

class On_Off_Comm_Lights : public Comm_Lights
    {

    public:
        On_Off_Comm_Lights(Light *light) : Comm_Lights(light) {};

        void on_light()
            {
            light -> On();       //включили
            }

        void off_light()
            {
            light -> Off();      //Выключили
            }
    };

class play_light_blinking
    {
    private:
        Light *light;
        std::vector<Comm_Lights*> comm_lights;

    public:
        play_light_blinking(Light *light) : light(light) {};

        void add_command(Comm_Lights *cmd)
            {
            comm_lights.push_back(cmd);
            }

        void command_forvard()
            {
            for(auto i = 0; i < size(comm_lights); i++)
                {
                if (comm_lights[i])
                    {
                    comm_lights[i] -> on_light();
                    }
                else
                    {
                    comm_lights[i] -> off_light();
                    }
                }
            }

        void command_back()
            {
            for (auto i = size(comm_lights); i = 0; --i)
                {
                if (comm_lights[i])
                    {
                    comm_lights[i] -> on_light();
                    }
                else
                    {
                    comm_lights[i] -> off_light();
                    }
                }

            }

    };


#endif // DZ_2_1_H_INCLUDED
