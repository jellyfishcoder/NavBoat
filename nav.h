#ifndef _NAV_H
#define _NAV_H 1

#include <vector>

namespace Nav {
	class Navigator {
		friend class Nav::Sensors;
		friend class Nav::Path;
		public:
			Navigator(Nav::Sensors _sensors);
			Navigator() = default;
			virtual ~Navigator() = default;
			// Functions
			void setPath(Nav::Path _path);
			const Nav::Vec2 getGoal() const;
			Nav::Vec2 getPos() const;
			void runPath();
		private:
			std::vector<Nav::Vec2> posLog;
			Path path;
	};

	class Sensors {

	};

	class Path {

	};

	struct Vec2 {
		Vec2(float _x, float _y);
		Vec2() = default;
		float x, y;
	};
};

#endif//_NAV_H
