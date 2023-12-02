#define MEM_SIZE 16
#define ITER_NUM 3

#include "MemoryManagemantLib/algorithms/BestFit.hpp"
#include "MemoryManagemantLib/structures/Bitmap.hpp"
#include "ProcessSimulationFramework/simulation/MainComponent.hpp"

int main()
{
    PSF::simulation::MainComponent<
        MML::algorithms::BestFit,
        MML::structures::Bitmap<MEM_SIZE>,
        MEM_SIZE,
        ITER_NUM>()
        .run();
    return 0;
}