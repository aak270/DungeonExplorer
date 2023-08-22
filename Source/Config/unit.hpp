#ifndef HEADER_UNIT
#define HEADER_UNIT

namespace unit {
	typedef unsigned int Tile;

	namespace {
		// One tile is 16 pixel
		const int TILE_SIZE = 16;
	}

	inline int tileToPixel(Tile tile) {
		return tile * TILE_SIZE;
	}
}

#endif