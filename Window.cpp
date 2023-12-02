//
// Created by micha on 12/1/2023.
//
#include <iostream>
#include "Window.h"

sf::RectangleShape Window::setRectangle(sf::Vector2f s,float x, float y, float o_x, float o_y, sf::Color color){
    sf::RectangleShape rect;
    rect.setSize(s);
    rect.setPosition(x, y);
    rect.setOrigin(o_x,o_y);
    rect.setFillColor(color);
    return rect;
}

void Window::printText(string txt, bool u, float x, float y, sf::RenderWindow *window, int f_size, bool w, bool bold){
    sf::Font font;
    if (!font.loadFromFile("../src/font.ttf")){
        throw("Font broke");
    }

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(f_size);
    text.setStyle(sf::Text::Regular);
    text.setString(txt);

    if (w){
        text.setFillColor(sf::Color::Black);
    }
    else{
        text.setFillColor(sf::Color::Black);
    }

    if (u)
        text.setStyle(sf::Text::Underlined);

    if (bold)
        text.setStyle(sf::Text::Bold);

    if (bold && u)
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    sf::FloatRect tR = text.getLocalBounds();
    text.setOrigin(tR.width/2.0f,tR.height/2.0f);
    text.setPosition(x, y);
    window->draw(text);
}


Window::Window() {

}

std::vector<string> Window::start(){
    int curr = 0;
    string name = "";
    string make = "";
    string model = "";
    int infoType = 0;
    int width = 25;
    int height = 16;
    sf::RenderWindow window(sf::VideoMode(32*width, 32*height+100), "Ticket Mistress", sf::Style::Close);
    window.setFramerateLimit(60);
    sf::RectangleShape bkgd = setRectangle(sf::Vector2f(800,600),0,0,0,0, sf::Color::White);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
                vector<string> emptyVec;
                return emptyVec;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
                vector<string> emptyVec;
                return emptyVec;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
//                if (name.size() != 0){
//                    name[0] = toupper(name[0]);
//                    for (unsigned int i = 1; i < name.size(); i++){
//                        name[i] = tolower(name[i]);
//                    }
                    window.close();
                    vector<string> infoVec;
                    infoVec.push_back(name);
                    infoVec.push_back(make);
                    infoVec.push_back(model);
                    return infoVec;
//                }
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
                if (event.type == sf::Event::KeyPressed) {
                    if (name.size() != 0) {
                        name.resize(name.size() - 1);
                    }
                }
            }
            else if (event.type == sf::Event::TextEntered) {
//                if (isalpha(event.text.unicode)) { //This line gets rid of all non alphabet input.
                    if (name.size() < 20) {
                        if (event.text.unicode < 128) {
                            name += static_cast<char>(event.text.unicode);
                        }
                    }
//                }
            }
        }

        window.clear(sf::Color::White);
        window.draw(bkgd);
        printText("Welcome To Ticket Mistress!", true, width*16, 16 * height + 50 -150, &window, 24, true, true);

        printText("Your State: " + name +"|", false, width*16, 16 * height + 50 -75, &window, 18, true, true);
        printText("Your Car Make: "+make + "|", false, width*16, 16 * height + 50 , &window, 18, false, true);
        printText("Your Car Model: "+model + "|", false, width*16, 16 * height + 50 +75 , &window, 18, false, true);
        window.display();
    }
    vector<string> infoVect;
    infoVect.push_back(name);
    infoVect.push_back(make);
    infoVect.push_back(model);
    return infoVect;
};