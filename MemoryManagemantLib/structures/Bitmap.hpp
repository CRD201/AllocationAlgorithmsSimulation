#pragma once

#include <bitset>
#include "MemoryManagemantStructureI.hpp"

namespace MML::structures
{
    template <unsigned SIZE>
    class Bitmap : public MemoryManagemantStructureI
    {
    public:
        inline void fromStart() override
        {
            index = 0;
            holeSize = 0;
        }
        inline void fromAdress(unsigned adress) override
        {
            index = adress;
            holeSize = 0;
        }

        std::optional<common::Hole> getHole() override
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

            for (unsigned i{index}; i < SIZE; ++i)
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

        bool isIndexSizeValid() 
        {
            if (index >= SIZE)
            {
                return false;
            }
            return true;
        }

        void fillHole(unsigned spaceToFill) override
        {
            for (unsigned i{0}; i < spaceToFill; ++index, ++i)
            {
                bits.flip(index);
            }
        }

        void freeSpace(unsigned adress, unsigned spaceToFree) override
        {
            for (unsigned i{adress}; i < adress + spaceToFree; ++i)
            {
                bits.flip(i);
            }
        }

        std::bitset<SIZE> bits{};
        unsigned index{0};
        unsigned holeSize{0};
    };
}