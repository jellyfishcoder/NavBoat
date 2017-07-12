#ifndef _NAV_H
#define _NAV_H 1

#include <vector>
#include <memory>

namespace Nav {
	struct Vec2 {
		Vec2(float _x, float _y);
		Vec2() = default;
		float x, y;
		Vec2 operator+(const Vec2& other);
		Vec2 operator=(const Vec2& other) noexcept;
	};
	inline bool operator==(const Vec2& lhs, const Vec2& rhs) { return (lhs.x == rhs.x && lhs.y == rhs.y); }
	inline bool operator!=(const Vec2& lhs, const Vec2& rhs) { return lhs != rhs; }

	class Area {
		public:
			virtual ~Area() =0;
			virtual bool contains(Nav::Vec2 point) =0;
			virtual Nav::Area& intesects(const Area& other) =0;
	};

	class CircleArea: public Area {
		public:
			CircleArea(Nav::Vec2 _centre, float _radius);
			virtual ~CircleArea();
			virtual bool contains(Nav::Vec2 point);
		private:
			Nav::Vec2 centre;
			float radius;
	};

	class PolyArea: public Area {
		public:
			virtual ~PolyArea();
			virtual bool contains(Nav::Vec2 point);
			virtual Nav::Area& intersects(const Area& other);
		private:
			std::vector<Nav::Vec2> points;
	};

	class Sensors {
		
	};

	class Path {
		public:
			void setRestricted(const std::vector<std::unique_ptr<Nav::Area> > _restricted);
			void compute();
		private:
			std::vector<std::unique_ptr<Nav::Area> > restricted;
	};

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
			Nav::Path path;
	};
}

#endif//_NAV_H
