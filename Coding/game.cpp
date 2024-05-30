#include "game.hpp"
#include "game_menager.hpp"
#include "object_menager.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>




game::game(object_menager& om) : om(om) {
}

game::~game(){
}

void game::run(bool shop,bool death, bool wave){
    if (shop==false&&death==false&&wave==false)
    {
        std::vector<std::unique_ptr<sf::Drawable>> shapes;
        om.load_obj("C:\\Users\\trole\\OneDrive\\Dokumenty\\GitHub\\Projekt_Zaliczeniowy_Issac_v2\\src\\textures\\guy.png", {100.f, 150.f}, shapes);
        display(shapes);
    }
    else
    {
        cout<<"nie można załadować tekstur"<<endl;
    }
    
}

void game::display(const std::vector<std::unique_ptr<sf::Drawable>>& shapes){

    sf::RenderWindow window(sf::VideoMode(), "SFML works!", sf::Style::Fullscreen);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)    
                window.close();
        }

        window.clear();

        for (const auto& shape : shapes) {
            window.draw(*shape);
        }

        window.display();
    }
}

int main(){
object_menager om;
game_menager gm;

game g(om);
g.run(gm.shop(),gm.death(),gm.wave());
    return 0;
}
