#pragma once

#include "MemoryManagemantStructureI.hpp"

namespace MML::structures
{
    template <unsigned SIZE>
    class Bitmap : public MemoryManagemantStructureI
    {
    public:
        Bitmap()
        {
            for (unsigned i{0}; i < SIZE; ++i)
            {
                bits[i] = false;
            }
        }
        
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
            index += holeSize;
            if (isIndexSizeValid())
            {
                return std::nullopt;
            }

            while (bits[index])
            {
                ++index;
                if (isIndexSizeValid())
                {
                    return std::nullopt;
                }
            }

            for (unsigned i{index}; i < SIZE; ++i)
            {
                if (bits[i])
                {
                    holeSize = i - index;
                    return std::make_optional<common::Hole>(index, holeSize);
                }
            }

            holeSize = SIZE - index;
            return std::make_optional<common::Hole>(index, holeSize);
        }

        void fillHole(unsigned spaceToFill) override
        {
            for (unsigned i{0}; i < spaceToFill; ++index, ++i)
            {
                bits[index] = true;
            }
            holeSize = 0;
        }

        void freeSpace(unsigned adress, unsigned spaceToFree) override
        {
            for (unsigned i{adress}; i < adress + spaceToFree; ++i)
            {
                bits[i] = false;
            }
        }

    private:
        bool isIndexSizeValid()
        {
            if (index >= SIZE)
            {
                return true;
            }
            return false;
        }

        bool bits[SIZE];
        unsigned index{0};
        unsigned holeSize{0};
    };
}