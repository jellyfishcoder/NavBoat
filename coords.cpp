#include "nav.h"

namespace Nav {
	Vec2::Vec2(float _x, float _y) : x(_x), y(_y) { }
	Vec2 Vec2::operator=(const Vec2& other) noexcept {
		 x = other.x;
		 y = other.y;
		 return *this;
	}
};
