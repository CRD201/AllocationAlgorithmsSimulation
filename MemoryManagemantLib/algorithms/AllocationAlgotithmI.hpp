#pragma once

#include <optional>
#include "MemoryManagemantLib/structures/MemoryManagemantStructureI.hpp"

namespace MML::algorithms
{
    class AllocationAlgotithmI
    {
    public:
        explicit AllocationAlgotithmI(structures::MemoryManagemantStructureI &mmStructure) : mmStructure{mmStructure} {}

        virtual std::optional<unsigned> findSpace(const unsigned size) = 0;

    protected:
        structures::MemoryManagemantStructureI &mmStructure;
    };
}