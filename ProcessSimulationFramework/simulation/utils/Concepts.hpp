#pragma once

#include <concepts>
#include "MemoryManagemantLib/algorithms/AllocationAlgotithmI.hpp"
#include "MemoryManagemantLib/structures/MemoryManagemantStructureI.hpp"

namespace PSF::simulation::utils
{
    template <class T>
    concept MemoryManagemantStructure = std::derived_from<T, MML::structures::MemoryManagemantStructureI>;

    template <class T>
    concept AllocationAlgotithm = std::derived_from<T, MML::algorithms::AllocationAlgotithmI>;
}
