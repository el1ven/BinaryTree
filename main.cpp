//
//  main.cpp
//  pro1
//
//  Created by el1ven on 14-6-6.
//  Copyright (c) 2014年 el1ven. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct BiTNode{
    char data;
    struct BiTNode *leftChild;
    struct BiTNode *rightChild;
};

BiTNode *T;//创建指向结构体的指针

void createBiTree(BiTNode* &T);//创建二叉树
void inOrder(BiTNode* &T);//中序遍历二叉树
void preOrder(BiTNode* &T);//前序遍历二叉树
void postOrder(BiTNode* &T);//后序遍历二叉树

int main(){
    cout<<"创建一颗树，其中A->Z字符代表树的数据，用“#”表示空树:"<<endl;
    createBiTree(T);
    //ABD##E##CH###
    
    cout<<"先序递归遍历："<<endl;
    preOrder(T);
    cout<<endl;
    
    cout<<"中序递归遍历："<<endl;
    inOrder(T);
    cout<<endl;
    
    cout<<"后序递归遍历:"<<endl;
    postOrder(T);
    cout<<endl;
    
    return 0;
}

void createBiTree(BiTNode* &T){
    char ch;
    cin>>ch;
    if(ch == '#'){
        T = NULL;
    }else{
        //先序创建二叉树
        T = new BiTNode;//创建新的结构体对象
        T->data = ch;
        createBiTree(T->leftChild);
        createBiTree(T->rightChild);
    }
}

void preOrder(BiTNode* &T){
    if(T){
        cout<<T->data;//当结点不为空的时候执行
        preOrder(T->leftChild);
        preOrder(T->rightChild);
    }else{
        cout<<"";
    }
}

void inOrder(BiTNode* &T){
    if(T){
        inOrder(T->leftChild);
        cout<<T->data;
        inOrder(T->rightChild);
    }else{
        cout<<"";
    }
}

void postOrder(BiTNode* &T){
    if(T){
        postOrder(T->leftChild);
        postOrder(T->rightChild);
        cout<<T->data;//当结点不为空的时候执行
    }else{
        cout<<"";
    }
}




