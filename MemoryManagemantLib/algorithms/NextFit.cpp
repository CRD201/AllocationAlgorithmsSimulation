#include "NextFit.hpp"

namespace MML::algorithms
{
    NextFit::NextFit(structures::MemoryManagemantStructureI &mmStructure)
        : AllocationAlgotithmI(mmStructure)
    {
    }

    std::optional<unsigned> NextFit::findSpace(const unsigned size)
    {
        const auto hole{mmStructure.getHole()};
        unsigned holeSize{0};
        unsigned holeAdress{0};

        if (!hole.has_value())
        {
            mmStructure.fromStart();
        }
        else
        {
            holeSize = hole->getSize();
            holeAdress = hole->getAdress();
        }

        while (!(holeSize >= size))
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