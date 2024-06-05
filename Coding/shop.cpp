#include "shop.hpp"

Shop::Shop(sf::Texture& tloTexture,std::shared_ptr<Player> player) : player(player), aktywny(false) {
        if (!font.loadFromFile("C:\\Users\\trole\\OneDrive\\Dokumenty\\GitHub\\Projekt_Zaliczeniowy_Issac_v2\\src\\textures\\arial.ttf")) {
            std::cerr << "Failed to load font\n";
        }

        healText.setFont(font);
        healText.setString("1 - Heal: 50");
        healText.setPosition(100, 100);

        speedText.setFont(font);
        speedText.setString("2 - Speed: 100");
        speedText.setPosition(100, 200);

        damageText.setFont(font);
        damageText.setString("3 - Damage: 100");
        damageText.setPosition(100, 300);

        fireRateText.setFont(font);
        fireRateText.setString("4 - Fire Rate: 100");
        fireRateText.setPosition(100, 400);

        exitText.setFont(font);
        exitText.setString("Tab - Exit Shop");
        exitText.setPosition(100, 500);

        saldoText.setFont(font);
        saldoText.setPosition(100, 50);

        messageText.setFont(font);
        messageText.setPosition(100, 600);
        messageText.setFillColor(sf::Color::Red);

        tloSprite.setTexture(tloTexture);
        tloSprite.setScale(1920.f / tloTexture.getSize().x, 1080.f / tloTexture.getSize().y);
    }

void Shop::draw(sf::RenderTarget& target, sf::RenderStates states) const  {
        if (aktywny) {
            saldoText.setString("Saldo: " + std::to_string(player->getgold()));
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

void Shop::handleEvent(const sf::Keyboard::Key& key) {
        if (aktywny) {
            messageText.setString("");  // Clear previous messages
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
                cout << "wciskam 1"<<endl;
                if (player->getgold() >= 50) {
                    player->getgold() -= 50;
                    player->heal();
                    messageText.setString("Purchased Heal!");
                } else {
                    messageText.setString("Not enough funds!");
                }
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
                if (player->getgold() >= 100) {
                    player->getgold() -= 100;
                    player->getspeed() += 30;
                    messageText.setString("Purchased Speed Upgrade!");
                } else {
                    messageText.setString("Not enough funds!");
                }
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
                if (player->getgold() >= 100) {
                    player->getgold() -= 100;
                    player->getdmg() += 5;
                    messageText.setString("Purchased Damage Upgrade!");
                } else {
                    messageText.setString("Not enough funds!");
                }
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
                if (player->getgold() >= 100) {
                    player->getgold() -= 100;
                    player->gettime_between_atack() -= 0.1f;
                    messageText.setString("Purchased Fire Rate Upgrade!");
                } else {
                    messageText.setString("Not enough funds!");
                }
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
                aktywny = false;
                cout<<"klikam tab"<<endl;
            }
        }
    }