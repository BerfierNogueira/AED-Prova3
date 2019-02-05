//
// Created by gnber on 03/02/2019.
//

#ifndef AED_TREE_H
#define AED_TREE_H

typedef struct Yggdrasill{
    struct Yggdrasill * left;
    struct Yggdrasill * right;
    char data;
}Tree;

typedef Tree ** Root;

Root raisesTree();

void freeTree(Root root);

void freeNode(Tree * node);

int isEmpty(Root root);

int insertNodeTree(Root root, char value);

Tree * insertNodeTreeRecursive(Root root, char key);

Tree * findTree(Root root, char key);

void printYggdrasil(Root root, int option);

Tree * createsLeaf(char value);

int totalOfNodes(Root root);

Tree * removeTree(Root root, char key);

int altura(Root root);

int estritamenteBinaria(Root root);

Tree * getsFather(Tree * node, char key);

int compara(Tree *a1, Tree *a2);

int similares(Tree * root, Tree * root2);

int calculateInTree(Root root, char key);

#endif //AED_TREE_H
