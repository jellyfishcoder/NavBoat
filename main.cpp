#include "nav.h"

int main(int argc, char** argv) {
	Nav::Sensors sensors();
	Nav::Navigator navigator(sensors);
	navigator.setCenter(Nav::Vec2(10.0f, 0.0f));
	Nav::Path path();
	path.restricted.push_back(Nav::CircleArea(navigator.getCenter, 2.5f));
	path.restricted.push_back(Nav::RectArea(Nav::Vec2(-0.1f, 0.0f), Nav::Vec2(-0.9f, navigator.getCenter.y)));
	path.setGoal(Nav::Vec2(-1.0f, 0.0f));
	path.compute();
	navigator.setPath(path);
	std::thread(&navigator::runPath, navigator);
	while(Nav::length(navigator.getPos() - navigator.getGoal()) > 0.5f) {
		if(navigator.isStuck() || navigator.isBadPath()) {
			path.setGoal(nagivator.getPosLog().at(nagivator.getPosLog().end - 5));
			//path.compute(
		}
	}
}
