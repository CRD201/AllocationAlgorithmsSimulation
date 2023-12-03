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
            Node(bool isHole, unsigned adress, unsigned size, std::shared_ptr<Node> next)
                : isHole{isHole},
                  adress{adress},
                  size{size},
                  next{next}
            {
            }

            bool isHole;
            unsigned adress;
            unsigned size;
            std::shared_ptr<Node> next;
        };

    public:
        LinkedList()
            : head{std::make_shared<Node>(true, 0, SIZE, nullptr)}, currentNode{head}
        {
        }

        inline void fromStart() override
        {
            currentNode = head;
            isHoleFound = false;
        }
        inline void fromAdress(unsigned adress) override
        {
            fromStart();
            currentNode = findNodeByAdress(adress);
        }

        std::optional<common::Hole> getHole() override
        {
            if (lastNodeReached() && isHoleFound)
            {
                return std::nullopt;
            }

            if (isHoleFound)
            {
                currentNode = currentNode->next;
            }

            while (!currentNode->isHole)
            {
                if (lastNodeReached())
                {
                    return std::nullopt;
                }
                currentNode = currentNode->next;
            }

            return std::make_optional<common::Hole>(currentNode->adress, currentNode->size);
        }
        void fillHole(unsigned spaceToFill) override
        {
            currentNode->isHole = false;

            if (currentNode->size > spaceToFill)
            {
                std::shared_ptr<Node> newHole{std::make_shared<Node>(true,
                                                                     currentNode->adress + spaceToFill,
                                                                     currentNode->size - spaceToFill,
                                                                     currentNode->next)};
                currentNode->size = spaceToFill;
                currentNode->next = newHole;
            }
        }
        void freeSpace(unsigned adress, unsigned spaceToFree) override
        {
            std::shared_ptr<Node> newHole = findNodeByAdress(adress);

            std::shared_ptr<Node> tmpNode{head};
            while (tmpNode->next != nullptr)
            {
                if (tmpNode->isHole || tmpNode->next->isHole)
                {
                    tmpNode->size += tmpNode->next->size;
                    tmpNode->next = tmpNode->next->next;
                }
                else
                {
                    tmpNode = tmpNode->next;
                }
            }
        }

    private:
        bool lastNodeReached()
        {
            if (currentNode->next == nullptr)
            {
                return true;
            }
            return false;
        }

        std::shared_ptr<Node> findNodeByAdress(unsigned adress)
        {
            std::shared_ptr<Node> tmpNode{head};
            while (tmpNode->adress < adress)
            {
                if (tmpNode->next == nullptr)
                {
                    return nullptr;
                }
                tmpNode = tmpNode->next;
            }
            return tmpNode;
        }

        std::shared_ptr<Node> head;
        std::shared_ptr<Node> currentNode;
        bool isHoleFound{false};
    };
}