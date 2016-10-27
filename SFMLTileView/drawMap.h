#include <string>
#include <iostream>
#include <SFML\Graphics.hpp>
#include "theMap.h"

class drawMap : public theMap{
public:
	drawMap();
	void initValues();
	void openWindow();
	void setView();
	void drawGrid();
private:
	sf::Vector2i windowSize;
	sf::RenderWindow window;
	sf::Event Event;
	std::string stext;
	sf::Texture tileset;
	sf::Sprite tilesprite;
	sf::Vector2i tileAmount;
	sf::Vector2f atileSize;
	sf::Vector2f tilefullSize;
	sf::Vector2f position;
	sf::View view;
	sf::Vector2f viewCenter;
	sf::Vector2f viewSize;
	int viewAmount;
	sf::Text text;
	sf::Font font;
	int counter;
};