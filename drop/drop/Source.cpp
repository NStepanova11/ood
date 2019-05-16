#include <SFML/Graphics.hpp>
#include "BasicButton.h"
#include "const.h"
#include "Panel.h"

using namespace sf;

int main()
{
	Panel panel;
	
	sf::RenderWindow window(sf::VideoMode(1027, 768), "SFMLworks");
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == Event::MouseButtonPressed && event.key.code == Mouse::Left) {
				Vector2i mousePos = Mouse::getPosition(window);
				if (panel.isInsideBounds(mousePos)) {
					BasicButton * activeButton = panel.getClickedButton(mousePos);
					panel.unselectAllButton();
					/*if (activeButton->isSelected())
						activeButton->unselectButton();
					else*/
						activeButton->selectButton();
					cout << activeButton->getFunctCode() << endl;
				}
			}
		}

		window.clear();
		panel.drawPanel(window);
		window.display();
	}
	return 0;
}