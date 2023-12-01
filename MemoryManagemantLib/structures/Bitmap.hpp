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

        std::optional<common::Hole> getHole() override;
        void fillHole(unsigned spaceToFill) override;
        void freeSpace(unsigned adress, unsigned spaceToFree) override;

    private:
        bool isIndexSizeValid();

        std::bitset<SIZE> bits{};
        unsigned index{0};
        unsigned holeSize{0};
    };
}