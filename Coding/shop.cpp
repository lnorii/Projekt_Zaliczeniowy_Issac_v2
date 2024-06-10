#include "shop.hpp"

// Konstruktor klasy Shop
Shop::Shop(sf::Texture& tloTexture, std::shared_ptr<Player> player)
    : player(player), aktywny(false), click(false) {

    // Załaduj czcionkę z pliku
    if (!font.loadFromFile("C:\\Users\\trole\\OneDrive\\Dokumenty\\GitHub\\Projekt_Zaliczeniowy_Issac_v2\\src\\textures\\arial.ttf")) {
        std::cerr << "Failed to load font\n";
    }

    // Ustawienia tekstu dla opcji leczenia
    healText.setFont(font);
    healText.setString("1 - Heal: 50");
    healText.setPosition(100, 100);

    // Ustawienia tekstu dla opcji zwiększenia szybkości
    speedText.setFont(font);
    speedText.setString("2 - Speed: 100");
    speedText.setPosition(100, 200);

    // Ustawienia tekstu dla opcji zwiększenia obrażeń
    damageText.setFont(font);
    damageText.setString("3 - Damage: 100");
    damageText.setPosition(100, 300);

    // Ustawienia tekstu dla opcji zwiększenia szybkości strzału
    fireRateText.setFont(font);
    fireRateText.setString("4 - Fire Rate: 100");
    fireRateText.setPosition(100, 400);

    // Ustawienia tekstu dla opcji wyjścia ze sklepu
    exitText.setFont(font);
    exitText.setString("Tab - Exit Shop");
    exitText.setPosition(100, 500);

    // Ustawienia tekstu dla salda (bilansu)
    saldoText.setFont(font);
    saldoText.setPosition(100, 50);

    // Ustawienia tekstu dla wiadomości-potwierdzenie zakupu lub braku środków
    messageText.setFont(font);
    messageText.setPosition(100, 600);
    messageText.setFillColor(sf::Color::Red);

    // Ustawienia tła sklepu
    tloSprite.setTexture(tloTexture);
    tloSprite.setScale(1920.f / tloTexture.getSize().x, 1080.f / tloTexture.getSize().y);
}

// Rysowanie elementów sklepu na ekranie
void Shop::draw(sf::RenderTarget& target, sf::RenderStates states) const  {
    if (aktywny) {
        // Aktualizacja tekstu salda gracza
        saldoText.setString("Saldo: " + std::to_string(player->getgold()));
        // Rysowanie tła i elementów tekstowych sklepu
        target.draw(tloSprite);
        target.draw(saldoText);
        target.draw(healText);
        target.draw(speedText);
        target.draw(damageText);
        target.draw(fireRateText);
        target.draw(exitText);
        target.draw(messageText);
    }
}

// Obsługa zdarzeń klawiatury
void Shop::handleEvent(const sf::Keyboard::Key& key) {
    if (aktywny && !click) {

        messageText.setString("");
        // Obsługa zakupu leczenia
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
            cout << "wciskam 1" << endl;
            if (player->getgold() >= 50) {
                player->getgold() -= 50;
                player->heal();
                messageText.setString("Purchased Heal!");
            } else {
                messageText.setString("Not enough funds!");
            }
        }
        // Obsługa zakupu zwiększenia szybkości
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
            if (player->getgold() >= 100) {
                player->getgold() -= 100;
                player->getspeed() += 30;
                messageText.setString("Purchased Speed Upgrade!");
            } else {
                messageText.setString("Not enough funds!");
            }
        }
        // Obsługa zakupu zwiększenia obrażeń
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
            if (player->getgold() >= 100) {
                player->getgold() -= 100;
                player->getdmg() += 5;
                messageText.setString("Purchased Damage Upgrade!");
            } else {
                messageText.setString("Not enough funds!");
            }
        }
        // Obsługa zakupu zwiększenia szybkości strzału
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
            if (player->getgold() >= 100) {
                player->getgold() -= 100;
                player->gettime_between_atack() -= 0.1f;
                messageText.setString("Purchased Fire Rate Upgrade!");
            } else {
                messageText.setString("Not enough funds!");
            }
        }
        // Obsługa wyjścia ze sklepu
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
            aktywny = false;
            cout << "klikam tab" << endl;
        }
    }
    // Zapobieganie wielokrotnemu rejestrowaniu kliknięć klawiszy
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
        click = true;
    } else {
        click = false;
    }
}
