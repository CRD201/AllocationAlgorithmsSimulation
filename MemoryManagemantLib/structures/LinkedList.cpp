#include "LinkedList.hpp"

namespace MML::structures
{
    template <unsigned SIZE>
    LinkedList<SIZE>::LinkedList()
        : head{std::make_shared<Node>(true, 0, SIZE, nullptr)}, currentNode{head}
    {
    }

    template <unsigned SIZE>
    std::optional<common::Hole> LinkedList<SIZE>::getHole()
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

    template <unsigned SIZE>
    bool LinkedList<SIZE>::lastNodeReached()
    {
        if (currentNode->next == nullptr)
        {
            return true;
        }
        return false;
    }

    template <unsigned SIZE>
    std::shared_ptr<typename LinkedList<SIZE>::Node> LinkedList<SIZE>::findNodeByAdress(unsigned adress)
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

    template <unsigned SIZE>
    void LinkedList<SIZE>::fillHole(unsigned spaceToFill)
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

    template <unsigned SIZE>
    void LinkedList<SIZE>::freeSpace(unsigned adress, unsigned spaceToFree)
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
}