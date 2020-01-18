#include <iostream>
using namespace std;
struct pnode {
  int data;
  struct pnode * next;
};
typedef struct pnode * LPTR;
LPTR head = NULL;
struct pnode * create(int x) {
  LPTR p;
  p = new(struct pnode);
  p -> next = NULL;
  p -> data = x;
  return p;
}
void add(LPTR & l, int x) {
  if (l == NULL) {
    l = create(x);
  } else {
    LPTR temp = l;
    while (temp -> next != NULL) {
      temp = temp -> next;
    }
    temp -> next = create(x);
  }
}
void swap(LPTR & x, LPTR & y) {
  int t = x -> data;
  x -> data = y -> data;
  y -> data = t;
  return;
}
void func(LPTR & l) {
  for (LPTR i = l; i -> next != NULL; i = i -> next) {
    for (LPTR j = i; j -> next -> next != NULL; j = j -> next) {
      if (j -> data % 2 == 0 && j -> next -> data % 2 != 0) {
        swap(j, j -> next);
      }
    }
  }
}

void printlst(LPTR l) {
  LPTR t = l;
  if (t == NULL) return;
  else {
    cout << t -> data << " ";
    printlst(t -> next);
  }
}
int main() {
  LPTR l = NULL;
  add(l, 2);
  add(l, 3);
  add(l, 5);
  add(l, 7);
  add(l, 32);
  func(l);
  printlst(l);
  cout << endl;
  return 0;
}
