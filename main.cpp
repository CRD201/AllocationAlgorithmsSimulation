#define MEM_SIZE 100000
#define ITER_NUM 20

#include "MemoryManagemantLib/algorithms/NextFit.hpp"
#include "MemoryManagemantLib/structures/LinkedList.hpp"
#include "ProcessSimulationFramework/simulation/MainComponent.hpp"

int main()
{
    PSF::simulation::MainComponent<
        MML::algorithms::NextFit, 
        MML::structures::LinkedList<MEM_SIZE>, 
        MEM_SIZE, ITER_NUM>()
        .run();
    return 0;
}