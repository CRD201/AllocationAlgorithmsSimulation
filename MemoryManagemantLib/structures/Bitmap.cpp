#pragma once

#include <bitset>

#include "Bitmap.hpp"

namespace MML::structures
{
    template <unsigned SIZE>
    std::optional<common::Hole> Bitmap<SIZE>::getHole()
    {
        if (isIndexSizeValid())
        {
            return std::nullopt;
        }

        while (bits.test(index))
        {
            ++index;
            if (isIndexSizeValid())
            {
                return std::nullopt;
            }
        }

        for (int i{index}; i < SIZE; ++i)
        {
            if (bits.test(i))
            {
                holeSize = i - index - 1;
                return std::make_optional<common::Hole>(index, holeSize);
            }
        }

        holeSize = SIZE - index - 1;
        return std::make_optional<common::Hole>(index, holeSize);
    }

    template <unsigned SIZE>
    bool Bitmap<SIZE>::isIndexSizeValid()
    {
        if (index >= SIZE)
        {
            return false;
        }
        return true;
    }

    template <unsigned SIZE>
    void Bitmap<SIZE>::fillHole(unsigned spaceToFill)
    {
        for (int i{0}; i < spaceToFill; ++index, ++i)
        {
            bits.flip(index);
        }
    }

    template <unsigned SIZE>
    void Bitmap<SIZE>::freeSpace(unsigned adress, unsigned spaceToFree)
    {
        for (int i{adress}; i < adress + spaceToFree; ++i)
        {
            bits.flip(i);
        }
    }
}