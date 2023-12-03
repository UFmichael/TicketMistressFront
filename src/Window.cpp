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
    if (!font.loadFromFile("../TicketMistressFront/src/font.ttf")){
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

    std::vector<std::string> statesList = {
            "Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware",
            "Florida", "Georgia", "Hawaii", "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky",
            "Louisiana", "Maine", "Maryland", "Massachusetts", "Michigan", "Minnesota", "Mississippi", "Missouri",
            "Montana", "Nebraska", "Nevada", "New Hampshire", "New Jersey", "New Mexico", "New York",
            "North Carolina", "North Dakota", "Ohio", "Oklahoma", "Oregon", "Pennsylvania", "Rhode Island",
            "South Carolina", "South Dakota", "Tennessee", "Texas", "Utah", "Vermont", "Virginia", "Washington",
            "West Virginia", "Wisconsin", "Wyoming"
    };

    std::vector<std::string> makesList = {
            "Florida", "Georgia", "Hawaii", "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky",
            "Louisiana", "Maine", "Maryland", "Massachusetts", "Michigan", "Minnesota", "Mississippi", "Missouri",
            "Montana", "Nebraska", "Nevada", "New Hampshire", "New Jersey", "New Mexico", "New York",
            "North Carolina", "North Dakota", "Ohio", "Oklahoma", "Oregon", "Pennsylvania", "Rhode Island",
            "South Carolina", "South Dakota", "Tennessee", "Texas", "Utah", "Vermont", "Virginia", "Washington",
            "West Virginia", "Wisconsin", "Wyoming"
    };

    std::vector<std::string> modelsList = {
            "North Carolina", "North Dakota", "Ohio", "Oklahoma", "Oregon", "Pennsylvania", "Rhode Island",
            "South Carolina", "South Dakota", "Tennessee", "Texas", "Utah", "Vermont", "Virginia", "Washington",
            "West Virginia", "Wisconsin", "Wyoming"
    };

    std::vector<std::string> colorsList = {
            "Blue", "Black", "Red", "Yellow", "Yellow1", "Yellow2", "Yellow3", "Yellow4"
    };



    int curr = 0;
    int listIndex = 0;
    string name = "";
    string make = "";
    string model = "";
    string color = "";
    vector<string> infoVec = {name, make, model, color};
    int infoType = -1;
    int width = 25;
    int height = 16;
    bool selected = false;
    bool stateSelection = false;
    bool makeSelection = false;
    bool modelSelection = false;
    bool colorSelection = false;
    sf::RenderWindow window(sf::VideoMode(32*width, 32*height+100), "Ticket Mistress", sf::Style::Close);
    window.setFramerateLimit(60);
    sf::RectangleShape bkgd = setRectangle(sf::Vector2f(800,600),0,0,0,0, sf::Color::White);

    sf::RectangleShape StateBox;//= sf::Rect(400, 350, 100, 50);
    StateBox.setPosition(200, 210-100);
    StateBox.setSize(sf::Vector2f(400,50));
    //StateBox.setFillColor(sf::Color::Black);
    StateBox.setOutlineColor(sf::Color::Black);
    StateBox.setOutlineThickness(10);

    sf::RectangleShape MakeBox;//= sf::Rect(400, 350, 100, 50);
    MakeBox.setPosition(200, 285-100);
    MakeBox.setSize(sf::Vector2f(400,50));
    //MakeBox.setFillColor(sf::Color::Black);
    MakeBox.setOutlineColor(sf::Color::Black);
    MakeBox.setOutlineThickness(10);

    sf::RectangleShape ModelBox;//= sf::Rect(400, 350, 100, 50);
    ModelBox.setPosition(200, 360-100);
    ModelBox.setSize(sf::Vector2f(400,50));
    //ModelBox.setFillColor(sf::Color::Black);
    ModelBox.setOutlineColor(sf::Color::Black);
    ModelBox.setOutlineThickness(10);

    sf::RectangleShape ColorBox;//= sf::Rect(400, 350, 100, 50);
    ColorBox.setPosition(200, 435-100);
    ColorBox.setSize(sf::Vector2f(400,50));
    ColorBox.setOutlineColor(sf::Color::Black);
    ColorBox.setOutlineThickness(10);

    std::vector<sf::RectangleShape> statesBox, modelsBox, makesBox, colorsBox;

    sf::Font font;
    if (!font.loadFromFile("../TicketMistressFront/src/font.ttf")){
        throw("Font broke");
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
//            if(infoType = 0){
//                stateSelection = true;
//                makeSelection = false;
//                modelSelection = false;
//            }else if(infoType = 1){
//                stateSelection = false;
//                makeSelection = true;
//                modelSelection = false;
//            }else if(infoType = 2){
//                stateSelection = false;
//                makeSelection = false;
//                modelSelection = true;
//            }else{
//                stateSelection = false;
//                makeSelection = false;
//                modelSelection = false;
//            }
//
            if(stateSelection){
                statesBox.clear();

                for(int i = 0; i < 5; i++) {
                    sf::RectangleShape outlineBox;//= sf::Rect(400, 350, 100, 50);
                    outlineBox.setPosition(200, 260 + 50*i-100);
                    outlineBox.setSize(sf::Vector2f(400, 50));
                    outlineBox.setOutlineColor(sf::Color::Black);
                    outlineBox.setOutlineThickness(5);
                    statesBox.push_back(outlineBox);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && event.type == sf::Event::KeyPressed) {
                    if(listIndex+5 != statesList.size()) {
                        listIndex++;
                    }
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && event.type == sf::Event::KeyPressed) {
                    if(listIndex != 0) {
                        listIndex--;
                    }
                }
                auto position = sf::Mouse::getPosition(window);
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && infoType == 0) {
                    for (int i = 0; i < statesBox.size(); i++) {
                        if (statesBox[i].getGlobalBounds().contains(position.x, position.y)) {
                            name = statesList[i + listIndex];
                            stateSelection = false;
                            selected = false;
                            infoType = -1;
                        }
                    }
                    //listIndex = 0;
                }
            }

            if(makeSelection){
                makesBox.clear();

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && event.type == sf::Event::KeyPressed) {
                    //states list should be changed to make list

                    if(listIndex+5 != makesList.size()) {
                        listIndex++;
                    }
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && event.type == sf::Event::KeyPressed) {
                    if(listIndex != 0) {
                        listIndex--;
                    }
                }

                for(int i = 0; i < 5; i++) {
                    sf::RectangleShape outlineBox;//= sf::Rect(400, 350, 100, 50);
                    outlineBox.setPosition(200, 335 + 50*i-100);
                    outlineBox.setSize(sf::Vector2f(400, 50));
                    outlineBox.setOutlineColor(sf::Color::Black);
                    outlineBox.setOutlineThickness(5);
                    makesBox.push_back(outlineBox);

                    auto position = sf::Mouse::getPosition(window);
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && infoType == 1) {
                        //makesbox.size()
                        for (int i = 0; i < makesBox.size(); i++) {
                            //makesBox[i]
                            if (makesBox[i].getGlobalBounds().contains(position.x, position.y)) {
                                //mfake = makesBox[]
                                make = makesList[i + listIndex];
                                makeSelection = false;
                                selected = false;
                                infoType = -1;
                            }
                        }
                        //listIndex = 0;
                    }
                }
            }

            if(modelSelection){
                modelsBox.clear();
                for(int i = 0; i < 5; i++) {
                    sf::RectangleShape outlineBox;//= sf::Rect(400, 350, 100, 50);
                    outlineBox.setPosition(200, 415 + 50*i-100);
                    outlineBox.setSize(sf::Vector2f(400, 50));
                    outlineBox.setOutlineColor(sf::Color::Black);
                    outlineBox.setOutlineThickness(5);
                    modelsBox.push_back(outlineBox);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && event.type == sf::Event::KeyPressed) {
                    //states list should be changed to model list

                    if(listIndex+5 != modelsList.size()) {
                        listIndex++;
                    }
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && event.type == sf::Event::KeyPressed) {
                    if(listIndex != 0) {
                        listIndex--;
                    }
                }
                auto position = sf::Mouse::getPosition(window);
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && infoType == 2) {
                    //modelsbox.size()
                    for (int i = 0; i < modelsBox.size(); i++) {
                        //modelsBox[i]
                        if (modelsBox[i].getGlobalBounds().contains(position.x, position.y)) {
                            //mfake = modelsBox[]
//                            std::cout << listIndex << std::endl;
                            model = modelsList[i + listIndex];
                            modelSelection = false;
                            selected = false;
                            infoType = -1;
                        }
                    }
                    //listIndex = 0;
                }
            }

            if(colorSelection){
                colorsBox.clear();
                for(int i = 0; i < 4; i++) {
                    sf::RectangleShape outlineBox;//= sf::Rect(400, 350, 100, 50);
                    outlineBox.setPosition(200, 495 + 50*i-100);
                    outlineBox.setSize(sf::Vector2f(400, 50));
                    outlineBox.setOutlineColor(sf::Color::Black);
                    outlineBox.setOutlineThickness(5);
                    colorsBox.push_back(outlineBox);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && event.type == sf::Event::KeyPressed) {
                    //states list should be changed to model list

                    if(listIndex+4 != colorsList.size()) {
                        listIndex++;
                    }
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && event.type == sf::Event::KeyPressed) {
                    if(listIndex != 0) {
                        listIndex--;
                    }
                }
                auto position = sf::Mouse::getPosition(window);
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && infoType == 3) {
                    //colorsbox.size()
                    for (int i = 0; i < colorsBox.size(); i++) {
                        if (colorsBox[i].getGlobalBounds().contains(position.x, position.y)) {
                            //mfake = modelsBox[]
//                            std::cout << listIndex << std::endl;
                            color = colorsList[i + listIndex];
                            colorSelection = false;
                            selected = false;
                            infoType = -1;
                        }
                    }
                    //listIndex = 0;
                }
            }

            if (event.type == sf::Event::Closed) {
                window.close();
                vector<string> emptyVec;
                return emptyVec;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
                vector<string> emptyVec;
                return emptyVec;
            }

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){

                auto position = sf::Mouse::getPosition(window);
                listIndex = 0;
                if(StateBox.getGlobalBounds().contains(position.x, position.y)){
                    infoType = 0;
                    stateSelection = true;
                    makeSelection = false;
                    modelSelection = false;
                    colorSelection = false;
                }
                else if(MakeBox.getGlobalBounds().contains(position.x, position.y)){
                    infoType = 1;
                    stateSelection = false;
                    makeSelection = true;
                    modelSelection = false;
                    colorSelection = false;
                }
                else if(ModelBox.getGlobalBounds().contains(position.x, position.y)){
                    infoType = 2;
                    stateSelection = false;
                    makeSelection = false;
                    modelSelection = true;
                    colorSelection = false;
                }
                else if(ColorBox.getGlobalBounds().contains(position.x, position.y)){
                    infoType = 3;
                    stateSelection = false;
                    makeSelection = false;
                    modelSelection = false;
                    colorSelection = true;
                }
                else{
                    infoType = -1;
                    stateSelection = false;
                    makeSelection = false;
                    modelSelection = false;
                    colorSelection = false;
                }
                // in any of the text rectangles
                //listIndex = 0;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && event.type == sf::Event::KeyPressed) {
                infoVec[0] = name;
                infoVec[1] = make;
                infoVec[2] = model;
                infoVec[3] = color;
                SecondScreen(infoVec, window);
            }
        }

        window.clear(sf::Color::White);
        window.draw(bkgd);
        window.draw(StateBox);
        window.draw(MakeBox);
        window.draw(ModelBox);
        window.draw(ColorBox);

        printText("Welcome To Ticket Mistress!", true, width*16, 16 * height + -100-100, &window, 24, true, true);

        if(infoType == 0){
            printText("Your State: " + name +"|", false, width*16, 16 * height + 50 -75-100, &window, 18, true, true);
        }else{
            printText("Your State: " + name, false, width*16, 16 * height + 50 -75-100, &window, 18, true, true);
        }

        if(infoType == 1){
            printText("Your Car Make: "+make+"|", false, width*16, 16 * height + 50-100 , &window, 18, false, true);
        }else{
            printText("Your Car Make: "+make, false, width*16, 16 * height + 50-100 , &window, 18, false, true);
        }

        if(infoType == 2){
            printText("Your Car Model: "+model+"|", false, width*16, 16 * height + 50 +75-100 , &window, 18, false, true);
        }else{
            printText("Your Car Model: "+model, false, width*16, 16 * height + 50 +75-100 , &window, 18, false, true);
        };

        if(infoType == 3){
            printText("Your Car Color: "+color+"|", false, width*16, 16 * height + 100 , &window, 18, false, true);
        }else{
            printText("Your Car Color: "+color, false, width*16, 16 * height + 100 , &window, 18, false, true);
        };

        if(!selected && infoType == 0){
            for(auto nextState : statesBox){
                window.draw(nextState);
            }
            for(int i = 0; i < 5; i++){
                printText(statesList[i + listIndex], false, 400, 50 * i + 280-100, &window, 18, true, true);
            }
        }
        if(!selected && infoType == 1){
            for(auto nextMake : makesBox){
                window.draw(nextMake);
            }
            for (int i = 0; i < 5; i++) {
                //edit for make location
                //states list changed to make list
                printText(makesList[i + listIndex], false, 400, 50 * i + 350-100, &window, 18, true, true);
            }
        }
        //working on this one
        if(!selected && infoType == 2){
            for(auto nextModel : modelsBox){
                window.draw(nextModel);
            }
            for (int i = 0; i < 5; i++) {
                //edit for make location
                //states list changed to model list
                printText(modelsList[i + listIndex], false, 400, 50 * i + 430-100, &window, 18, true, true);
            }
        }

        if(!selected && infoType == 3){
            for(auto nextColor : colorsBox){
                window.draw(nextColor);
            }
            for (int i = 0; i < 4; i++) {
                //edit for make location
                //states list changed to model list
                printText(colorsList[i + listIndex], false, 400, 50 * i + 510-100, &window, 18, true, true);
            }
        }

        window.display();
    }
    infoVec[0] = name;
    infoVec[1] = make;
    infoVec[2] = model;
    infoVec[3] = color;
    return infoVec;
}

