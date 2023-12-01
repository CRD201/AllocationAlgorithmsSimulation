#pragma once

#include <optional>
#include "common/Hole.hpp"

namespace MML::structures
{
    class MemoryManagemantStructureI
    {
    public:
        virtual void fromStart() = 0;
        virtual void fromAdress(unsigned adress) = 0;

        virtual std::optional<common::Hole> getHole() = 0;
        virtual void fillHole(unsigned spaceToFill) = 0;
        virtual void freeSpace(unsigned adress, unsigned spaceToFree) = 0;
    };
}