#include <iostream>
#include <stdlib.h>   
#include <time.h>
#include <random>
#include <vector>
#include<string>
#include "../include/stack.hpp"
#include "../include/queue.hpp"
#include "../include/doublylinkedlist.hpp"
#include "../include/binarytree.hpp"
#include "../include/auxiliarytools.hpp"
#include "../include/graph.hpp"
using namespace std;

int main()
{
  bool question_options[] = {true, true, true, true, true};
  if (question_options[0] == true)
  {
    cout << "Testing to the question 01." << endl << endl;
    srand(time(NULL));
    Stack s(10);
    int result = 1;
    while(result)
    {
      if ((rand() % 100) < 50)
      {
          result = s.push(rand() % 100 + 1);
      }
      else
      {
          result = s.pop();
      }
    }
  }

  if (question_options[1] == true)
  {
    cout << endl << "Testing to the question 02." << endl << endl;
    srand(time(NULL));
    Queue q;
    do
    {
      if ((rand() % 100) < 50)
      {
          q.enQueue(rand() % 100 + 1);
      }
      else
      {
          q.deQueue();
      }
    }
    while(q.getStatus() == true);
  }
  if (question_options[2] == true)
  {
    cout << endl << "Testing to the question 03." << endl << endl;
    default_random_engine generator;
    normal_distribution<float> distribution(500.0,100.0);
    List l;
    int nbElements = 100;
    int number;
    for (int i = 0; i < nbElements; i ++)
    {
      number = distribution(generator);
      l.insertNode(number);
    }
    cout << "Original list" << endl << endl;
    l.displayList();
    l.removeDuplicates();
    cout << endl << "Modified list" << endl << endl;
    l.displayList();

  }

  if (question_options[3] == true)
  {
    cout << endl << "Testing to the question 04." << endl << endl;
    BinaryTree trojan_horse;

    cout << endl << "Select a file: (1) SmallSet or (2) LargeSet." << endl << endl;
    int user_input;
    receiveUserInput(user_input);
    cout << endl;
    string file_path = "../data/binarytree";
    string user_selection = user_input == 1 ? "/smallSet" : "/largeSet";
    file_path += user_selection;

    vector<vector<int>> added_datas = loadDatasFromFile(file_path+"/data.txt");
    vector<vector<int>> searched_datas = loadDatasFromFile(file_path+"/search.txt");
    vector<vector<int>> removed_datas = loadDatasFromFile(file_path+"/delete.txt");
    int added_datas_length = added_datas.size();
    int searched_datas_length = searched_datas.size();
    int removed_datas_length = removed_datas.size();

    for (int i = 0; i < added_datas_length; i++){trojan_horse.insertNode(added_datas[i][0]);}
    cout << "Before to remove some items:" << endl;
    trojan_horse.displayBinaryTreeInOrder(trojan_horse.getRoot());
    cout << endl;

    for (int i = 0; i < searched_datas_length; i++)
    {
        string result = (trojan_horse.searchKey(trojan_horse.getRoot(), searched_datas[i][0]) == nullptr) ? "Item not found." : "Item found.";
        cout << endl << "The Key " << searched_datas[i][0] << ": " << result << endl;
    }

    for (int i = 0; i < removed_datas_length; i++){trojan_horse.deleteNode(removed_datas[i][0]);}
    cout << endl << "After to remove some items:" << endl;
    trojan_horse.displayBinaryTreeInOrder(trojan_horse.getRoot());

    cout << endl;
  }

  if (question_options[4] == true)
  {
    cout << endl << "Testing to the question 05." << endl << endl;
    Graph g("../data/graph/graph.txt");
    cout << g;
    g.printPath(0,2);
  }

  return 0;
}