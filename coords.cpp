#include "nav.h"

namespace Nav {
	Vec2::Vec2(float _x, float _y) : x(_x), y(_y) { }
	Vec2 Vec2::operator=(const Vec2& other) noexcept {
		 x = other.x;
		 y = other.y;
		 return *this;
	}
	/* These operators are not correctly implemented,
	 * but it doesnt really matter now anyways.
	 */
	Vec2 Vec2::operator*(float s) const noexcept {
		return Vec2(x * s, y * s);
	}
	Vec2 operator*(const Vec2& v, float s) noexcept {
		return v * s;
	}
	Vec2 operator*(float s, const Vec2& v) noexcept {
		return v * s;
	}

	PolyArea::PolyArea() {
		this->points = std::vector<Nav::Vec2>();
	}
	PolyArea::PolyArea(const CircleArea& area, unsigned int resolution) {
		float angle = ( 2 * M_PI ) / resolution;
		for(unsigned int i = 0; i < resolution; i++) {
			Nav::Vec2 outer = area.radius * Nav::Vec2(cos(angle * i), sin(angle * i));
			this->points.push_back(outer + area.centre);
		}
	}
	// Raycast container algorithm
	bool PolyArea::contains(const Nav::Vec2& point) const {
		bool b = false;
		unsigned int i, j = 0;
		for(i = 0, j = this->points.size(); i < this->points.size(); j = i++) {
			if(((this->points[i].y > point.y) != (this->points[j].y > point.y)) && (point.x < (this->points[j].x - this->points[i].x) * (point.y - this->points[i].y) / (this->points[j].y - this->points[i].y) + this->points[i].x))
				b = !b;
		}
		return b;
	}

	CircleArea::CircleArea(const Nav::Vec2& _centre, float _radius) : centre(_centre), radius(_radius) {}
	bool CircleArea::contains(const Nav::Vec2& point) const {
		return (pow(point.x - this->centre.x, 2) + pow(point.y - this->centre.y, 2) < pow(this->radius, 2));
	}
}
