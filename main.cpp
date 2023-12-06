#define MEM_SIZE 100000
#define ITER_NUM 2000

#include "MemoryManagemantLib/algorithms/WorstFit.hpp"
#include "MemoryManagemantLib/structures/LinkedList.hpp"
#include "ProcessSimulationFramework/simulation/MainComponent.hpp"

int main()
{
    PSF::simulation::MainComponent<
        MML::algorithms::WorstFit, 
        MML::structures::LinkedList<MEM_SIZE>, 
        MEM_SIZE, ITER_NUM>()
        .run();
    return 0;
}