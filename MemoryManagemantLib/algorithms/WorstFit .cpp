#include "WorstFit.hpp"

namespace MML::algorithms
{
    WorstFit::WorstFit(structures::MemoryManagemantStructureI &mmStructure)
        : AllocationAlgotithmI(mmStructure)
    {
    }

    std::optional<unsigned> WorstFit::findSpace(const unsigned size)
    {
        mmStructure.fromStart();
        unsigned holeSize{size};
        unsigned holeAdress{0};
        bool isAdressFound{false};

        while (true)
        {
            const auto hole{mmStructure.getHole()};
            if (!hole.has_value())
            {
                break;
            }

            if ((!isAdressFound) || (hole->getSize() > holeSize))
            {
                isAdressFound = true;
                holeSize = hole->getSize();
                holeAdress = hole->getAdress();
            }
        }

        if (isAdressFound)
        {
            mmStructure.fromAdress(holeAdress);
            mmStructure.fillHole(size);
            return std::make_optional<unsigned>(holeAdress);
        }
        
        return std::nullopt;
    }
}