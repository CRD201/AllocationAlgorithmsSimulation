#include <iostream>
#include "NextFit.hpp"

namespace MML::algorithms
{
    NextFit::NextFit(structures::MemoryManagemantStructureI &mmStructure)
        : AllocationAlgotithmI(mmStructure)
    {
    }

    std::optional<unsigned> NextFit::findSpace(const unsigned size)
    {
        std::cout << "[MML-INF] NextFit: lookoing for hole with size: " << size << std::endl;
        const auto hole{mmStructure.getHole()};
        unsigned holeSize{0};
        unsigned holeAdress{0};

        if (!hole.has_value())
        {
            std::cout << "[MML-INF] NextFit: reached end, restarting " << size << std::endl;
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
                std::cout << "[MML-ERR] NextFit: no hole" << std::endl;
                return std::nullopt;
            }
            holeSize = hole->getSize();
            holeAdress = hole->getAdress();
        }

        std::cout << "[MML-INF] NextFit: hole found: size: " << holeSize << " adress: " << holeAdress << std::endl;
        mmStructure.fillHole(size);
        return std::make_optional<unsigned>(holeAdress);
    }
}