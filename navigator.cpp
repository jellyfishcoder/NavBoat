#include "nav.h"

namespace Nav {
	Navigator::Navigator(Nav::Sensors _sensors) {
		this->sensors = _sensors;
		this->sensors.reset();
	}
	void Navigator::setPath(Nav::Path path) {
		this->path = _path;
	}
	const Nav::Vec2 Navigator::getGoal() const {
		return this->path.goal;
	}
};
