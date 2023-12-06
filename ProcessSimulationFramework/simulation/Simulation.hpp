#pragma once

#include "MemoryManagemantLib/algorithms/FirstFit.hpp"
#include "MemoryManagemantLib/algorithms/NextFit.hpp"
#include "MemoryManagemantLib/algorithms/BestFit.hpp"
#include "MemoryManagemantLib/algorithms/WorstFit.hpp"
#include "MemoryManagemantLib/structures/Bitmap.hpp"
#include "MemoryManagemantLib/structures/LinkedList.hpp"

#include "MainComponent.hpp"

namespace PSF::simulation
{
    template <unsigned MEMORY_SIZE, unsigned NUMBER_OF_ITERATIONS>
    class Simulation
    {
        enum class Algorithms
        {
            FirstFit,
            NextFit,
            BestFit,
            WorstFit
        };

        enum class MMStructures
        {
            Bitmap,
            LinkedList
        };

    public:
        void run()
        {
            chooseAlgorithm();
        }

        Simulation &setFirstFit()
        {
            algoritm = Algorithms::FirstFit;
            return *this;
        }

        Simulation &setNextFit()
        {
            algoritm = Algorithms::NextFit;
            return *this;
        }

        Simulation &setBestFit()
        {
            algoritm = Algorithms::BestFit;
            return *this;
        }

        Simulation &setWorstFit()
        {
            algoritm = Algorithms::WorstFit;
            return *this;
        }

        Simulation &setBitmap()
        {
            mmStructure = MMStructures::Bitmap;
            return *this;
        }

        Simulation &setLinkedList()
        {
            mmStructure = MMStructures::LinkedList;
            return *this;
        }

    private:
        void chooseAlgorithm()
        {
            switch (algoritm)
            {
            case Algorithms::FirstFit:
                chooseStructure<MML::algorithms::FirstFit>();
                break;
            case Algorithms::NextFit:
                chooseStructure<MML::algorithms::NextFit>();
                break;
            case Algorithms::BestFit:
                chooseStructure<MML::algorithms::BestFit>();
                break;
            case Algorithms::WorstFit:
                chooseStructure<MML::algorithms::WorstFit>();
                break;
            }
        }

        template <typename Algorithm>
        void chooseStructure()
        {
            switch (mmStructure)
            {
            case MMStructures::Bitmap:
                runMainComponent<Algorithm, MML::structures::Bitmap<MEMORY_SIZE>>();
                break;
            case MMStructures::LinkedList:
                runMainComponent<Algorithm, MML::structures::LinkedList<MEMORY_SIZE>>();
                break;
            }
        }

        template <typename Algorithm, typename Structure>
        void runMainComponent()
        {
            MainComponent<Algorithm, Structure, MEMORY_SIZE, NUMBER_OF_ITERATIONS>().run();
        }

        Algorithms algoritm{Algorithms::FirstFit};
        MMStructures mmStructure{MMStructures::LinkedList};
    };
}