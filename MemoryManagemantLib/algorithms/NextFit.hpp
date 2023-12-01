#pragma once

#include "AllocationAlgotithmI.hpp"

namespace MML::algorithms
{
    class NextFit : public AllocationAlgotithmI
    {
    public:
        explicit NextFit(structures::MemoryManagemantStructureI &mmStructure);

        std::optional<unsigned> findSpace(const unsigned size) override;
    };
}