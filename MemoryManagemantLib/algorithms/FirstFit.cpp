#include <iostream>
#include "FirstFit.hpp"

namespace MML::algorithms
{
    FirstFit::FirstFit(structures::MemoryManagemantStructureI &mmStructure)
        : AllocationAlgotithmI(mmStructure)
    {
    }

    std::optional<unsigned> FirstFit::findSpace(const unsigned size)
    {
        std::cout << "[MML-INF] FirstFit: lookoing for hole with size: " << size << std::endl;
        mmStructure.fromStart();
        unsigned holeSize{0};
        unsigned holeAdress{0};
        
        while (! (holeSize >= size))
        {
            const auto hole{mmStructure.getHole()};
            if (!hole.has_value())
            {
                std::cout << "[MML-ERR] FirstFit: no hole" << std::endl;
                return std::nullopt;
            }
            holeSize = hole->getSize();
            holeAdress = hole->getAdress();
        }

        std::cout << "[MML-INF] FirstFit: hole found: size: " << holeSize << " adress: " << holeAdress << std::endl;
        mmStructure.fillHole(size);
        return std::make_optional<unsigned>(holeAdress);
    }
}