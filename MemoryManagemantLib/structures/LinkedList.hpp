#pragma once

#include <memory>
#include "MemoryManagemantStructureI.hpp"

namespace MML::structures
{
    template <unsigned SIZE>
    class LinkedList : public MemoryManagemantStructureI
    {
        struct Node
        {
            Node(bool isHole, unsigned adress, unsigned size) : isHole{isHole}, adress{adress}, size{size} {}

            bool isHole;
            unsigned adress;
            unsigned size;
            std::shared_ptr<Node> next;
        };

    public:
        LinkedList();

        inline void fromStart() override
        {
            currectNode = head;
            isHoleFound = false;
        }
        inline void fromAdress(unsigned adress) override
        {
            fromStart();
            currentNode = findNodeByAdress(adress);
        }

        std::optional<common::Hole> getHole() override;
        void fillHole(unsigned spaceToFill) override;
        void freeSpace(unsigned adress, unsigned spaceToFree) override;

    private:
        bool lastNodeReached();
        std::shared_ptr<Node> findNodeByAdress(unsigned adress);
        
        std::shared_ptr<Node> head;
        std::shared_ptr<Node> currectNode;
        bool isHoleFound{false};
    };
}