#pragma once

#include "AllocationAlgotithmI.hpp"

namespace MML::algorithms
{
    class WorstFit : public AllocationAlgotithmI
    {
    public:
        explicit WorstFit(structures::MemoryManagemantStructureI &mmStructure);

        std::optional<unsigned> findSpace(const unsigned size) override;
    };
}