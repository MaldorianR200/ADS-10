// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
class Tree {
 private:
    struct Node {
        char c;
        std::vector<Node*> vec;
    };
    Node* root;
    std::vector<std::vector<char>> perms;
    void createPerms(Node* root, std::vector<char>vector) {
        if (!(root->c == ' ')) {
            vector.push_back(root->c);
        }
        if (!root->vec.empty()) {
            for (Node* next : root->vec) {
                createPerms(next, vector);
            }
        } else {
            perms.push_back(vector);
        }
    }

 public:
    explicit Tree(std::vector<char> new_vec) {
        root = new Node;
        root->c = ' ';
        buildTree(root, &new_vec);
        std::vector<char> vector;
        createPerms(root, vector);
    }
    std::vector <char> getPerm(const Tree& tree, int n);
    void buildTree(Node* root, std::vector<char>* vec) {
        for (char c : *vec) {
            Node* temp = new Node;
            temp->c = c;
            root->vec.push_back(temp);
            std::vector<char> remains = *vec;
            remains.erase(std::find(remains.begin(), remains.end(), c));
            buildTree(temp, &remains);
        }
    }
    std::vector<std::vector<char>> getPerms()const {
        return perms;
    }
};
#endif  // INCLUDE_TREE_H_
