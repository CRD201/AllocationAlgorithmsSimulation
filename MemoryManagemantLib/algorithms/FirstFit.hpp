#pragma once

#include "AllocationAlgotithmI.hpp"

namespace MML::algorithms
{
    class FirstFit : public AllocationAlgotithmI
    {
    public:
        explicit FirstFit(structures::MemoryManagemantStructureI &mmStructure);

        std::optional<unsigned> findSpace(const unsigned size) override;
    };
}