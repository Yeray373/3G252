#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <sstream>
using namespace std;

#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
using namespace ftxui;

string nave =
    string("     ___     \n") +
    string(" ___/   \\___ \n") +
    string("/   '---'   \\\n") +
    string("'--_______--'\n") +
    string("     / \\     \n") +
    string("    /   \\    \n") +
    string("    /\\O/\\    \n") +
    string("    / | \\    \n") +
    string("    // \\\\    \n");

int main(int argc, char const *argv[])
{
    auto pantalla = Screen::Create(
        Dimension::Full(),
        Dimension::Fixed(10));

    int x = 0;
    int y = 0;

    while (true)
    {
        x++;
        stringstream ss(nave);
        string linea;
        int nolinea = 0;
        while (getline(ss, linea))
        {
            int columna = 0;
            for (auto &&letra : linea)
            {
                auto &pixel = pantalla.PixelAt(x + columna, y + nolinea);
                pixel.character = letra;
                columna++;
            }
            
            nolinea++;
        }

        // pixel.blink = true;
        // pixel.background_color = Color::Cyan;
        // pixel.foreground_color = Color::Green;

        pantalla.Print();
        pantalla.Clear();
        cout << pantalla.ResetPosition();
        this_thread::sleep_for(chrono::milliseconds(400));
    }

    return 0;
}