void namesToPics(){

}

void Window::SecondScreen(vector<string>& infoVec, sf::RenderWindow& window) {
    vector<vector<string>> data;
    data = {{"florida", "toyota", "four door", "blue", "2:37pm"},{"florida", "toyota", "four door", "blue", "2:38pm"},{"florida", "toyota", "four door", "blue", "2:39pm"},{"florida", "toyota", "four door", "blue", "2:30pm"},{"florida", "toyota", "four door", "blue", "2:31pm"},{"florida", "toyota", "four door", "blue", "2:32pm"},{"florida", "toyota", "four door", "blue", "2:33pm"},{"florida", "toyota", "four door", "blue", "2:34pm"}};
    int curr = 0;
    int scrollVal = 0;
    while(window.isOpen()){
        window.clear(sf::Color::White);
        sf::Event event;
        int max = 5;
        if(data.size() < max){
            max = data.size();
        }
        for(int i = 0; i < max; i++) {
            sf::RectangleShape outlineBox;//= sf::Rect(400, 350, 100, 50);
            outlineBox.setPosition(100, 40 + 70*i);
            outlineBox.setSize(sf::Vector2f(600, 50));
            outlineBox.setOutlineColor(sf::Color::Black);
            outlineBox.setOutlineThickness(5);
            if(i == curr){
                outlineBox.setOutlineThickness(10);
            }
            window.draw(outlineBox);

            string infoString1 = "";
            string infoString2 = "";
            for(int j = 0; j < data[scrollVal+i].size(); j++){
                if(j == 0){
                    infoString1 += "State: ";
                    infoString1 += data[scrollVal+i][j];
                    infoString1 += "\t";
                }
                else if(j == 1){
                    infoString1 += "Make: ";
                    infoString1 += data[scrollVal+i][j];
                    infoString1 += "\t";
                }
                else if(j == 2){
                    infoString1 += "Model: ";
                    infoString1 += data[scrollVal+i][j];
                }
                else if(j == 3){
                    infoString2 += "Color: ";
                    infoString2 += data[scrollVal+i][j];
                    infoString2 += "\t";
                }
                else if(j == 4){
                    infoString2 += "Time: ";
                    infoString2 += data[scrollVal+i][j];
                }
                else{
                    std::cout << "Error" << "\n";
                }

            }
            printText(infoString1, false, 400, 55+ i*70 , &window, 18, false, true);
            printText(infoString2, false, 400, 75+ i*70 , &window, 18, false, true);
        }

        printText(to_string(1+curr + scrollVal)+"\/" + to_string(data.size()), false, 400, 75+ max*70 -30 , &window, 18, false, true);

        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && event.type == sf::Event::KeyPressed) {
                if(curr <4) {
                    curr++;
                }else{
                    if(scrollVal + 2 != max){
                        scrollVal++;
                    }
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && event.type == sf::Event::KeyPressed) {
                if(curr > 0) {
                    curr--;
                }else{
                    if(scrollVal != 0){
                        scrollVal--;
                    }
                }

            }
        }
        window.display();
    }

};