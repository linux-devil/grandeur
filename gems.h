//
// Declarations for a gem resource class. This class holds gems of different
// colors (with YELLOW being a special wildcard color). These collections can
// be added, substracted, and compared based on the game rules.
//
// Created by eitan on 11/18/15.
//

#pragma once

#include <array>
#include <iosfwd>

namespace grandeur {

enum gem_color_t {
    WHITE = 0, TEAL = 1, GREEN = 2, RED = 3, BLACK = 4, YELLOW = 5
};

static constexpr char color2char[] = { 'W', 'T', 'G', 'R', 'B', 'Y' };

namespace {
using count_t = int8_t;  // We don't expect more than 127 gems of each color
}

class Gems {
  public:
    // Catch-all constructor for gems
    template <typename... T>
    constexpr Gems(T... args) : gems_{static_cast<count_t>(args)...} {}

    // How many gems we have in total (substracting negatives)
    int totalGems() const;

    // How many different gem colors have non-zero quantities?
    long totalColors() const;

    // Does any gem color appear in negative quantities?
    bool hasNegatives() const;

    // What is the maximum quantity of gems of any color?
    count_t maxQuantity() const;

    count_t getCount(gem_color_t color) const { return gems_.at(color); }

    friend std::ostream& operator<<(std::ostream&, const Gems&);

  private:
    std::array<count_t, 6> gems_;
};


}