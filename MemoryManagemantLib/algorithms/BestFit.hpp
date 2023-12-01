#pragma once

#include "AllocationAlgotithmI.hpp"

namespace MML::algorithms
{
    class BestFit : public AllocationAlgotithmI
    {
    public:
        explicit BestFit(structures::MemoryManagemantStructureI &mmStructure);

        std::optional<unsigned> findSpace(const unsigned size) override;
    };
}