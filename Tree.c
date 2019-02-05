//
// Created by gnber on 03/02/2019.
//

#include "Tree.h"
#include <stdlib.h>
#include <ctype.h>
#include "stdio.h"

Root raisesTree(){
    Root root = (Root) malloc(sizeof(Root));
    if(root == NULL){
        printf("Error during memory allocation\n");
        exit(1);
    }
    *root = NULL;
    return root;
}

void freeNode(Tree * node){
    if(node == NULL){
        return;
    }
    freeNode(node->left);
    freeNode(node->right);
    free(node);
    node = NULL;
}

void freeTree(Root root){
    if(root == NULL)
        return;
    freeNode(*root);
    free(root);
}

int isEmpty(Root root){
    if(*root == NULL){
        return 1;
    }
    return 0;
}

Tree * insertNodeTreeRecursive(Root root, char key){
    if(root == NULL){
        printf("\nFUCK");
        return NULL;
    }
    Tree * aux = *root;
    if(aux == NULL){
        printf("\tAdicionando %d", key);
        Tree * newnode = createsLeaf(key);
        *root = newnode;
        printf("\nValue in aux: %d", (*root)->data);
        return *root;
    }
    else if(aux->data > key){
        printf("\nPassou pelo lado esquerdo");
        //aux->left =
        return insertNodeTreeRecursive(&((*root)->left), key);
    }
    else if(aux->data < key){
        printf("\nPassou pelo lado direito");
        //aux->right =
        return insertNodeTreeRecursive(&(*root)->right, key);
    }
}

Tree * createsLeaf(char value){
    Tree * node = (Tree *) malloc(sizeof(Tree));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int insertNodeTree(Root root, char value){

    if(root == NULL){
        printf("\nErro");
        return 0;
    }

    Tree * node;
    node = (Tree *) malloc(sizeof(Tree));
    if(node == NULL){
        printf("\nAlgo deu errado");
        return 0;
    }
    node->data = value;
    node->left = NULL;
    node->right = NULL;

    if(*root == NULL)
        *root = node;
    else{
        Tree * current = *root;
        Tree * old = NULL;
        while(current != NULL){
            old = current;
            if(value == current->data){
                free(node);
                printf("\nEste valor já foi utilizado");
                return 0;//elemento já existe
            }
            if(value > current->data)
                current = current->right;
            else
                current = current->left;
        }
        if(value > old->data){
            old->right = node;
            //printf("\nInserindo o valor (%d) à direita", old->right->data);
        }
        else{
            old->left = node;
            //printf("\nInserindo o valor (%d) à esquerda", old->left->data);
        }
    }
    return 1;
}

void printYggdrasil(Root root, int option){
    if(*root == NULL) return;
    switch(option){
        case 0:
            printf("\n\t\t\t   !!!");
            printf("\n\t\t\tData: %c (raiz)", (*root)->data);
            break;
        case 1:
            printf("\n\t\t\t\t\tData: %c (Nó direito)", (*root)->data);
            break;
        case 2:
            printf("\nData: %c (Nó esquerdo)", (*root)->data);
            break;
    }
    printYggdrasil(&(*root)->right, 1);
    printYggdrasil(&(*root)->left, 2);
}

Tree * findTree(Root root, char key){
    Tree * drawback = *root;

    if(drawback == NULL){
        printf("...not found");
        return NULL;
    }

    if(drawback->data == key) return drawback;
    else if(drawback->data > key){
        return (findTree(&(drawback->left), key));
    }
    else{

        return (findTree(&(drawback->right), key));
    }
}

int calculateInTree(Root root, char key){
    key = tolower(key);
    Tree * tree = findTree(root, key);
    if(tree == NULL){
        printf("\nErro");
        return 0;
    }
    else
    {
        tree->data = tolower(tree->data);
        int num = (int) tree->data;
        num = num - 96;
        printf("\nChar: %c, valor inteiro: %d", tree->data, num);
        return num%9;
    }
}

int totalOfNodes(Root root){
    Tree * auxiliar = *root;
    if(auxiliar == NULL){
        return 0;
    }
    return(totalOfNodes(&(auxiliar->left))
           +1
           +totalOfNodes(&(auxiliar->right)));
}


Tree * removeTree(Root root, char key){
    Tree * standard = *root,
            *father,
            *partner,
            *substitute;
    if(standard == NULL) return NULL;

    // Procurar o nó e identificar o pai dele
    while(standard->data != key){
        father = standard;
        if(standard->data > key)
            standard = standard->left;
        else standard = standard->right;

        if(standard == NULL){
            return NULL;
        }
    }

    //termina a seção

    printf("\nThe key found %d", standard->data);
    printf("\nThe father: %d", father->data);

    if(standard->left == NULL || standard->right == NULL){
        printf("\nV");
        if(standard->left == standard->right) return standard;
        substitute = (!standard->left)?standard->right:standard->left;
    }
    else{
        printf("\nW");
        partner = standard;
        substitute = standard->left;
        while(substitute->right != NULL){
            partner = substitute;
            substitute = substitute->right;
        }

        if(partner != standard){
            partner->right = substitute->left;
            substitute->left = standard->right;
        }
        substitute->right = standard->right;
    }
    if(!father){
        free(standard);
        return substitute;
    }
    if(key < father->data){
        father->left = substitute;
    }
    else father->right = substitute;
    printf("\nSubstitute = %d", substitute->data);
    printf("\nSubstituted = %d", standard->data);
    free(standard);
    return substitute;
}

int altura_Arv(Root root){
    if (root == NULL)
        return 0;
    if (*root == NULL)
        return 0;
    int alt_esq = altura_Arv (&((*root)->left));
    int alt_dir = altura_Arv (&((*root)->right));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return (alt_dir + 1);
}

int estritamenteBinaria(Root root)
{
    Tree * arv = *root;
    if(arv != NULL)
    {
        if( (arv->left == NULL && arv->right != NULL) || (arv->left != NULL && arv->right == NULL) )
            return 0;
        else
        {
            int v_esq = estritamenteBinaria(&(arv->left));
            int v_dir = estritamenteBinaria(&(arv->right));
            if(v_esq && v_dir)
                return 1;
            else
                return 0;
        }
    }
    else
        return 1;
}

Tree * getsFather(Tree * node, char key){
    Tree * standard = node;
    Tree * father = NULL;
    while(standard->data != key){
        father = standard;
        if(standard->data > key)
            standard = standard->left;
        else standard = standard->right;

        if(standard == NULL){
            return NULL;
        }
    }
    return father;
}

int compara(Tree *a1, Tree *a2)
{
    if (a1 == NULL && a2 == NULL)
        return 1;
    else{
        printf("\n%d = %d", a1->data,a2->data);
        return (a1->data == a2->data) && (compara(a1->left, a2->left)) && compara(a1->right, a2->right);
    }
}

int similares(Tree * root, Tree * root2){
    Tree *a = root;
    Tree *b = root2;
    if((a != NULL || b != NULL) && (a == NULL || b == NULL))
        return 0;
    else if(!a || !b)
        return 1;
    else
        similares(a->left, b->left) && similares(a->right, b->right);
}
