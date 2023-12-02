#include "BestFit.hpp"

namespace MML::algorithms
{
    BestFit::BestFit(structures::MemoryManagemantStructureI &mmStructure)
        : AllocationAlgotithmI(mmStructure)
    {
    }

    std::optional<unsigned> BestFit::findSpace(const unsigned size)
    {
        mmStructure.fromStart();
        unsigned holeSize{0};
        unsigned holeAdress{0};
        bool isAdressFound{false};

        while (true)
        {
            const auto hole{mmStructure.getHole()};
            if (!hole.has_value())
            {
                break;
            }

            if (hole->getSize() >= size && ((!isAdressFound) || (hole->getSize() < holeSize)))
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