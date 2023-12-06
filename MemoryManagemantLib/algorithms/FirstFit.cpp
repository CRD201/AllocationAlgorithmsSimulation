#include "FirstFit.hpp"

namespace MML::algorithms
{
    FirstFit::FirstFit(structures::MemoryManagemantStructureI &mmStructure)
        : AllocationAlgotithmI(mmStructure)
    {
    }

    std::optional<unsigned> FirstFit::findSpace(const unsigned size)
    {
        mmStructure.fromStart();
        unsigned holeSize{0};
        unsigned holeAdress{0};
        
        while (! (holeSize >= size))
        {
            const auto hole{mmStructure.getHole()};
            if (!hole.has_value())
            {
                return std::nullopt;
            }
            holeSize = hole->getSize();
            holeAdress = hole->getAdress();
        }

        mmStructure.fillHole(size);
        return std::make_optional<unsigned>(holeAdress);
    }
}