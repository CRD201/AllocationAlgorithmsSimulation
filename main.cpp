#define MEM_SIZE 10000
#define ITER_NUM 1000

#include "MemoryManagemantLib/algorithms/NextFit.hpp"
#include "MemoryManagemantLib/structures/Bitmap.hpp"
#include "ProcessSimulationFramework/simulation/MainComponent.hpp"

int main()
{
    PSF::simulation::MainComponent<
        MML::algorithms::NextFit, 
        MML::structures::Bitmap<MEM_SIZE>, 
        MEM_SIZE, ITER_NUM>()
        .run();
    return 0;
}