#pragma once

#include <bitset>
#include <iostream>
#include "MemoryManagemantStructureI.hpp"

namespace MML::structures
{
    template <unsigned SIZE>
    class Bitmap : public MemoryManagemantStructureI
    {
    public:
        inline void fromStart() override
        {
            // std::cout << "[MML-INF] Bitmap: fromStart " << std::endl;
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
                std::cout << "[MML-ERR] Bitmap: invalid index at start: " << index << std::endl;
                return std::nullopt;
            }

            while (bits.test(index))
            {
                ++index;
                if (isIndexSizeValid())
                {
                    std::cout << "[MML-ERR] Bitmap: invalid index: " << index << std::endl;
                    return std::nullopt;
                }
            }

            for (unsigned i{index}; i < SIZE; ++i)
            {
                if (bits.test(i))
                {
                    holeSize = i - index;
                    std::cout << "[MML-INF] Bitmap: hole found holeSize: " << holeSize << " adress: " << index << std::endl;
                    return std::make_optional<common::Hole>(index, holeSize);
                }
            }

            holeSize = SIZE - index;
            std::cout << "[MML-INF] Bitmap: hole found holeSize: " << holeSize << " adress: " << index << std::endl;
            return std::make_optional<common::Hole>(index, holeSize);
        }

        bool isIndexSizeValid()
        {
            if (index >= SIZE)
            {
                return true;
            }
            return false;
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
            std::cout << "[MML-INF] Bitmap: free space spaceToFree: " << spaceToFree << " adress: " << index << std::endl;
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