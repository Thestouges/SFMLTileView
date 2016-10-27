#include "drawMap.h"

drawMap::drawMap(){
	initValues();
	openWindow();
}

void drawMap::initValues(){
	viewAmount = 10;
	tileAmount = sf::Vector2i(23,21);
	if(!tileset.loadFromFile("tileset.png")){
	}
	tilesprite.setTexture(tileset);
	tilefullSize.x = tilesprite.getGlobalBounds().width;
	tilefullSize.y = tilesprite.getGlobalBounds().height;
	atileSize.x = tilefullSize.x/23;
	atileSize.y = tilefullSize.y/21;

	view.reset(sf::FloatRect(0,0,atileSize.x*viewAmount,atileSize.y*viewAmount));
	viewCenter = view.getCenter();
	view.setCenter(viewCenter);

	viewSize = view.getSize();

	if(!font.loadFromFile("times.ttf")){
	}

	text.setFont(font);

	windowSize = sf::Vector2i(atileSize.x*viewAmount,atileSize.y*viewAmount);
}

void drawMap::openWindow(){
	window.create(sf::VideoMode(windowSize.x, windowSize.y), "TileMap");

	while (window.isOpen())
    {
		while (window.pollEvent(Event))
        {
			if (Event.type == sf::Event::Closed)
                window.close();
        }

		window.clear();
		setView();
		window.setView(view);
		drawGrid();
		window.display();
    }

}

void drawMap::drawGrid(){
	text.setFillColor(sf::Color::Red);
	text.setPosition(0,0);
	text.setCharacterSize(12);
	counter = 1;
	position = (sf::Vector2f(0,0));
	for(int i = 0; i < getGridSize(); i++){
		for(int j = 0; j < getGridSize(); j++){
			if(getTileValue(i, j) >= 0 && getTileValue(i, j) < 30)//grass
				tilesprite.setTextureRect(sf::IntRect(0,0,atileSize.x, atileSize.y)); 
			else if(getTileValue(i, j) >= 30 && getTileValue(i, j) < 50)//tree
				tilesprite.setTextureRect(sf::IntRect(0,atileSize.y,atileSize.x, atileSize.y*2));
			else if(getTileValue(i, j) >= 50 && getTileValue(i, j) < 70)//water
				tilesprite.setTextureRect(sf::IntRect(atileSize.x*22,atileSize.y*3,atileSize.x*23, atileSize.y*4));
			else if(getTileValue(i, j) >= 70 && getTileValue(i, j) < 80)//mountain
				tilesprite.setTextureRect(sf::IntRect(atileSize.x*6,atileSize.y*11,atileSize.x*7, atileSize.y*12));
			else if(getTileValue(i, j) >= 80 && getTileValue(i, j) < 90)//deadtrees
				tilesprite.setTextureRect(sf::IntRect(atileSize.x*1,atileSize.y*15,atileSize.x*2, atileSize.y*16));
			else if(getTileValue(i, j) >= 90 && getTileValue(i, j) < 95)//lava
				tilesprite.setTextureRect(sf::IntRect(atileSize.x*4,atileSize.y*4,atileSize.x*5, atileSize.y*5));
			else if(getTileValue(i, j) >= 95 && getTileValue(i, j) < 100)//ripple
				tilesprite.setTextureRect(sf::IntRect(atileSize.x*12,atileSize.y*15,atileSize.x*13, atileSize.y*16));
			
			tilesprite.setPosition(position.x, position.y);
			window.draw(tilesprite);

			text.setString(std::to_string(counter));
			window.draw(text);
			counter++;

			position.x += atileSize.x;
			text.setPosition(position.x, position.y);
		}
		position.y += atileSize.y;
		position.x = 0;
		text.setPosition(position.x, position.y);
	}
}

void drawMap::setView(){
	viewCenter = view.getCenter();
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && viewCenter.x + viewSize.x/2 < getGridSize()*atileSize.x){
		view.move(atileSize.x,0);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && viewCenter.x - viewSize.x/2 > 0){
		view.move(-atileSize.x,0);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && viewCenter.y - viewSize.y/2 > 0){
		view.move(0,-atileSize.y);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && viewCenter.y + viewSize.y/2 < getGridSize()*atileSize.y){
		view.move(0,atileSize.y);
	}
}