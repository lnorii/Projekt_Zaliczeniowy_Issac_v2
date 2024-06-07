#include "Ranking.hpp"

Ranking::Ranking(const sf::Vector2u& windowSize) 
    : filename("C:\\Users\\trole\\OneDrive\\Dokumenty\\GitHub\\Projekt_Zaliczeniowy_Issac_v2\\src\\ranking.txt"), 
      backgroundFilename("C:\\Users\\trole\\OneDrive\\Dokumenty\\GitHub\\Projekt_Zaliczeniowy_Issac_v2\\src\\textures\\ranking.png"),
      windowSize(windowSize) {
    values = readFromFile();
    sortVector();

    if (!texture.loadFromFile(backgroundFilename)) {
        throw std::runtime_error("Could not load background texture");
    }
    texture.setRepeated(true);
    background.setTexture(texture);
    background.setTextureRect(sf::IntRect(0, 0, windowSize.x, windowSize.y));

    if (!font.loadFromFile("C:\\Users\\trole\\OneDrive\\Dokumenty\\GitHub\\Projekt_Zaliczeniowy_Issac_v2\\src\\textures\\arial.ttf")) {
        throw std::runtime_error("Could not load font");
    }

    gameOverText.setFont(font);
    gameOverText.setString("Game Over");
    gameOverText.setCharacterSize(48);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(windowSize.x / 2 - gameOverText.getGlobalBounds().width / 2, 20);

    title.setFont(font);
    title.setString("Ranking");
    title.setCharacterSize(36);
    title.setFillColor(sf::Color::White);
    title.setPosition(windowSize.x / 2 - title.getGlobalBounds().width / 2, 100);

    exitText.setFont(font);
    exitText.setString("Press Enter to exit");
    exitText.setCharacterSize(24);
    exitText.setFillColor(sf::Color::White);
    exitText.setPosition(windowSize.x / 2 - exitText.getGlobalBounds().width / 2, windowSize.y - 50);

    updateTextResults();
}

void Ranking::writeToFile(int value) {
    std::ofstream file(filename, std::ios_base::app);
    if (file.is_open()) {
        file << value << "\n";
        file.close();
    }
    // Update values vector after writing to file
    values = readFromFile();
    sortVector();
    updateTextResults();
}

void Ranking::updateResults() {
    values = readFromFile();
    sortVector();
    updateTextResults();
}

std::vector<int> Ranking::readFromFile() {
    std::vector<int> values;
    std::ifstream file(filename);
    if (file.is_open()) {
        int value;
        while (file >> value) {
            values.push_back(value);
        }
        file.close();
    }
    return values;
}

void Ranking::sortVector() {
    std::sort(values.begin(), values.end(), std::greater<int>());
}

void Ranking::updateTextResults() {
    textResults.clear();
    for (size_t i = 0; i < std::min<size_t>(5, values.size()); ++i) {
        sf::Text text;
        text.setFont(font);
        text.setString(std::to_string(values[i]));
        text.setCharacterSize(36);
        text.setFillColor(sf::Color::Black);
        text.setPosition(windowSize.x / 2 - text.getGlobalBounds().width / 2, i * 60 + 180);

        textResults.push_back(text);
    }
}

void Ranking::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(background, states);
    target.draw(gameOverText, states);
    target.draw(title, states);
    for (const auto& text : textResults) {
        target.draw(text, states);
    }
    target.draw(exitText, states);
}
