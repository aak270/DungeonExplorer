#ifndef HEADER_UNIT
#define HEADER_UNIT

namespace unit {
	typedef unsigned int Tile;

	namespace {
		// One tile is 32 pixel
		const int TILE_SIZE = 32;
	}

	inline int tileToPixel(Tile tile) {
		return tile * TILE_SIZE;
	}
}

#endif